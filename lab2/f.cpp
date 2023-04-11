#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; // NULL, if this doesnt work
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
		this->next = next;
	}
};


struct LinkedList {
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addAtHead(int val) {
		ListNode *newNode = new ListNode(val);
		if (this->size == 0) {
			this->head = newNode;
			this->tail = newNode;
		} else {
			newNode->next = this->head;
			this->head = newNode;
		}
		this->size++;
	}

	void addAtTail(int val) {
		ListNode *newNode = new ListNode(val);
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		} else {
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}

	void addAtIndex(int index, int val) {
		if (index < 0 || index > this->size) {
			return;
		}
		if (index == 0) {
			this->addAtHead(val);
		} else if (index == this->size) {
			this->addAtTail(val);
		} else {
			ListNode *newNode = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
			this->size++;
		}
	}

	void printLL() {
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main()
{

	int n;
    cin>>n;
    LinkedList ll;
    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        ll.addAtTail(x);
    }
     int val;
     cin>>val;
     int index;
     cin>>index;
    ll.addAtIndex(index,val);
    ll.printLL();
    
    
	return 0;
}