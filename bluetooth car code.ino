char cmd; // The Bluetooth Command

// The L298N Motor Driver Control Pins
const int rightMotorForward = 13;
const int rightMotorBackward = 12;
const int leftMotorForward = 11;
const int leftMotorBackward = 10;

void setup() {
    pinMode(leftMotorForward, OUTPUT);
    pinMode(leftMotorBackward, OUTPUT);
    pinMode(rightMotorForward, OUTPUT);
    pinMode(rightMotorBackward, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        cmd = Serial.read();
    }

    // Stop motors before processing a new command
    stopMotors();

    switch (cmd) {
        case 'F': // Move Forward
            digitalWrite(leftMotorForward, HIGH);
            digitalWrite(rightMotorForward, HIGH);
            break;

        case 'B': // Move Backward
            digitalWrite(leftMotorBackward, HIGH);
            digitalWrite(rightMotorBackward, HIGH);
            break;

        case 'L': // Turn Left
            digitalWrite(rightMotorForward, HIGH); // Move only the right motor forward
            break;

        case 'R': // Turn Right
            digitalWrite(leftMotorForward, HIGH); // Move only the left motor forward
            break;
    }

    delay(50); // Short delay for stability
}

// Function to stop all motors
void stopMotors() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, LOW);
}

