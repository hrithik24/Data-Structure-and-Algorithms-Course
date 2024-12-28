#include<iostream>
#include<vector>
using namespace std;
void createMapping(string& str){
    char start = 'a';
    char mapping[300] = {0};
    
    for(auto ch: str){
        if(mapping[ch] == 0){
            mapping[ch] = start;
            start++;
        }
    }

    // update the string
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        str[i] = mapping[ch];
    }
}
vector<string> findAndReplacePattern(vector<string>& words,string pattern){
    vector<string> ans;
    //first normalize the pattern
    createMapping(pattern);

    // iterate the words
    for(string s: words){
        string tempString = s;
        // normalize the tempString
        createMapping(tempString);
        if(tempString == pattern){
            ans.push_back(s);
        }
    }
    for(auto i: ans){
        cout << i << " ";
    }
}
int main(){
    vector<string> words({"abc","deq","mee","aqq","dkd","ccc"});
    string pattern = "abb";
    findAndReplacePattern(words,pattern);
}