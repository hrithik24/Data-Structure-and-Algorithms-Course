#include<iostream>
using namespace std;
string decodeMessage(string key,string message){
    // create mapping
    char start = 'a';
    char mapping[280] = {0};

    for(auto ch: key){
        if(ch != ' ' && mapping[ch] == 0){
            mapping[ch] = start;
            start++;
        }
    }

    // use mapping
    string ans;
    for(auto ch: message){
        if(ch == ' '){
            ans.push_back(' ');
        }
        else{
            char decodeChar = mapping[ch];
            ans.push_back(decodeChar);
        }
    }
    return ans;
}
int main(){
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << "Decoded Message: " << decodeMessage(key,message);

}