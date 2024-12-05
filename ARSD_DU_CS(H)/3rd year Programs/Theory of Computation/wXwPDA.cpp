#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool simulatePDA(const string &input) {
    stack<char> st;
    int state = 0; // Start in state q0

    for (char ch : input) {
        if (state == 0) {
            if (ch == 'a' || ch == 'b') {
                st.push(ch); // Push characters of w onto the stack
            } else if (ch == 'X') {
                state = 1; // Transition to q1 on encountering 'X'
            } else {
                return false; // Invalid input
            }
        } else if (state == 1) {
            if (!st.empty() && (ch == st.top())) {
                st.pop(); // Pop and match with reverse of w
            } else {
                return false; // Mismatch or stack underflow
            }
        }
    }

    // Accept if stack is empty and all input is processed
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string over {a, b, X}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Accepted: The string is in the language {wXw^R | w ∈ {a, b}*}.\n";
    } else {
        cout << "Rejected: The string is not in the language {wXw^R | w ∈ {a, b}*}.\n";
    }

    return 0;
}
