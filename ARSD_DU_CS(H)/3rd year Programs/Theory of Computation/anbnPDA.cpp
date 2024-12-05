#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool simulatePDA(const string &input) {
    stack<char> st;
    int state = 0; // Start in the initial state q0

    for (char ch : input) {
        if (state == 0) {
            if (ch == 'a') {
                st.push('X'); // Push 'X' for each 'a'
            } else if (ch == 'b' && !st.empty()) {
                st.pop(); // Pop 'X' for each 'b'
                state = 1; // Move to state q1
            } else {
                return false; // Invalid input
            }
        } else if (state == 1) {
            if (ch == 'b' && !st.empty()) {
                st.pop(); // Continue popping 'X' for each 'b'
            } else {
                return false; // Invalid input
            }
        }
    }

    // Accept if stack is empty and all input is processed
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Accepted: The string is in the language {a^n b^n | n > 0}.\n";
    } else {
        cout << "Rejected: The string is not in the language {a^n b^n | n > 0}.\n";
    }

    return 0;
}
