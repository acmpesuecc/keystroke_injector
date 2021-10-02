#include <BleKeyboard.h>
#include <SPI.h>
#include <SD.h>

File myFile;
BleKeyboard bleKeyboard;
String keycode;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  myFile = SD.open("key_code.txt");
  if (myFile) {
    while (myFile.available()) {
      keycode = myFile.read();
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
  if(bleKeyboard.isConnected()) {
    /*YOUR CODE HERE*/
    /*Serial.println("Opening Notepad...");
    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('r');
    delay(100);
    bleKeyboard.releaseAll();
    delay(100);
    bleKeyboard.print("notepad");
    delay(100);
    bleKeyboard.write(KEY_RETURN);
    
    delay(1000);

    Serial.println("Sending random text");
    bleKeyboard.print("Hello worldsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F4);
    delay(100);
    bleKeyboard.releaseAll();

    delay(1000);*/
  }
  Serial.println("Waiting 10 seconds...");
  delay(10000);
}
