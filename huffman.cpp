#include <bits/stdc++.h> 
using namespace std;

// Node structure for each character in the Huffman tree
struct Node {
    char c;             // Character
    int freq;           // Frequency of the character
    Node* left;         // Left child
    Node* right;        // Right child
};

// Custom comparator for priority queue (min-heap based on frequency)
struct comp {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;  // Smaller frequency has higher priority
    }
};

// Recursive function to generate Huffman codes by traversing the tree
void encode(Node* root, string code, map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, store the code for the character
    if (!root->left && !root->right) {
        huffmanCodes[root->c] = code;
        return;
    }

    // Traverse left and right with '0' and '1' respectively
    encode(root->left, code + '0', huffmanCodes);
    encode(root->right, code + '1', huffmanCodes);
}

// Recursive function to decode the encoded binary string
void decode(Node* root, int& index, string res) {
    if (!root) return;

    // Reached a leaf node: print the character
    if (!root->left && !root->right) {
        cout << root->c;
        return;
    }

    // Move to the next bit
    index++;
    if (res[index] == '0') decode(root->left, index, res);
    else decode(root->right, index, res);
}

// Utility function to create a new node
Node* makeNode(char c, int freq, Node* left, Node* right) {
    Node* t = new Node();
    t->c = c;
    t->freq = freq;
    t->left = left;
    t->right = right;
    return t;
}

// Main function to build Huffman Tree and perform encoding/decoding
void buildHuffman(string text) {
    // Step 1: Count frequency of each character in the text
    map<char, int> freq;
    for (int i = 0; i < text.size(); i++) {
        freq[text[i]]++;
    }

    // Step 2: Build a min-heap (priority queue) of nodes
    priority_queue<Node*, vector<Node*>, comp> tree;
    for (auto p : freq) {
        tree.push(makeNode(p.first, p.second, NULL, NULL));
    }

    // Step 3: Construct Huffman Tree
    while (tree.size() > 1) {
        Node* node1 = tree.top(); tree.pop(); // least freq
        Node* node2 = tree.top(); tree.pop(); // next least freq

        // Merge two nodes into one (non-leaf, marked with '\0')
        int newFreq = node1->freq + node2->freq;
        tree.push(makeNode('\0', newFreq, node1, node2));
    }

    // Root of the Huffman tree
    Node* root = tree.top();

    // Step 4: Generate Huffman codes from the tree
    map<char, string> huffmanCodes;
    encode(root, "", huffmanCodes);

    // Step 5: Print Huffman Codes
    cout << "HUFFMAN CODES ARE:\n" << endl;
    for (auto p : huffmanCodes) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << endl;

    // Step 6: Encode the input text using Huffman codes
    string res = "";
    for (char ch : text) {
        res += huffmanCodes[ch];  // Append code for every character in original text
    }

    // Step 7: Print the encoded binary string
    cout << "ENCODED STRING IS:\n" << res << endl;

    // Step 8: Decode the binary string back to original text
    int index = -1;
    cout << "DECODED STRING IS:\n";
    while (index < (int)res.size() - 1) {
        decode(root, index, res);
    }
    cout << "\n\n";

    // Step 9: Compute and display compression ratio
    int originalSize = 8 * text.size();      // Original size in bits
    int convertedSize = res.size();          // Compressed size in bits
    double compression_Ratio = (double)convertedSize / originalSize;
    cout << "String is compressed to " << compression_Ratio * 100 << "% of the total size." << endl;
}

// Driver function
int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);     // Read input string

    buildHuffman(text);     // Call Huffman builder
    return 0;
}
