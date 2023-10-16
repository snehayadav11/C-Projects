#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform Caesar cipher encryption
string caesarEncrypt(const string& input, int key) {
    string encryptedText = input;
    
    for (char& c : encryptedText) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + key) % 26) + base;
        }
    }
    
    return encryptedText;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "encrypted.txt";
    int encryptionKey = 3; // Change this to your desired encryption key

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string encryptedLine = caesarEncrypt(line, encryptionKey);
        outFile << encryptedLine << endl;
    }

    inFile.close();
    outFile.close();

    cout << "File encrypted successfully." << endl;
    
    return 0;
}