#include<iostream>
#include <climits>
using namespace std;
int reverse(int n){
    int reverse = 0;
    bool isNegative = false;
    if(n <= INT_MIN){
        return 0;
    }
    if(n < 0){
        isNegative = true;
        n = -n;
    }
    while(n>0){
        if(reverse > INT_MAX / 10){
            return 0;
        }
        int rem = n%10;
        reverse = reverse * 10 + rem;
        n = n/10;   
    }
    return isNegative ? -reverse : reverse;

}
int main(){
    int n;
    cin >> n; 
    cout << reverse(n);
}