#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Define a structure for a suffix tree node
struct SuffixTreeNode {
    unordered_map<char, SuffixTreeNode*> children;
    string edge; // Label on the edge
    bool isEnd;  // Indicates the end of a suffix

    SuffixTreeNode() : isEnd(false) {}
};

// Function to insert a suffix into the tree
void insertSuffix(SuffixTreeNode* root, const string& suffix) {
    SuffixTreeNode* current = root;
    for (char ch : suffix) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new SuffixTreeNode();
        }
        current = current->children[ch];
    }
    current->isEnd = true;
}

// Function to build a suffix tree for the given string
SuffixTreeNode* buildSuffixTree(const string& text) {
    SuffixTreeNode* root = new SuffixTreeNode();
    for (size_t i = 0; i < text.length(); ++i) {
        insertSuffix(root, text.substr(i));
    }
    return root;
}

// Function to search for a substring in the suffix tree
bool search(SuffixTreeNode* root, const string& substring) {
    SuffixTreeNode* current = root;
    for (char ch : substring) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return true;
}

// Helper function to print the suffix tree
void printSuffixTree(SuffixTreeNode* root, const string& prefix = "") {
    for (const auto& child : root->children) {
        cout << prefix << child.first << "\n";
        printSuffixTree(child.second, prefix + child.first);
    }
}

// Main function
int main() {
    string text;
    cout << "Enter the text to build the suffix tree: ";
    cin >> text;

    SuffixTreeNode* root = buildSuffixTree(text);

    cout << "\nSuffix Tree:\n";
    printSuffixTree(root);

    string query;
    cout << "\nEnter substring to search: ";
    cin >> query;

    if (search(root, query)) {
        cout << "Substring \"" << query << "\" is found in the text.\n";
    } else {
        cout << "Substring \"" << query << "\" is not found in the text.\n";
    }

    return 0;
}
