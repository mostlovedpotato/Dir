#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> present(K + 1, false); // Initialize boolean array to track presence

    // Mark elements present in the sequence
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num <= K) // Ensure the number is within the range [1, K]
            present[num] = true;
    }

    // Calculate the sum of numbers not present in the sequence
    long long sum = 0;
    for (int i = 1; i <= K; ++i) {
        if (!present[i]) // If number is not present, add it to the sum
            sum += i;
    }

    cout << sum << endl; // Output the sum

    return 0;
}
