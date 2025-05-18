#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int>s;

    // one by one queue se element lo and stack me daalo
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    // one by one stack se element lo and queue me push karo
    while(!s.empty()){
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseQueueUsingRecursion(queue<int>&q){
    // base case
    if(q.empty()){
        return;
    }

    int element = q.front();
    q.pop();

    reverseQueueUsingRecursion(q);

    q.push(element);

}
int main(){
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // reverseQueue(q);
    reverseQueueUsingRecursion(q);

    cout << "Printing Queue: " << endl;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout << element << " ";
    }  
}