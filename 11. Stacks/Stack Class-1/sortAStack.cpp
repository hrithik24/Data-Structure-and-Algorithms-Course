#include<iostream>
#include<stack>
using namespace std;
void insertInASortedStack(stack<int>& st,int &data){
    if(st.empty() || st.top() < data){
        st.push(data);
        return;
    }

    // 1 case me solve karunga
    int temp = st.top();
    st.pop();

    // recursive call
    insertInASortedStack(st,data);

    // backtracking
    st.push(temp);

}
void sortAStack(stack<int>& st){
    //base case
    if(st.empty()){
        return;
    }

    // 1 case solve karunga
    int temp = st.top();
    st.pop();

    // recursive call
    sortAStack(st);

    // backtracking
    insertInASortedStack(st,temp);
}
int main(){
    stack<int> st;
    st.push(5);
    st.push(20);
    st.push(300);
    st.push(10);

    sortAStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();

    }
}