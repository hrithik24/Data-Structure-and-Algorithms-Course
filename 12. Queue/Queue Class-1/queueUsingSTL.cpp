#include<iostream>
#include<queue>
using namespace std;
int main(){
    // creation
    queue<int>q;
    
    //insertion
    q.push(5);

    //size
    cout << "Size of Queue: " << q.size() << endl;

    // empty
    if(q.empty() == true){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }

    // remove
    q.pop();

    //size
    cout << "Size of Queue: " << q.size() << endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element of Queue is: " << q.front() << endl;
    cout << "Rear or Last element of Queue is: " << q.back() << endl;


}