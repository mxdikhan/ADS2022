#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

	void _preorder(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

	void _postorder(Node* node) {
		if (!node) return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->val << " ";
	}

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	int _rightmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}

	int _leftmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->left) return cur->val;
		return _leftmost(cur->left);
	}


	int _getSize(Node* node) {
		if (!node) return 0;
		return _getSize(node->left) + _getSize(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		else {
			Node* found = _search(cur->left, target);
			if (found == nullptr) {
				found = _search(cur->right, target);
			}
			return found;
		}
		return nullptr;
	}

public:
	BST() {
		this->root = nullptr;
	}

	void inorder() {
		_inorder(root);
		cout << endl;
	}

	void preorder() {
		_preorder(root);
		cout << endl;
	}

	void postorder() {
		_postorder(root);
		cout << endl;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		// if (!root) root = newNode;
		if (root == nullptr) root = newNode;
	}


	Node* search(int target) {
		return _search(root, target);
	}

	Node* getRoot() {
		return root;
	}

	void setRoot(Node* root) {
		this->root = root;
	}

	int getSize() {
		return _getSize(root);
	}
    int getSize2(int x) {
		return _getSize(search(x));
	}

	int getHeight(Node* node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;
	}

    void solve(int l){
        Node* node=search(l);
        _preorder(node);
    }
   
	
};


int main() {
BST bst;
int n, k,l;
cin>>n;
for (int i = 0; i < n; i++)
{
    cin>>k;
    bst.insert(k);
}
cin>>l;
bst.solve(l);

	return 0;
}