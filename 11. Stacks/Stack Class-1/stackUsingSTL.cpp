#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;

    // push 
    st.push(10);
    st.push(20);
    st.push(30);

    // top
    cout << st.top() << endl;

    // pop
    st.pop();

    cout << st.top() << endl;

    // empty
    if(st.empty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    // size
    cout << st.size();
}