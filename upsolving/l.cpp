#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

struct BST {
private:
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



public:
  Node *root;
  BST() {
    this->root = NULL;
  }
  
  int LeafCount(Node* node){
	if(node == NULL)	
	    return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;		
	else
		return LeafCount(node->left)+LeafCount(node->right);
    }
    
    void count(){
        cout << LeafCount(root);
    }

  void insert(int val) {
    Node* newNode = _insert(root, val);
    if (!root) root = newNode;
  }

};

int main(){
    BST bst;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        bst.insert(x);
    }
    bst.count();
}