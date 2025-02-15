#include<iostream>
#include<vector>
using namespace std;
vector<bool> Sieve(int n){
    vector<bool> sieve(n+1,true);
    sieve[0] = sieve[1] = false;

    for(int i=2;i*i<n;i++){ // optimisation 2 if i becomes > sqrt(N), then the inner loop does not work
        if(sieve[i] == true){
            // int j = i*2;
            int j = i*i; // optimisation 1 first unmarked number would be i*i as, other have been marked by 2 to (i - 1).
            while(j<=n){
                sieve[j] = false;
                j+=i;
            }
        }
    }
    return sieve;
}
int main(){
    vector<bool>sieve = Sieve(25);
    for(int i=0;i<25;i++){
        if(sieve[i]){
            cout << i << " ";
        }
    }
}