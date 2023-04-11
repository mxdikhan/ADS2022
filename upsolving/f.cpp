#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

struct BST{
private:
	Node* _add(Node* root, int data) {
		if (!root){
			return new Node(data);
		}
		if (data > root->data) {
			root->right = _add(root->right, data);
		}else if (data < root->data) {
			root->left = _add(root->left, data);
		}
		return root;
	}

	int _find(Node* root, int tar, int cnt) {
		if (!root) return 0;
		cnt++;
		if (root->data == tar) return cnt;
		if (root->data > tar) return _find(root->left, tar, cnt);
		return _find(root->right, tar, cnt);
	}
public:
	Node * root;
	BST() {
		this->root = NULL;
	}

	void add(int data) {
		Node* newNode = _add(root, data);
		if (!root) root = newNode;
	}

	int find(int tar) {
	    int cnt = 0;
		return _find(root, tar, cnt);
	}
};
int main(){
    BST bst;
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        bst.add(k);
        sum += (k - bst.find(k) + 1);
    }
    cout << sum;
}