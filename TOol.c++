#include <iostream>
#include <string>

using namespace std;

// Caesar cipher
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


string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift); 
}

int main() {
    int shift;
    string input;

    cout << "Enter the shift value for encryption: ";
    cin >> shift;
    cin.ignore(); 
    cout << "Enter the text to encrypt: ";
    getline(cin, input);

    
    string encryptedText = encrypt(input, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    
    string decryptedText = decrypt(encryptedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
