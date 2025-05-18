#include<iostream>
using namespace std;
class circularQueue{
    public:
        int *arr;
        int size;
        int rear;
        int front;

        circularQueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        // push
        void push(int data){
            // overflow
            if(front == 0 && rear == size-1 || rear == front-1){
                cout << "Overflow" << endl;
            }
            else if(front == -1 && rear == -1){
                // single element
                front++;
                rear++;
                arr[rear] = data;
            }
            else if(rear == size-1 && front != 0){
                // circular nature
                rear = 0;
                arr[rear] = data;
            }
            else{
                // normal flow
                rear++;
                arr[rear] = data;
            }
        }

        void pop(){
            // underflow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            else if(front == rear){
                // single element
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else if(front == size-1){
                // circular element
                arr[front] = -1;
                front = 0;
            }
            else{
                // normal flow
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        void print(){
            cout << "Printing Queue: ";
            for(int i=0;i<size;i++){
                cout << arr[i] << " ";
            }
             cout << endl;
       }
};
int main(){
    circularQueue q(5);
    q.print();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    q.push(60);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(100);
    q.print();
    q.push(200);
    q.push(300);
    q.print();
    q.push(340);
    q.print();
}