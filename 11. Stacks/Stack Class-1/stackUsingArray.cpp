#include<iostream>
using namespace std;
class Stack{
    public:
        int* arr;
        int size;
        int top;

        // default constructor
        Stack(int size){
            arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        // push
        void push(int data){
            if(top == size-1){
                cout << "Stack Overflow";
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        // pop
        void pop(){
            if(top == -1){
                cout << "Stack underflow" << endl;
                return;
            }
            else{
                top--;
            }
        }

        // empty 
        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        // top
        int getTop(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }
            else{
                return arr[top];
            }        
        }

        // size
        int getSize(){
            return top+1;
        }

        void print(){
            cout << "Stack: ";
            for(int i=0;i<getSize();i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    // creation 
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    cout << st.getTop() << endl;
    cout << st.getSize() << endl;
    
    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
}