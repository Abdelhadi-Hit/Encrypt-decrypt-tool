#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a string using a Caesar cipher
string encrypt(string text, int shift) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
        result += c;
    }
    return result;
}

// Function to decrypt an encrypted string using a Caesar cipher
string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift); // Decryption is essentially encryption with the opposite shift
}

int main() {
    int shift;
    string input;

    cout << "Enter the shift value for encryption: ";
    cin >> shift;
    cin.ignore(); // Clear the newline character from the buffer

    cout << "Enter the text to encrypt: ";
    getline(cin, input);

    // Encrypt the input text
    string encryptedText = encrypt(input, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    // Decrypt the encrypted text
    string decryptedText = decrypt(encryptedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
