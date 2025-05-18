#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(50);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    // dq.pop_front();

    cout << dq.size() << endl;

    for(int i=0;i<dq.size();i++){
        cout << dq[i] << " ";
    }

}