the keyword is "retrival" yes with this spelling  !!!


Automated Code::Blocks Program Deployment
This project demonstrates an intriguing application of an Arduino-based Human Interface Device (HID) to automate the deployment of a C++ program within Code::Blocks. The Arduino, acting as a keyboard, simulates keystrokes to open Code::Blocks, type out a C++ keylogger program, and then compile and run it.

🚀 How it Works
The core of this project lies in the Arduino's ability to mimic keyboard inputs. Upon execution, the Arduino performs a sequence of automated actions:

Opens Code::Blocks: It triggers the "Run" dialog (Win + R) and inputs the path to the Code::Blocks executable.
Clears Editor: Once Code::Blocks is open, it selects and deletes any existing text in the active editor.
Types Program: It then systematically "types" the provided C++ keylogger code into the Code::Blocks editor.
Compiles and Runs: Finally, it simulates pressing F9 (the "Build and Run" shortcut in Code::Blocks) and saves the file as main.cpp.
The Embedded C++ Program
The C++ code that is automatically typed and executed by the Arduino is a basic keylogger. Here's a breakdown of its functionality:

It continuously monitors for keystrokes.
It filters out modifier keys (Shift, Ctrl, Alt, Caps Lock).
It accumulates captured keystrokes into a string.
Trigger Keyword: When the specific keyword RETRIVAL (note: there's a typo in the original C++ code, it's spelled "RETRIVAL" instead of "RETRIEVAL") is detected in the stream of captured keystrokes, it saves all the preceding captured data to a file named captured_keystrokes.txt.
Automatic Opening: After saving, it automatically opens captured_keystrokes.txt in Notepad.
⚠️ Important Considerations
Ethical Use: This project demonstrates the capabilities of HID automation. The included keylogger program is for educational and demonstrative purposes only. Using keyloggers without explicit consent is illegal and unethical. Please ensure you have the necessary permissions before deploying such tools in any real-world scenario.
Path Customization: The Arduino code assumes Code::Blocks is installed at C:\Program Files\CodeBlocks\codeblocks.exe. If your installation path is different, you'll need to update this line in the Arduino sketch:
C++

Keyboard.print("C:\\Program Files\\CodeBlocks\\codeblocks.exe"); // Update with the correct path if different

🛠️ Setup and Usage
To replicate this project, you will need:

An Arduino board capable of acting as an HID (e.g., Arduino Leonardo, Micro, Due, or any board with an ATmega32U4 chip).
The Arduino IDE for uploading the sketch.
Code::Blocks IDE installed on your Windows system.

Connect your Arduino: Connect your compatible Arduino board to your computer.
Open the Arduino Sketch: Copy the provided Arduino code into your Arduino IDE.
Verify and Upload: Select the correct board and port in the Arduino IDE, then upload the sketch to your Arduino.
Observe: Once uploaded, the Arduino will begin executing the programmed sequence, automatically opening Code::Blocks, typing the C++ code, and running it.
Feel free to contribute to this project or suggest improvements!
