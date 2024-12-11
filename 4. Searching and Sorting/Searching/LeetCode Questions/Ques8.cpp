#include<iostream>
using namespace std;
int sqrt(int x){
    int start = 0;
    int end = x;
    long long int mid;
    int ans = -1;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(mid*mid == x){
            return mid;
        }
        else if(mid*mid < x){
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
    int x;
    cin >> x;
    cout << "Square root: " << sqrt(x);

}