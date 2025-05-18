#include<iostream>
#include<stack>
using namespace std;
bool checkRedundant(string &str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int countOperator = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    countOperator++;
                }
                st.pop();
            }
            // yaha pr aap tabhi pohchoge jab stack ke top per ek opening bracket h
            st.pop();
            if(countOperator == 0){
                return true;
            }
        }
    }
    // agar me yaha tak pocha hu iska mtlab k har ek bracket ke bech me ek operator pakka mila hoga
    return false;
}
int main(){
    string str = "(((a+b)*(c+d)))";
    bool ans = checkRedundant(str);

    if(ans == true){
        cout << "Redundant Brackets Present" << endl;
    }
    else{
        cout << "Redundant Brackets not present" << endl;
    }
    return 0;
}