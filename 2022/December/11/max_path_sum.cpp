#include<iostream>
#include<vector>

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
 public : 
     int maxSum = -1e9;
     int maxPathSum(TreeNode* root) {
         Traverse(root);
         return maxSum;
     }
     int Traverse(TreeNode* root) {
         if (root == NULL) {
             return 0;
         }
         int leftSum = max(0, Traverse(root->left));
         int rightSum = max(0, Traverse(root->right));
         maxSum = max(maxSum, root->val + leftSum + rightSum);
         return max(leftSum, rightSum) + root->val;
     }
};