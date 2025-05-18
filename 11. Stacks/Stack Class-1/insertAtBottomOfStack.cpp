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
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    int data = 400;
    cout << "Before size: " << st.size() << endl;
    insertAtBottom(st,data);
    cout << "After size: " << st.size() << endl;


}