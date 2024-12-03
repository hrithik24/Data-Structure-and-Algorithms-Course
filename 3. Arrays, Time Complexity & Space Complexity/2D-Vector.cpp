#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector < vector<int> > arr(5, vector<int>(10,0));
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    vector <vector<int> > brr;
 
    cout << "Jagged Array: " << endl;
    vector<int> v1(10,1);
    vector<int> v2(6,3);
    vector<int> v3(4,7);
    vector<int> v4(11,-1);
    vector<int> v5(2,-99);

    brr.push_back(v1);
    brr.push_back(v2);
    brr.push_back(v3);
    brr.push_back(v4);
    brr.push_back(v5);

    for(int i=0;i<brr.size();i++){
        for(int j=0;j<brr[i].size();j++){
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }


}