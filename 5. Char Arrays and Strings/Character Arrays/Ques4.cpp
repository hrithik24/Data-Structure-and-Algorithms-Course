#include<iostream>
using namespace std;
void replaceWithSpace(char ch[], int size){
    int i = 0;
    
    while(ch[i] != '\0'){
        char currCharacter = ch[i];
        if(currCharacter == '@'){
            ch[i] = ' ';
        }
        i++;
    }
}
int main(){
    char ch[100];
    cin >> ch;
    cout << "Befor: " << ch << endl;
    replaceWithSpace(ch,100);
    cout << "After: " << ch << endl;

}