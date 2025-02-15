#include<iostream>
using namespace std;
void findSubsequences(string str,string output,int index){
    // base case
    if(index >= str.length()){
        cout << "->" << output <<  endl;
        return;
    }

    // processing
    char ch = str[index];

    // include
    output.push_back(ch);
    findSubsequences(str,output,index+1);

    // exclude
    output.pop_back();
    findSubsequences(str,output,index+1);

    // if I need to put exclude first then
    // exclude
    // findSubsequences(str,output,index+1);

    // include
    // output.push_back(ch);
    // findSubsequences(str,output,index+1);
}
int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    findSubsequences(str,output,index);
}