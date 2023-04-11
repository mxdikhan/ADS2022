#include <bits/stdc++.h>
using namespace std;

vector <int> v(1000);

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
struct BST{
private:
    Node* _insert(Node* root, int data){
        if(!root){
            return new Node(data);
        }
        if(data > root -> data){
            root -> right = _insert(root -> right, data);
        }
        else if(data < root -> data){
            root -> left = _insert(root -> left, data);
        }
        return root;
    }
    void _count(Node* root, int height){
        if(!root) return;
        Node *left = root -> left;
        Node *right = root -> right;
        while(left && right){
            v[height]++;
            height++;
            left = left -> left;
            right = right -> right;
        }
        height = 0;
        _count(root -> left, height);
        _count(root -> right, height);
    }
public:
    Node* root;
    BST(){
        this -> root = NULL;
    }

    void insert(int data){
        Node* newNode = _insert(root, data);
        if(!root) root = newNode;
    }

    void count(){
        int height = 0;
        _count(root, height);
    }
};
int main(){
    BST bst;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        bst.insert(k);
    }
    bst.count();
    for(int i = 0; i < n - 1; i++){
        cout << v[i] <<" ";
    }
}