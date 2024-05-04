#include<iostream>
#include<string>
#include<set> // Include for set

using namespace std;

void dfs(string str, set<string>& a) {
    if (str.size() == 0) {
        return;
    }
    // case 1 : first character deletion
    string x = str.substr(1);
    a.insert(x);
    dfs(x, a);
    if (str.size() > 1) {
        string y = str[0] + str.substr(2);
        a.insert(y);
        dfs(y, a);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<string> a;
        dfs(s, a);
        cout << a.size() << endl;
    }
}
    