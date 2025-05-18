#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>& st,int &data){
    // base case
    if(st.empty()){
        st.push(data);
        return;
    }

    // 1 case me solve karunga
    int temp = st.top();
    st.pop();

    // recursive call
    insertAtBottom(st,data);

    // backtracking
    st.push(temp);
}

void reverseStack(stack<int>& st){
    // base case
    if(st.empty()){
        return;
    }

    // 1 case me solve karunga 
    int temp = st.top();
    st.pop();

    // recursive call
    reverseStack(st);

    // backtracking
    insertAtBottom(st,temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack after reversal: " << endl;
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}