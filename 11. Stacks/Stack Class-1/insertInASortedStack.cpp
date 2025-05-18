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
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    int data = 25;
    insertInASortedStack(st,data);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();

    }
}