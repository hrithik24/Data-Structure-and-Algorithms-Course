#include<iostream>
#include <math.h>
using namespace std;
int setTheKthBit(int n, int k){
    int mask = 1 << k;
    int ans = n | mask;
    return ans;  
}
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << setTheKthBit(n,k);
}