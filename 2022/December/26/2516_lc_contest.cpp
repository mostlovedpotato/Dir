#include<vector>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = count(s.begin(), s.end(), 'a');
        int b = count(s.begin(), s.end(), 'b');
        int c = count(s.begin(), s.end(), 'c');

        if (a < k || b < k || c < k) return -1;

        int ra = a - k;
        int rb = b - k;
        int rc = c - k;

        a = 0, b = 0, c = 0;

        int j = 0, maxSize = 0;
        for (int i = 0; i < n; i++) {
            a += (s[i] == 'a');
            b += (s[i] == 'b');
            c += (s[i] == 'c');
            while (j <= i && (a > ra || b > rb || c > rc)) {
                a -= (s[j] == 'a');
                b -= (s[j] == 'b');
                c -= (s[j] == 'c');
                j++;
            }
            maxSize = max(maxSize, i - j + 1);
        }
        return n - maxSize;
    }
};




