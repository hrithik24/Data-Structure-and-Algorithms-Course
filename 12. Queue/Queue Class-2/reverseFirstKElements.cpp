#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstKElements(queue<int>& q,int k){
    int n = q.size();

    if(k > n || k==0){
        return;
    }
    
    //push first k elements into stack
    stack<int>s;
    for(int i=0;i<k;i++){
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    //push all k elements into queue
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // pop and push first (n-k) elements into queue again
    for(int i=0;i<n-k;i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
int main(){
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;
    reverseFirstKElements(q,k);

    cout << "Printing Queue: " << endl;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout << element << " ";
    }  
}