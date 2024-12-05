#include <iostream>
#include <stdio.h>
using namespace std;

// Function to increment a binary number using a Turing Machine simulation
string incrementBinary(string binary) {
    int head = binary.size() - 1; // Start from the least significant bit (rightmost) (binary.size() gives the length of the string)
    bool carry = true; // We need to carry the addition of 1 initially

    while (carry && head >= 0) {
        if (binary[head] == '0') {
            binary[head] = '1'; // Change '0' to '1' and stop carrying
            carry = false; // No more carry needed
        } else if (binary[head] == '1') {
            binary[head] = '0'; // Change '1' to '0' (carry continues until we find a 0)
        }
        head--; // Move to the left
    }

    // If we still have a carry after the leftmost bit, we need to add '1' at the front
    if (carry) {
        binary = '1' + binary; // Add '1' to the front
    }

    return binary; 
}

int main() {
    string binary;
    cout << "Enter a binary number : "; // e.g. 1011
    cin >> binary;

    // Increment the binary number
    string incrementedBinary = incrementBinary(binary);
    
    cout<<"Original binary number is :"<<binary<<endl;
    cout << "Incremented binary number is: " << incrementedBinary << endl;
    
    return 0;
}
