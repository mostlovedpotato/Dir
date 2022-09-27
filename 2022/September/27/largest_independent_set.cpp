#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

// If a node is included it's child can't be included
// but it's grandchild can be included
// lis(x) = max(1+lis_sum_of_all_grandchildren,sum_of_lis_for_all_children)

int max(int x, int y) {
	return (x > y) ? x : y;
}

class node {
public : 
	int data;
	node* left, * right;
};

int longest_independent_set(node* root) {
	if (root == NULL) return 0;
	int child_exclude = longest_independent_set(root->left) + longest_independent_set(root->right);
	int child_include = 1;
	if (root->left) {
		child_include += longest_independent_set(root->left->left) + longest_independent_set(root->left->right);
	}
	if (root->right) {
		child_include += longest_independent_set(root->right->left) + longest_independent_set(root->right->right);
	}
	return max(child_exclude, child_include);
}

class Node {
public :
	int data;
	int isset;
	Node* left, * right;
};

int lis(Node* toor) {
	if (toor == NULL) return 0;
	if (toor->isset)
		return toor->isset;
	if (toor->left == NULL && toor->right == NULL)
		return (toor->isset = 1);

	int child_exclude = lis(toor->left) + lis(toor->right);
	int child_include = 1;
	if (toor->left)
		child_include += lis(toor->left->left) + lis(toor->left->right);
	if (toor->right)
		child_include += lis(toor->right->left) + lis(toor->right->right);
	toor->isset = max(child_include, child_exclude);
	return toor->isset;
}