#include <iostream> 

#define f first
#define s second

typedef std::pair<int, int> pt;

pt A, B, C;

inline bool read() {
	if (!std::cin >> A.f >> A.s) {
		return false;
	}
	std::cin >> B.f >> B.s;
	std::cin >> C.f >> C.s;
	return true;
}

int dist(const pt& A, const pt& B) {
	return abs(A.f - B.f) + abs(A.s - B.s);
}

inline void solve() {
	std::cout << (dist(A, B) + dist(A, C) - dist(B, C)) / 2 + 1 << '\n';
}

int main() {
	int t; 
	std::cin >> t;
	while (t--) {
		read();
		solve();
	}
	return 0;
}