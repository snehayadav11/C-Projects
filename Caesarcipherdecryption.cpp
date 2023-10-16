#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform Caesar cipher decryption
string caesarDecrypt(const string& input, int key) {
    string decryptedText = input;

    for (char& c : decryptedText) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base - key + 26) % 26) + base; // Adding 26 ensures a positive result
        }
    }

    return decryptedText;
}

int main() {
    string inputFile = "encrypted.txt";
    string outputFile = "decrypted.txt";
    int decryptionKey = 3; // Use the same key used for encryption

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string decryptedLine = caesarDecrypt(line, decryptionKey);
        outFile << decryptedLine << endl;
    }

    inFile.close();
    outFile.close();

    cout << "File decrypted successfully." << endl;

    return 0;
}