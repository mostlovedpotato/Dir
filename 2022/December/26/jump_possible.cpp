#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_possible_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_possible_index = max(max_possible_index, nums[i] + i);
            if (max_possible_index < i + 1) {
                break;
            }
        }
        return max_possible_index >= (nums.size() - 1);
    }
};