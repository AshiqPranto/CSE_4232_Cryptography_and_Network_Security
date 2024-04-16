#include<iostream>
using namespace std;

string transpositionCipherEncryption(string plain_text, int width){
    int plain_text_sz = plain_text.size();
    int num_partial_column = plain_text_sz % width;
    int num_full_column = width - num_partial_column;
    string cipher_text = "";
    // int starting_index = 0;
    for(int starting_index = 0; starting_index < width; starting_index++){
        for(int temp_index = starting_index; temp_index < plain_text_sz; temp_index += width){
            cipher_text += plain_text[temp_index];
        }        
    }
    return cipher_text;
}

string transpositionCipherDecryption(string cipher_text, int width){
    int index = 0, cipher_text_sz = cipher_text.size();
    string plain_text(cipher_text_sz, ' ');
    // string plain_text = cipher_text;
    for(int starting_index = 0; starting_index < width; starting_index++){
        for(int temp_index = starting_index; temp_index < cipher_text_sz; temp_index+= width){
            plain_text[temp_index] = cipher_text[index++];
        }
    }
    return plain_text;
}
string removeSpaceFromString(string str){
    string ans = "";
    int sz = str.size();
    for(int i = 0; i<sz; i++){
        if(str[i] == ' ') continue;
        else{
            ans += str[i];
        }
    }
    return ans;
}


int main(){
    freopen("input.txt", "r", stdin);
    string plain_text;
    getline(cin, plain_text);
    cout<<"Yout plain text = "<<plain_text<<endl;
    // we have to remove space in the text
    plain_text = removeSpaceFromString(plain_text);
    // will do later
    string cipher_text = transpositionCipherEncryption(plain_text, 10);
    cout<<"Cipher text = "<<cipher_text<<endl;
    string plain_text_decrypted = transpositionCipherDecryption(cipher_text, 10);
    cout<<"After decryption Plain text = "<<plain_text_decrypted<<endl;
}