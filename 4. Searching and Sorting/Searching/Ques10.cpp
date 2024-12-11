#include<iostream>
using namespace std;
int getQuotient(int divisor, int divident){
    int start = 0;
    int end = divident;
    int ans = -1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(mid * divisor == divident){
            return mid;
        }
        if(mid * divisor < divident){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    int divisor = 4;
    int divident = -29;
    int ans = getQuotient(abs(divisor),abs(divident));

    if((divisor < 0 && divident > 0) || (divisor > 0 && divident < 0)){
        ans = -ans;
    }
    cout << "Final answer is: " << ans;
}