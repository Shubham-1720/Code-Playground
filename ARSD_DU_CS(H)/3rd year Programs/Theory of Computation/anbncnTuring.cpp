#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to simulate Turing Machine for the language anbncn
bool simulateTuringMachine(string input) {
    
    
    int head = 0;  // Turing machine head position
    int state = 0; // Initial state

    while (true) {
        char currentSymbol = input[head];

        switch (state) {
            case 0: // State to find 'a'
                if (currentSymbol == 'a') {
                    input[head] = 'X'; // Replace 'a' with 'X'
                    head++; // Move right
                    state = 1; // Go to state 1 to find 'b'
                } else if (currentSymbol == '-') {
                    return false; // Reject if we reach blank without matching
                } else {
                    head++; // Continue moving right
                }
                break;

            case 1: // State to find 'b'
                if (currentSymbol == 'b') {
                    input[head] = 'Y'; // Replace 'b' with 'Y'
                    head++; // Move right
                    state = 2; // Go to state 2 to find 'c'
                } else if (currentSymbol == '-') {
                    return false; // Reject if we reach blank without matching
                } else {
                    head++; // Continue moving right
                }
                break;

            case 2: // State to find 'c'
                if (currentSymbol == 'c') {
                    input[head] = 'Z'; // Replace 'c' with 'Z'
                    head = 0; // Go back to the beginning of the tape
                    state = 0; // Start over to find next 'a'
                } else if (currentSymbol == '-') {
                    return false; // Reject if we reach blank without matching
                } else {
                    head++; // Continue moving right
                }
                break;
        }

        // Check if we've finished processing
        bool allMatched = true;
        for (char ch : input) {
            if (ch == 'a' || ch == 'b' || ch == 'c') {
                allMatched = false;
                break;
            }
        }
        
        // If everything is matched, accept
        if (allMatched) {
            return true;
        }
    }
}

int main() {
    string input;
    cout << "Enter the string to process (format: a^n b^n c^n): ";
    cin >> input;
    input+='-';

    // Simulate the Turing Machine
    if (simulateTuringMachine(input)) {
        cout << "The string is accepted by the Turing Machine." << endl;
    } else {
        cout << "The string is not accepted by the Turing Machine." << endl;
    }

    return 0;
}
