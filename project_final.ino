#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>

#define RX            10
#define TX            11
#define CAPTEUR_VALUE A0

int Bouton = 2;
int etatBouton;
int BUZZER = 9;

const char *devEUI = "0072FB045E271CD5"; 
const char *appEUI = "70B3D57ED0027093"; 
const char *devAddr = "260113BF";
const char *nwkSKey = "5093162BF84ACBE76804062349B3DCB0";
const char *appSKey = "97EDFCC8A04E1A9D2A0F4EDB9D453930";

SoftwareSerial loraSerial(10,11);
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);
byte payload[1] = { 1 };

void sensorWarn () {
  tone(BUZZER, 1000); // Send 1KHz sound signal...
  delay(5000);        // ...for 1 sec
  noTone(BUZZER);     // Stop sound...
  delay(1000);        // ...for 1sec
}

void readSensor(int bouton) {
  int capteur = analogRead(CAPTEUR_VALUE);
  if (capteur > 200) {
    sensorWarn();
    debugSerial.println("Capteur de gaz plus 200!!" );
  }
    if(bouton == HIGH){
    debugSerial.println("OK I KNOW" );
    }
  debugSerial.println("Capteur: " + (String)(capteur));

}

void message(const byte* payload, size_t length, port_t port) {
  debugSerial.println("-- MESSAGE");
  debugSerial.print("Received " + String(length) + " bytes on port " + String(port) + ":");
    
  for (int i = 0; i < length; i++) {
    debugSerial.print(" " + String(payload[i]));
  }
    
  debugSerial.println();
}

void setup() {
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(Bouton, INPUT);
  etatBouton = LOW;

   // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    
 // Set callback for incoming messages
  ttn.onMessage(message);
  
  debugSerial.println("-- PERSONALIZE");
  ttn.personalize(devAddr, nwkSKey, appSKey);

  debugSerial.println("-- STATUS");
  ttn.showStatus();

  //debugSerial.println("--JOIN");
  //ttn.join(appEUI,appSKey);
}


void loop() {
  debugSerial.println("-- LOOP");
  etatBouton = digitalRead(Bouton);
  readSensor(etatBouton);

  // Prepare payload of 1 byte to indicate LED status
  byte data[1];
  data[0] = (analogRead(CAPTEUR_VALUE) >200) ? 1 : 0;

  // Send it off
  ttn.sendBytes(data, sizeof(data));

  delay(2000);

}
