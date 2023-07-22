#include <iostream>
#include <vector>
#include <algorithm>


int a[200005];
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, k, tot, ans = 0;
		std::cin >> n;
		for (int i = 1; i <= n; i++)
			std::cin >> a[i];
		tot = a[1];
		for (int i = 2; i <= n; i++) {
			if (tot == 0) {
				ans++;
				tot = a[i];
			}
			else tot &= a[i];
		}
		if (tot == 0 || ans == 0)ans++;
		std::cout << ans << '\n';
	}
	return 0;
}