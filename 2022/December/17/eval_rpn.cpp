#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long b = st.top(); st.pop();
                long a = st.top(); st.pop();
                if (tokens[i] == "+") {
                    st.push(a + b);
                }
                else if (tokens[i] == "-") {
                    st.push(a - b);
                }
                else if (tokens[i] == "*") {
                    st.push(a * b);
                }
                else {
                    st.push(a / b);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};