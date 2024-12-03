// #include<iostream>
// using namespace std;


// int main(){
//     int n;
//     int i=1;
//      int j = i,count = 1;
//     while(i<n){
//         while(count<i){
//             cout<<j;
//             j = j + 1;
//             count = count + 1;
//         }
//         cout<<"\n";
//         i = i + 1;
//     }
// }

#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j = i,count = 1;
        while(count<=i){
            cout<<j;
            j = j + 1;
            count = count + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}