#include <iostream>
#include <vector>
using namespace std;

// Function to compute the longest prefix-suffix (LPS) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0; // Length of the previous longest prefix-suffix
    lps[0] = 0;     // LPS for the first character is always 0
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Fall back to the previous prefix-suffix
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to search for the pattern in the text
void KMPsearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Preprocess the pattern to create the LPS array
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for the text
    int j = 0; // Index for the pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    KMPsearch(text, pattern);

    return 0;
}
