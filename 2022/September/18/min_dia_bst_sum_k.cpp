#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int ans = 1e5;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int num)
    {
        data = num;
        Node* left = NULL;
        Node* right = NULL;
    }
};

vector<int>  min_dia_bst(Node* curr, int k) {
    if (curr == NULL) {
        return { 0,0 };
    }
    vector<int> left_sum = min_dia_bst(curr->left, k);
    vector<int> right_sum = min_dia_bst(curr->right, k);

    int cur_sum = left_sum[0] + right_sum[0] + curr->data;
    int dia = 1 + left_sum[1] + right_sum[1];
    if (cur_sum == k) {
        ans = min(dia, ans);
    }

    vector<int> ret;
    ret.push_back(max(left_sum[0] + curr->data, right_sum[0] + curr->data));
    //ret.push_back(sum);
    ret.push_back(dia);
    return ret;
}

void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->data > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > key)
        prev->left = node;
    else
        prev->right = node;
}

int main()
{
    int k = 45;

    Node* root = NULL;
    insert(root, 30);
    insert(root, 50);
    insert(root, 15);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 60);

    vector<int> res = min_dia_bst(root, k);
    if (ans == 1e5) {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
    return 0;
}