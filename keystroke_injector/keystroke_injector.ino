#include <BleKeyboard.h>
#include <SPI.h>
#include <SD.h>

File myFile; //File pointer to refer to the keystroke file on the SD card
BleKeyboard bleKeyboard; //Variable to define the bluetooth keyboard
String keycode; //var to hold the code in the keystroke file

//Helper Functions.
void interpret_keycode(String);
void write_string(String);
void shift_plus_char(char);
void ctrl_plus_char(char);
void ctrl_plus_shift_plus_char(char);
void win_plus_char(char);
void enter();
void arrow_key(char);

//Code that runs ONCE
void setup() {
  //Starts Serial Communication. This is only necessary for debugging purposes, but
  //since it doesn't actually interfere in the working of the code, it's just been left here.
  Serial.begin(115200);

  //prints the string "Starting BLE work!" to the serial monitor
  Serial.println("Starting BLE work!");

  //Starts bluetooth keyboard
  bleKeyboard.begin();

  //Prints "Initializing SD card..." to the serial monitor
  Serial.print("Initializing SD card...");

  //Starts Communication with the SD card
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }

  //When SD card is successfully initialized
  //Also, it's just redundant to explain every Serial.println statement, so skipping those.
  //They all basically print the argument string to the serial monitor.
  Serial.println("initialization done.");

  //Reads the file called 'key_code.txt' from the SD card.
  myFile = SD.open("key_code.txt");

  //if file exists
  if (myFile) {
    while (myFile.available()) {
      //Contents of key_code.txt copied to the string keycode
      keycode = myFile.read();
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
  //Check if bluetooth keyboard is connected to a computer
  if(bleKeyboard.isConnected()) {

    //This is the function where you parse the contents of key_code.txt (stored in variable keycode)
    //and inject keystrokes. Read interpreting_keycode.md for more info.
    interpret_keycode(keycode);
  }
  Serial.println("Waiting 10 seconds...");
  delay(10000);
}

void interpret_keycode(String code) {
  /*
    FUNCTION: This function parses the code given as argument, and calls other helper functions to
              send the keystrokes as mentioned to the computer.
    INPUT: code (string)
    OUTPUT: NONE
  */
  /*YOUR CODE GOES HERE*/
}

void write_string(String string_to_print) {
  /*
    FUNCTION: Given a string, this function sends it as keystrokes to the conencted computer.
    INPUT: string_to_print (string)
    OUTPUT: NONE
  */
  bleKeyboard.print("notepad");
}

void shift_plus_char(char letter) {
  bleKeyboard.press(0x10);
  ble.Keyboard.press(letter);
  delay(100);
  bleKeyboard.releaseAll()
  
}

void ctrl_plus_char(char letter) {
  /*
    FUNCTION: This function simulates pressing a letter key (not a special key) and ctrl simultaneously.
    INPUT: letter (char)
    OUTPUT: NONE
  */
  
  
  if(letter>='A' && letter<='z')
  {
    bleKeyboard.press(KEY_LEFT_CTRL);
    ble.Keyboard.press(letter);
    delay(200);
    bleKeyboard.releaseAll();
  }
}

void ctrl_plus_shift_plus_char(char letter) {
  /*
    FUNCTION: This function simulates pressing a letter key (not a special key) and shift+ctrl simultaneously.
    INPUT: letter (char)
    OUTPUT: NONE
  */
  
  
  if(letter>='A' && letter<='z')
  {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    ble.Keyboard.press(letter);
    delay(200);
    bleKeyboard.releaseAll();
  }
}

void win_plus_char(char letter) {
  /*
    FUNCTION: This function simulates pressing a letter key (not a special key) and windows key simultaneously.
    INPUT: letter (char)
    OUTPUT: NONE
  */
  /*YOUR CODE GOES HERE*/
  
  if(letter>='A' && letter>='z')
  {
    bleKeyboard.press(KEY_LEFT_GUI);
    ble.Keyboard.press(letter);
    delay(400);
    bleKeyboard.releaseAll();
  }
}

void enter() {
  /*
    FUNCTION: This function simulates pressing the enter key.
    INPUT: letter(char)
    OUTPUT: NONE
  */
  /*YOUR CODE GOES HERE*/
   bleKeyboard.press(0x28);
   bleKeyboard.release(0x28);
}

void arrow_key(char dir) {
  /*
    FUNCTION: This function simulates pressing an arrow key
    INPUT: dir (char) --> l: left, u: up, d: down, r: right
    OUTPUT: NONE
  */
  /*YOUR CODE GOES HERE*/
  if(dir==u)
  {
    bleKeyboard.press(KEY_UP_ARROW);
    ble.keyboard.press(dir);
  }
  else if (dir==d)
  {
    bleKeyboard.press(KEY_DOWN_ARROW);
    ble.keyboard.press(dir);
  }
  else if (dir==l)
  { 
   bleKeyboard.press(KEY_LEFT_ARROW);
   ble.keyboard.press(dir);
  }
  else(dir==r)
  {
    bleKeyboard.press(KEY_RIGHT_ARROW);
    ble.keyboard.press(dir);
  }
  bleKeyboard.releaseAll();
}
