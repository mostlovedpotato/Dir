#include<iostream>
#include<vector>

template<typename T>
void InsertionSort(T arr[], int n) {
	int i, j;
	for (int i = 1; i < n; i++) {
		j = i;
		while ((j > 0) && (s[j] < s[j - 1])) {
			std::swap(&s[i], &s[j - 1]);
			j = j - 1;
		}
	}
}