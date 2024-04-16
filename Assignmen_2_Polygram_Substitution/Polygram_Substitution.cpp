#include<bits/stdc++.h>
using namespace std;
    
map<string, string> encodedString, decryptedString;

string polygram_substituition_encryption(string plain_text, int block_size){
    string cipher_text = "";
    int sz = plain_text.size();
    string temp_plain_text;
    for(int i = 0; i<sz; i+=block_size)
    {
        // 
        // if((i + block_size) >= sz)
        // {
        //     temp_plain_text = plain_text.substr(i, (sz - i));
        //     cipher_text += encodedString[temp_plain_text];
        // }
        temp_plain_text = plain_text.substr(i, 3);
        cipher_text += encodedString[temp_plain_text];
    }
    return cipher_text;
}
string polygram_substituition_decryption(string cipher_text, int block_size){
    string plain_text = "";
    int sz = cipher_text.size();
    string temp_cipher_text;
    for(int i = 0; i<sz; i+=block_size)
    {
        // 
        // if((i + block_size) >= sz)
        // {
        //     temp_plain_text = plain_text.substr(i, (sz - i));
        //     cipher_text += encodedString[temp_plain_text];
        // }
        temp_cipher_text = cipher_text.substr(i, 3);
        plain_text += decryptedString[temp_cipher_text];
    }
    return plain_text;
}

vector<string> split_line_by_space(string line){
    string word = "";
    vector<string> words;
    int sz = line.size();
    for(int i = 0; i<sz; i++){
        if(line[i] == ' '){
            words.push_back(word);
            // cout<<"debug: "<<word<<endl;
            word = "";
        }else{
            // word.push_back(line[i]);
            word += line[i];
        }
    }
    words.push_back(word);
    return words;
}

int main(){

    freopen("Mapping.txt", "r", stdin);
    string s;
    while (getline(cin, s))
    {
        if(s == "end") break;
        vector<string> words = split_line_by_space(s);
        encodedString[words[0]] = words[1];
        decryptedString[words[1]] = words[0];
        // cout<<words[0]<<", "<<words[1]<<endl;
    }
    // fclose(stdin);
    // string s;
    // freopen("Input.txt", "r", stdin);
    // cout<<"prev s = "<<s<<endl;
    cin>>s;
    // cout<<"After s = "<<s<<endl;
    cout<<"Plain text : "<<s<<endl;
    int block_size = 3;
    string cipher_text = polygram_substituition_encryption(s, block_size);
    cout<<"Cipher text : "<<cipher_text<<endl;
    string plain_text = polygram_substituition_decryption(cipher_text, block_size);
    cout<<"Plain text : "<<plain_text<<endl;

}