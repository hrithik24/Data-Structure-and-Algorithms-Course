#include<iostream>
using namespace std;
class deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        deque(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push_back(int data){
            // overflow
            if(front == 0 && rear == size-1 || rear == front-1){
                cout << "Overflow" << endl;
            }
            else if(front == -1 && rear == -1){
                // empty case
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

        void push_front(int data){
            if(front == 0 && rear == size-1 || rear == front-1){
                cout << "Overflow" << endl;
            }
            else if(front == -1 && rear == -1){
                // empty case
                front++;
                rear++; 
                arr[front] = data;
            }
            else if(front == 0 && rear != size-1){
                // circular nature
                front = size-1;
                arr[front] = data;
            }
            else{
                // normal flow
                front--;
                arr[front] = data;
            }
        }

        void pop_front(){
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

        void pop_back(){
            // underflow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            else if(front == rear){
                // single element
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                // circular element
                arr[rear] = -1;
                rear = size - 1;
            }
            else{ 
                // normal flow
                arr[rear] = -1;
                rear--;
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
    deque dq(5);
    dq.push_front(10);
    dq.print();

    dq.push_front(20);
    dq.print();

    dq.push_front(30);
    dq.print();
    
    dq.push_back(40);
    dq.print();

    dq.push_back(50);
    dq.print();

    dq.push_front(60);
    dq.print();

    dq.pop_front();
    dq.print();

    dq.pop_back();
    dq.print();


}