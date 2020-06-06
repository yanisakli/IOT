#include <EEPROM.h>

#define interval 250
#define clockInterval 1000 // Each second

#define sensorPin 4
#define microPin 7
#define electroPin 12
#define speakerPin 13

unsigned long previousClockMillis = 0; // Will store last time the clock was updated
unsigned long previousMillis = 0; // Will store last time update program was run
unsigned long currentMillis; // Will store current app time

long nextAlarm; // Time until next alarm (in ms)
bool alarmStopped = false; // If user stopped the alarm

String command;

void setup()
{
  Serial.begin(9600);

  // Alarm setup
  pinMode(speakerPin, OUTPUT);
  pinMode(electroPin, OUTPUT);
  noTone(speakerPin);

  // Save next alarm in memory
  EEPROM.write(0, 5000 * 1000); // For DEMO

  // Read nextAlarm from memory
  nextAlarm = EEPROM.read(0) * 1000;
}

// Handle a received command by user input
void handleCommand(String c) {
  // Stop the alarm
  if (c.equals("STOP")) {
    alarmStopped = true;
    Serial.println("Alarm stopped.");
  } else if (c.startsWith("SET")) {
    // Set the alarm time
    alarmStopped = false;

    long nextAlarmInMin = c.substring(3).toInt();
    Serial.print("Next alarm in ");
    Serial.print(nextAlarmInMin);
    Serial.println("min");

    nextAlarm = nextAlarmInMin * 1000;
    EEPROM.write(0, nextAlarmInMin);
  } else {
     Serial.println("Unknown command: " + c);
  }
}

// Main program
void loop()
{
  currentMillis = millis();

  // App interval without delay()
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Manage movements detection
    if (LOW == digitalRead(sensorPin)){
      Serial.println("Moving");
    }

    // Manage sound detection
    if (HIGH == digitalRead(microPin)){
      Serial.println("Talking");
    }

    // Listen for any user commands
    command = Serial.readString();
    if (command.length() > 0) {
      handleCommand(command);
    }
  }

  // Alarm interval without delay()
  if (currentMillis - previousClockMillis >= clockInterval) {
    previousClockMillis = currentMillis;
    nextAlarm -= clockInterval;

    // Alarm time reached
    if (nextAlarm <= 0) {
      // Stop alarm if user asked
      if (alarmStopped) {
        noTone(speakerPin);
        digitalWrite(electroPin, LOW);
      } else {
        // Trigger alarm
        tone(speakerPin, 500);
        digitalWrite(electroPin, HIGH);
      }
    }
  }
}
