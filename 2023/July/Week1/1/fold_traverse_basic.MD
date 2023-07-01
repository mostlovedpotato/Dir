We will have a basic tree traversal using our folding expressions.

```
#include<iostream>

struct Node{
	int value;
	Node *left;
	Node *right;
	Node(int i=0) : value(i), left(nullptr), right(nullptr) {}
};

auto left = &Node::left;
auto right = &Node::right;

//template for traversal for tree
template<typename T, typename... TP>
Node* traverse(T np,TP... Paths){
	return (np->* ... ->* Paths);
}

int main() {
	Node* root = new Node{0};
	root->left = new Node{1};
	root->right = new Node{2};
	root->left->right = new Node{3};
	root->left->right->left = new Node{4};
	
	Node* node = traverse(root, left, right, left);
	std::cout << node->value << '\n';
}
```