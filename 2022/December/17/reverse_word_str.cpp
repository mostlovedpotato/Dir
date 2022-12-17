#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && curr != "") {
                res.push_back(curr);
                curr = "";
            }
            else if (s[i] == ' ' && curr == "") {
                continue;
            }
            else {
                curr += s[i];
            }
        }
        if (curr != "") {
            res.push_back(curr);
        }
        reverse(res.begin(), res.end());
        string ret = "";
        for (int i = 0; i < res.size(); i++) {
            if (i != res.size() - 1)
                ret += res[i] + " ";
            else
                ret += res[i];
        }
        return ret;
    }
};