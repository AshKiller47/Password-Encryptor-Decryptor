#include <iostream>
#include <cctype>

using namespace std;

char decryptTrivial[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char decryptCapital[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char decryptSpecial[] = { '!', '@', '#', '$', '%', '^', '&', '*', '+', '=', '?', '~' };
char decryptNumeral[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

char encryptTrivial[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '+', '=', '?', '~', 'a', 'e', 'i', 'o', 'u' };
char encryptCapital[] = { 'U', 'O', 'I', 'E', 'A', '~', '?', '=', '+', '*', '&', '^', '%', '$', '#', '@', '!', '0', '9', '8', '7', '6', '5', '4', '3', '2', '1' };
char encryptSpecial[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '6', '9', '7' };
char encryptNumeral[] = { '!', '@', '#', '$', '%', '^', '&', '*', '+', '=', '?', '~' };

void encrypt(string&, int&);
void decrypt(string&, int&);

int main() {
    
    cout << "*********PASSWORD ENCRYPTOR/DECRYPTOR*********" << "\n";
    
    int choice;
    
    cout << "\nAvailable Operations :-" << "\n";
    cout << "\n1. Encrypt Password";
    cout << "\n2. Decrypt Password";
    cout << "\n3. Exit Program" << "\n";
    cout << "\nEnter Choice: "; cin >> choice;
    
    while(choice != 1 && choice != 2 && choice != 3) {
        
        cout << "\nInvalid Choice. Try Again." << "\n";
        cout << "\nEnter Choice: "; cin >> choice;
        
    }
    
    if(choice == 1) cout << "\nEnter Decrypted Password: ";
    else if(choice == 2) cout << "\nEnter Encrypted Password: ";
    else { cout << "\nTerminating Program..." << "\n"; exit(0); }
    
    string password; cin >> password;
    
    cout << "\nEnter Rotation Factor: ";
    
    int rotation; cin >> rotation;
    
    if(choice == 1) encrypt(password, rotation);
    else decrypt(password, rotation);
    
    if(choice == 1) cout << "\nEncrypted Password: ";
    else if(choice == 2) cout << "\nDecrypted Password: ";
    
    cout << password << "\n";
    
    return 0;
    
}

void encrypt(string &password, int &rotation) {
    
    for(char &key: password) {
        
        if(islower(key))
            
            for(int i = 0; i < 26; i++) {
                
                if(key == decryptTrivial[i]) { int index = i + rotation; while(index > 26) index -= 27; key = encryptTrivial[index]; break; }
                
            }
            
        else if(isupper(key))
            
            for(int i = 0; i < 26; i++) {
                
                if(key == decryptCapital[i]) { int index = i + rotation; while(index > 26) index -= 27; key = encryptCapital[index]; break; }
                
            }
            
        else if(isdigit(key))
            
            for(int i = 0; i < 10; i++) {
                
                if(key == decryptNumeral[i]) { int index = i + rotation; while(index > 11) index -= 12; key = encryptNumeral[index]; break; }
                
            }
            
        else
            
            for(int i = 0; i < 12; i++) {
                
                if(key == decryptSpecial[i]) { int index = i + rotation; while(index > 12) index -= 13; key = encryptSpecial[index]; break; }
                
            }
            
    }
    
}

void decrypt(string &password, int &rotation) {
    
    for(char &key: password) {
        
        if(islower(key))
            
            for(int i = 22; i < 27; i++) {
                
                if(key == encryptTrivial[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) key = decryptTrivial[index]; else key = '.'; break; }
                
            }
            
        else if(isupper(key))
            
            for(int i = 0; i < 5; i++) {
                
                if(key == encryptCapital[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) key = decryptCapital[index]; else key = '.'; break; }
                
            }
            
        else if(isdigit(key)) {
            
            cout << "\n";
            
            for(int i = 0; i < 10; i++) {
                
                if(key == encryptTrivial[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) cout << decryptTrivial[index]; else cout << '.'; break; }
                
            }
            
            cout << "\t";
            
            for(int i = 18; i < 27; i++) {
                
                if(key == encryptCapital[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) cout << decryptCapital[index]; else cout << '.'; break; }
                
            }
            
            cout << "\t";
            
            for(int i = 0; i < 13; i++) {
                
                if(key == encryptSpecial[i]) { int index = i - rotation; while(index < 0) index += 13; if(index < 12) cout << decryptSpecial[index]; else cout << '.'; break; }
                
            }
            
            key = '_'; cout << "\n";
            
        }
        
        else {
            
            cout << "\n";
            
            for(int i = 10; i < 22; i++) {
                
                if(key == encryptTrivial[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) cout << decryptTrivial[index]; else cout << '.'; break; }
                
            }
            
            cout << "\t";
            
            for(int i = 5; i < 18; i++) {
                
                if(key == encryptCapital[i]) { int index = i - rotation; while(index < 0) index += 27; if(index < 26) cout << decryptCapital[index]; else cout << '.'; break; }
                
            }
            
            cout << "\t";
            
            for(int i = 0; i < 12; i++) {
                
                if(key == encryptNumeral[i]) { int index = i - rotation; while(index < 0) index += 12; if(index < 10) cout << decryptNumeral[index]; else cout << '.'; break; }
                
            }
            
            key = '_'; cout << "\n";
            
        }
        
    }
    
}