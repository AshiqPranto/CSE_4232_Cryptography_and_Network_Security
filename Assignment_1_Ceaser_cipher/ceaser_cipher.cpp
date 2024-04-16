#include<bits/stdc++.h>
using namespace std;
bool is_upper(char p){
    if(p >= 'A' && p <= 'Z'){
        return true;
    }
    return false;
}
bool is_lower(char p){
    if(p >= 'a' && p <= 'z'){
        return true;
    }
    return false;
}
string ceaser_cipher_encryption(string plain_text, int shift_key){
    int sz = plain_text.size();
    string cipher_text = plain_text;
    for(int i = 0; i<sz; i++){
        if(is_upper(plain_text[i])){
            cipher_text[i] = (plain_text[i] - 'A' + shift_key) % 26 + 'A';
        }
        else if(is_lower(plain_text[i])){
            cipher_text[i] = (plain_text[i] - 'a' + shift_key) % 26 + 'a';
        }
        else{
            cipher_text[i] = plain_text[i];
        }
    }
    return cipher_text;
}
string ceaser_cipher_decryption(string cipher_text, int shift_key){
    int sz = cipher_text.size();
    string plain_text = cipher_text;
    for(int i = 0; i<sz; i++){
        if(is_upper(cipher_text[i])){
            plain_text[i] = (cipher_text[i] - 'A' -shift_key + 26) %26 + 'A';
        }
        if(is_lower(cipher_text[i])){
            plain_text[i] = (cipher_text[i] - 'a' -shift_key + 26) %26 + 'a';
        }
        else{
            plain_text[i] = cipher_text[i];
        }
    }
    return plain_text;
}
int main(){
    string s;
    cout<<"Enter your string: ";
    cin>>s;
    int shift_key = 3;
    string cipher_text = ceaser_cipher_encryption(s, shift_key);
    cout<<"Cipher text : "<<cipher_text<<endl;
    string plain_text = ceaser_cipher_decryption(cipher_text, shift_key);
    cout<<"Plain text : "<<plain_text<<endl;

}