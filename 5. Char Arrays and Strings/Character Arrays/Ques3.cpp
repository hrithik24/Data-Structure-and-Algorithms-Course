#include<iostream>
using namespace std;
void convertToUpperCase(char ch[], int size){
    int i = 0;
    
    while(ch[i] != '\0'){
        char currCharacter = ch[i];
        if(currCharacter >= 'a' && currCharacter <= 'z'){
            ch[i] = currCharacter - 'a' + 'A';
        }
        i++;
    }
}
int main(){
    char ch[100];
    cin >> ch;
    cout << "Befor: " << ch << endl;
    convertToUpperCase(ch,100);
    cout << "After: " << ch << endl;

}