const BAUD_RATE = 9600;

// Replace this URL with your own Teachable Machine image model URL
const MODEL_URL =
  "https://teachablemachine.withgoogle.com/models/YOUR_MODEL_ID/";

let port, connectBtn;
let classifier;
let video;
let label = "waiting...";
let confidence = 0;
let lastSent = -1;

function setup() {
  setupSerial();
  createCanvas(640, 480);
  textFont("system-ui", 24);
  textAlign(CENTER, CENTER);

  // Create a video capture element (not drawn by p5, ml5 uses it directly)
  video = createCapture(VIDEO);
  video.size(640, 480);
  video.hide();

  // Load the Teachable Machine model
  classifier = ml5.imageClassifier(MODEL_URL + "model.json", video, modelReady);
}

function modelReady() {
  console.log("Model loaded!");
  classifier.classify(gotResult);
}

function gotResult(error, results) {
  if (error) {
    console.error(error);
    return;
  }
  label = results[0].label;
  confidence = results[0].confidence;

  // Map label to a number to send over serial
  let toSend = 0;
  if (label === "Class 1") toSend = 1;
  else if (label === "Class 2") toSend = 2;

  // Only send if the value changed
  if (toSend !== lastSent && port && port.opened()) {
    port.write(toSend + "\n");
    lastSent = toSend;
  }

  // Keep classifying
  classifier.classify(gotResult);
}

function draw() {
  // Draw the camera feed
  image(video, 0, 0, width, height);

  // Dim overlay
  fill(0, 0, 0, 120);
  noStroke();
  rect(0, 0, width, 80);

  // Show label and confidence
  fill(255);
  textSize(28);
  text(label + " (" + nf(confidence * 100, 1, 1) + "%)", width / 2, 40);

  const portIsOpen = checkPort();
  if (!portIsOpen) {
    fill(255, 80, 80);
    textSize(20);
    text("Not connected to Arduino", width / 2, height - 30);
  }
}

// --- Serial helpers (same pattern as brightness example) ---

function setupSerial() {
  port = createSerial();

  let usedPorts = usedSerialPorts();
  if (usedPorts.length > 0) {
    port.open(usedPorts[0], BAUD_RATE);
  }

  connectBtn = createButton("Connect to Arduino");
  connectBtn.position(5, 5);
  connectBtn.mouseClicked(onConnectButtonClicked);
}

function checkPort() {
  if (!port.opened()) {
    connectBtn.html("Connect to Arduino");
    return false;
  } else {
    connectBtn.html("Disconnect");
    return true;
  }
}

function onConnectButtonClicked() {
  if (!port.opened()) {
    port.open(BAUD_RATE);
  } else {
    port.close();
  }
}
