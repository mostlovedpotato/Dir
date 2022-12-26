#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int min_sol = 1e8 + 9;
        int n = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (target == words[i]) {
                min_sol = min(min_sol, abs(i + n - startIndex) % n);
                min_sol = min(min_sol, min(abs(i - startIndex) % n, abs((i - n) - startIndex) % n));
            }
        }
        if (min_sol == 1e8 + 9) {
            return -1;
        }
        else return min_sol;
    }
};