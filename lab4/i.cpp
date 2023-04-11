#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int val=0,mult=0;
	Node* left;
	Node* right;

	Node(int val,int mult) {
		this->val = val;
        this->mult+=mult;
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
			return new Node(val,1);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
        else{
            cur->mult++;
            return cur;
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

    Node* _remove(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return nullptr;
			} else if (cur->left && !cur->right) {
				Node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				Node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = _rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
				// cur->val = _leftmost(cur->right);
				// cur->right = _remove(cur->right, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}


	int _getSize(Node* node) {
		if (!node) return 0;
		return _getSize(node->left) + _getSize(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
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

    void remove(int target) {
		root = _remove(root, target);
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

    int solve(Node* node, int& k){
        if(!node){
            return k;
        }
        if(node->left!=nullptr && node->right!=nullptr){
            k++;
        }
            solve(node->left,k);
            solve(node->right,k);
            return k;
        
    }
   
	void remove2(int val){
        if(this->search(val)->mult<=0){
            this->remove(val);
        }
        else{
            this->search(val)->mult-=1;
        }
    }

    int getMult(int val){
        return this->search(val)->mult;
    }

};


int main() {
BST bst;
int n, node;
cin>>n;
string s;
for (int i = 0; i < n; i++)
{
 cin>>s>>node;
 if(s=="insert"){
    bst.insert(node);
 }
 else if(s=="delete"){
    bst.remove2(node);
 }
 else if(s=="cnt"){
    if(bst.search(node)==nullptr){
        cout<<"0"<<endl;
    }
    else{
        cout<<bst.getMult(node)<<endl;
    }
 }
}

	return 0;
}