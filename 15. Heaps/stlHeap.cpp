#include<iostream>
#include<queue>
using namespace std;
int main(){
    // create max-heap
    priority_queue<int> pq;
    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top element of Heap: " << pq.top() << endl;

    pq.pop();

    cout << "Top element of Heap: " << pq.top() << endl;

    cout << "Size of max heap: " << pq.size() << endl;
    if(pq.empty()){
        cout << "Empty" << endl;
    }
    else{
        cout << "not empty" << endl;
    }


    // min heap creation
    priority_queue<int,vector<int>,greater<int>> p;
    // insertion
    p.push(100);
    p.push(90);
    p.push(70);

    cout << "Top element of heap: " << p.top() << endl;
    p.pop();

    cout << "Top element of heap: " << p.top() << endl;
    cout << "Size: " << p.size() << endl;
    if(p.empty()){
        cout << "Empty" << endl;
    }
    else{
        cout << "Not Empty" << endl;
    }
    return 0;
     
}