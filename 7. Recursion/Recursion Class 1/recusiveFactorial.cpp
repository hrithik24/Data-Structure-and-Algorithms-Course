#include<iostream>
using namespace std;
int factorial(int n){
    // Base case
    if(n == 1 || n == 0){
        return 1;
    }

    // recursive call
    int recursiveAns = factorial(n-1);

    // processing
    int ans = n * recursiveAns;
}
int main(){

    cout << factorial(10) << endl;
    return 0;

}