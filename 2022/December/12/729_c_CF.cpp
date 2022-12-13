#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#define  pi acos(-1.0)
#define  eps 1e-6
#define  fi first
#define  se second
#define  lson l,m,rt<<1
#define  rson m+1,r,rt<<1|1
#define  bug         printf("******\n")
#define  mem(a,b)    memset(a,b,sizeof(a))
#define  fuck(x)     cout<<"["<<"x="<<x<<"]"<<endl
#define  f(a)        a*a
#define  sf(n)       scanf("%d", &n)
#define  sff(a,b)    scanf("%d %d", &a, &b)
#define  sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define  sffff(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define  FIN         freopen("DATA.txt","r",stdin)
#define  gcd(a,b)    __gcd(a,b)
#define  lowbit(x)   x&-x
#pragma  comment (linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long  LL;
typedef unsigned long long ULL;
const int INF = 0x7fffffff;
const LL  INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 10;
string s1, s2, s3;
int cal(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) sum = (sum + s[i] - '0') % 3;
    if (!s.size()) return 1;
    return sum;
}
void del(string& s) {
    while (s[0] == '0' && s.size() > 1) s.erase(0, 1);
}
int main() {
    cin >> s1;
    int tot = cal(s1), num1 = 1, num2 = 2, p = 3 - tot;
    s2 = s3 = s1;
    if (!tot) {
        cout << s1 << endl;
        return 0;
    }
    for (int i = s1.size(); i >= 0; i--) {
        if ((s2[i] - '0') % 3 == tot && num1) {
            s2.erase(i, 1);
            num1--;
        }
        if ((s3[i] - '0') % 3 == p && num2) {
            s3.erase(i, 1);
            num2--;
        }
    }
    num1 = cal(s2), num2 = cal(s3);
    del(s2), del(s3);
    if (num1 && num2) return 0 * printf("-1\n");
    if (!num1 && !num2) {
        if (s2.size() > s3.size()) cout << s2 << endl;
        else cout << s3 << endl;
    }
    else if (!num1) cout << s2 << endl;
    else cout << s3 << endl;
    return 0;
}