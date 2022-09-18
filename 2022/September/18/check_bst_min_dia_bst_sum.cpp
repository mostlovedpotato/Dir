#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int num)
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};
int target, ans;

// hash tables to keep track of 
// min values
// max values 
// diameter -> h
// sum of subtree -> sum
unordered_map<Node*, int> minv, maxv, h, sum;

// we keep checking if subtree is bst or not
bool isBST(Node* root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL
        && root->right == NULL) {
        minv[root] = root->data;
        maxv[root] = root->data;
        h[root] = 1;
        sum[root] = root->data;
        if (sum[root] == target)
            ans = min(ans, h[root]);
        return true;
    }


    if (root->left == NULL) {
        if (isBST(root->right)
            && minv[root->right] > root->data) {
            minv[root] = root->data;
            maxv[root] = maxv[root->right];
            h[root] = h[root->right] + 1;
            sum[root] = sum[root->right] + root->data;
            if (sum[root] == target)
                ans = min(ans, h[root]);
            return true;
        }
        return false;
    }
    if (root->right == NULL) {
        if (isBST(root->left)
            && maxv[root->left] < root->data) {
            minv[root] = minv[root->left];
            maxv[root] = root->data;
            h[root] = h[root->left] + 1;
            sum[root] = sum[root->left] + root->data;
            if (sum[root] == target)
                ans = min(ans, h[root]);
            return true;
        }
        return false;
    }
    bool bstleft = isBST(root->left);
    bool bstright = isBST(root->right);
    if (bstleft && bstright
        && maxv[root->left] < root->data
        && minv[root->right] > root->data) {
        minv[root] = minv[root->left];
        maxv[root] = maxv[root->right];
        int temp = 1 + h[root->left] + h[root->right];
        sum[root] = root->data + sum[root->left]
            + sum[root->right];
        h[root] = max(1 + h[root->left], 1 + h[root->right]);
        if (sum[root] == target)
            ans = min(ans, temp);
        return true;
    }
    return false;
}


int minSubtreeSumBST(int k, Node* root)
{
    ans = INT_MAX;
    target = k;

    isBST(root);
    if (ans == INT_MAX)
        return -1;
    return ans;
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
    int k = 225;

    Node* root = NULL;
    insert(root, 30);
    insert(root, 50);
    insert(root, 15);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 60);
    int res = minSubtreeSumBST(k, root);
    cout << res << endl;
    return 0;
}
