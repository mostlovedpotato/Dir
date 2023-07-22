#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* zero, * one;
};

TrieNode* newNode() {
    TrieNode* temp = new TrieNode;
    temp->zero = temp->one = NULL;
    return temp;
}

void insert(TrieNode* root, int n) {
    TrieNode* temp = root;

    for (int i = 31; i >= 0; i--) {
        bool val = n & (1 << i);
        if (val == 0) {
            if (temp->zero == NULL) {
                temp->zero = newNode();
            }
            temp = temp->zero;
        }
        else {
            if (temp->one == NULL) {
                temp->one = newNode();
            }
            temp = temp->one;
        }
    }
}


int query(TrieNode* root, int n) {
    TrieNode* temp = root;
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        bool val = n & (1 << i);
        if (val == 0) {
            if (temp->one != NULL) {
                res ^= (1 << i);
                temp = temp->one;
            }
            else temp = temp->zero;
        }
        else {
            if (temp->zero != NULL) {
                res ^= (1 << i);
                temp = temp->zero;
            }
            else temp = temp->one;
        }
    }
    return res;
}

using namespace std;

int main()
{
    // int arr[] = {8,2,4,12,1};
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        TrieNode* root = newNode();
        insert(root, 0);
        int result = INT_MIN;
        int pre_xor = 0;

        for (int i = 0; i < arr.size(); i++) {
            pre_xor = pre_xor ^ arr[i];
            insert(root, pre_xor);
            int curr = query(root, pre_xor);
            result = max(result, curr);
        }
        cout << result << endl;

    }



    return 0;
}