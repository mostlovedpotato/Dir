#include <algorithm>
#include<vector>

using namespace std;

int sumOfSmallestAndSecondSmallest(int n, vector<int>& arr) {
    // Write your code here.
    int maxSum = 0;
    for (int i = 0; i < n - 1; i++) {
        maxSum = max(maxSum, arr[i] + arr[i + 1]);
    }
    return maxSum;

}