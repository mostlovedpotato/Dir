#include<vector>
#include<iostream>
#include<stack>
#include<string>

using namespace std;


class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*' && !st.empty()) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty()) {
            char a = st.top();
            st.pop();
            ans.push_back(a);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};