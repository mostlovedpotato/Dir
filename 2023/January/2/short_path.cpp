#include<iostream>
#include<vector>

using namespace std;

class TreeNode {
    TreeNode < T >** children;
    int childCount;

public:
    T data;
    TreeNode(T data);
    int numChildren();
    void addChild(TreeNode < T >* child);
    TreeNode < T >* getChild(int index);
    void setChild(int index, TreeNode < T >* child);
};

TreeNode<int>* lca(TreeNode<int>* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }
    TreeNode<int>* left = lca(root->getChild(0), n1, n2);
    TreeNode<int>* right = lca(root->getChild(1), n1, n2);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else return root;
}

int lvl(TreeNode<int>* root, int x, int level) {
    if (root == NULL) return -1;
    if (root->data == x) return level;
    int left = lvl(root->getChild(0), x, level + 1);
    if (left != -1)
        return lvl(root->getChild(1), x, level + 1);
    return left;
}
int findPath(TreeNode<int>* root, int n1, int n2) {
    // Write your code here.
    TreeNode<int>* LCA = lca(root, n1, n2);
    int d1 = lvl(LCA, n1, 0);
    int d2 = lvl(LCA, n2, 0);
    return d1 + d2;
}