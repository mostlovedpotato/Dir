#include<vector>

using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int b = 0, a = 0;
        for (int i = 0; i < arr2.size(); i++) {
            b = b ^ arr2[i];
        }
        for (int i = 0; i < arr1.size(); i++) {
            a = a ^ (b & arr1[i]);
        }
        return a;
    }
};