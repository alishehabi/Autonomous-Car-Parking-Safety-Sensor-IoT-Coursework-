// Pin connections
const int trigPin = 5;
const int echoPin = 6;
const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int buzzer = A0;
const int irSensorPin = 7;
const int pirSensorPin = 8;

// Distance thresholds in cm
const float redThreshold = 20.0; 
const float yellowThreshold = 50.0; 
const float greenThreshold = 100.0;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(irSensorPin, INPUT);
    pinMode(pirSensorPin, INPUT);
}

void loop() {
    long duration = triggerUltrasonicSensor(); // Trigger ultrasonic sensor
    float distance = calculateDistance(duration); // Calculate distance from duration in centimeters
    bool isIRObstacleDetected = digitalRead(irSensorPin) == LOW; // Read IR sensor state (detects obstacle if LOW)
    bool isPIRMotionDetected = digitalRead(pirSensorPin) == HIGH; // Read PIR sensor state (detects motion if HIGH)

    if (isPIRMotionDetected || isIRObstacleDetected) {
        Serial.println("Motion Detected"); // Output motion detection message to serial monitor
        handleLEDIndicators(distance); // Handle LED indicators based on distance
        handleBuzzer(distance, isPIRMotionDetected); // Handle buzzer based on distance and motion detection
    } else {
        turnOffAllLEDs(); // Turn off all LEDs
        noTone(buzzer); // Turn off buzzer if no motion
    }

    // Output the calculated distance to serial monitor
    Serial.print("Distance: ");
    Serial.print(distance, 1); // Print with 1 decimal precision
    Serial.println(" cm");
    delay(500);
}

// trigger the ultrasonic sensor and measure the echo pulse
long triggerUltrasonicSensor() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 
    return pulseIn(echoPin, HIGH); // Measure the duration of the returned echo pulse
}

// Function to calculate the distance from the echo pulse duration
float calculateDistance(long duration) {
    return (duration / 2.0) / 29.1; // Speed of sound = 343 m/s => 29.1 cm/us
}

// Function to control LED indicators based on distance
void handleLEDIndicators(float distance) {
    if (distance > greenThreshold) {
        turnOffAllLEDs(); // Turn off all LEDs if distance is greater than green threshold
    } else if (distance > yellowThreshold) {
        setLEDState(LOW, LOW, HIGH); // Activate green LED if distance is within green threshold
    } else if (distance > redThreshold) {
        setLEDState(LOW, HIGH, LOW); // Activate yellow LED if distance is within yellow threshold
    } else {
        setLEDState(HIGH, LOW, LOW); // Activate red LED if distance is below red threshold
    }
}

// Function to set the state of each LED
void setLEDState(int redState, int yellowState, int greenState) {
    digitalWrite(redLED, redState); 
    digitalWrite(yellowLED, yellowState);
    digitalWrite(greenLED, greenState); 
}

// Purpose: Controls the buzzer based on the distance measured - The buzzer beeps at different rates depending on how close the object is
void handleBuzzer(float distance, bool isPIRMotionDetected) {
    // Check if motion is detected by the PIR sensor
    if (isPIRMotionDetected) {
        // Check if distance is less than yellow threshold and greater or equal to red threshold
        if (distance < yellowThreshold && distance >= redThreshold) {
            // Map the distance to a corresponding beep rate
            int beepRate = map(distance, redThreshold, yellowThreshold, 50, 500);
            tone(buzzer, 1000, beepRate); // Activate the buzzer with the calculated beep rate
        } 
        // Check if the distance is less than the red threshold
        else if (distance < redThreshold) {
            tone(buzzer, 1000); // Activate the buzzer with a continuous tone for close distances Continuous tone
        }
    } else {
        noTone(buzzer); // Turn off the buzzer if no motion is detected
    }
}

// Purpose: Turns off all LED indicators and the buzzer
void turnOffAllLEDs() {
    setLEDState(LOW, LOW, LOW); // Set all LEDs to LOW
    noTone(buzzer); // Turn off the buzzer as well
}
