#include<iostream>
#include<string.h>
using namespace std;
int findLength(char ch[],int size){
    int length = 0;
    for(int i=0;i<size;i++){
        if(ch[i] == '\0'){
            break;
        }
        else{
            length++;
        }
    }
    return length;
}
int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = findLength(ch,100);
    cout << "Length of an character array: " << length << endl;
    cout << "Length using in-build function: " << strlen(ch);
}