# Huffman Coding - Compression & Decompression in C++

This project is a C++ implementation of **Huffman Coding**, a popular **lossless data compression algorithm**. It compresses text files by assigning shorter binary codes to frequently used characters and longer codes to less frequent ones.

---

## 🚀 Features

- Compress any ASCII text string
- Decompress the encoded binary string back to the original
- Displays Huffman Codes for each character
- Calculates the compression ratio
- Built entirely in standard C++ using STL

---

## 📚 Introduction

Huffman Coding is a greedy algorithm used to compress data without any loss. It creates a binary tree where:
- **Frequent characters** are assigned **shorter codes**
- **Rare characters** are assigned **longer codes**

This project demonstrates the full encoding and decoding workflow using Huffman trees, maps, and priority queues.

---

## ⚙️ Implementation Details

### 🔹 Compression Steps

1. **Read Input**: Accepts a string or text input.
2. **Count Frequencies**: Uses a hash map to count character frequencies.
3. **Build Huffman Tree**: Constructs a binary tree using a priority queue.
4. **Generate Codes**: Traverses the tree to generate Huffman codes.
5. **Encode**: Replaces input characters with corresponding binary codes.
6. **Calculate Compression Ratio**.

### 🔹 Decompression Steps

1. **Reconstruct Huffman Tree** (or reuse it in memory).
2. **Decode**: Uses the tree to convert the binary string back to the original text.

---

## 🧪 Example

<img width="1186" height="511" alt="Screenshot 2025-07-16 at 12 37 23 PM" src="https://github.com/user-attachments/assets/b8b3413d-b3fc-4d5a-ac7f-77883d369cf3" />

