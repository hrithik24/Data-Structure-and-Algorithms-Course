#include<iostream>
#include<queue>
using namespace std;
void interleaveQueue(queue<int> &first){
    int size = first.size();
    queue<int>second;

    // push first half of queue in second queue
    for(int i=0;i<size/2;i++){
        int temp = first.front();
        first.pop();

        second.push(temp);
    }

    // merge both the halves in original queue named as first queue
    for(int i=0;i<size/2;i++){
        int temp = second.front();
        second.pop();

        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }
}
int main(){
    queue<int>first;

    first.push(10);
    first.push(20);
    first.push(30);
    first.push(40);
    first.push(50);
    first.push(60);

    interleaveQueue(first);
    cout << "Printing Queue: " << endl;
    while(!first.empty()){
        int element = first.front();
        first.pop();
        cout << element << " ";
    } 

}