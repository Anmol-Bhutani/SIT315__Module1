const int motionSensor = 2;  // This motion sensor pin supports the interrupts
const int led = 13;          
volatile bool motionDetected = false; 

// Interrupt Service
void detectMotion() {
    motionDetected = true;  
}

void setup() {
    pinMode(motionSensor, INPUT); 
    pinMode(led, OUTPUT);         
    Serial.begin(9600);          

    // Attach the interrupt to the motion sensor pin
    attachInterrupt(digitalPinToInterrupt(motionSensor), detectMotion, RISING);
}

void loop() {
    if (motionDetected) {
        digitalWrite(led, HIGH);  
        Serial.println("Motion detected: LED ON");
        delay(2000);  // Keep LED on for 2 seconds
        digitalWrite(led, LOW);   
        Serial.println("Resetting LED: OFF");

        motionDetected = false;  
    }
}