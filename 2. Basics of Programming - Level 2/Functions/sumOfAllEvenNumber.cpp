#include<iostream>
using namespace std;
void sumOfAllEvenNumber(int n){
    int sum = 0;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            sum = sum + i;
        }
    }
    cout << sum;
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    sumOfAllEvenNumber(n);

}