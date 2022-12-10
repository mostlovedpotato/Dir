#include<iostream>
#include<vector>

using namespace std;

int count_decodings(char* digits, int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (digits[0] == '0')
		return 0;
	int count = 0;
	if (digits[n - 1] > '0') {
		count = count_decodings(digits, n - 1);
	}
	if (digits[n - 2] == '1' || (digits[n - 2] == '2' && digits[n - 1] < '7'))
		count += count_decodings(digits, n - 2);
	return count;
}