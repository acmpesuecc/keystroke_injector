# This is a keystroke injector.
Author: [Gallifrey](https://github.com/gall1frey)

## Why
To inject keystrokes by emulating a bluetooth keyboard using a nodeMCU.

## Tech Stack
* Arduino C++
* C
* [BLEkeyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) library

## How to Run
1. If you have a NodeMCU and an SD card module, upload the sketch and run it. 
2. But most probably you don't. That's okay. If you're working on implementing the keyboard functions, you only need to write the code, no testing required. Going through the library documentation should be enough.
3. If you're working on the interpreter, plug your interpreter code into ```test.c``` and compare the output with the text in ```ans1.txt``` and ```ans2.txt```

**Kindly note that ```test.c``` is just a program to test the interpreter you've written, if you've chosen to work on that issue. All other issues pertain to the ```.ino``` file.** 

## Is it beginner Friendly?
Yes! 

## What if I have a problem?
The first step is to always google stuff. Try different searches and keywords, look through stackoverflow.

If that doesn't help, contact any maintainer or ACM PESUECC team member!

This is an official repository maintained by ACM PESUECC for Hacktoberfest2021!
