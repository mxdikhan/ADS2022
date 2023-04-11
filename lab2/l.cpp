#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = NULL; // NULL, if this doesnt work
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
		this->next = next;
	}
};

struct LinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList()
	{
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}


	void addAtTail(int val)
	{
		ListNode *newNode = new ListNode(val);
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}

	
	

	void printLL()
	{
		ListNode *cur = this->head;
		while (cur != NULL)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}

};

int main()
{
	LinkedList * ans = new LinkedList();
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans->addAtTail(a);
    }
    int sumAns = ans->head->val;
    int sum = 0;
    while(ans->head){
        sum += ans->head->val;
        if(sum > sumAns)sumAns = sum;
        if(sum < 0)sum = 0;
        ans->head = ans->head->next;
    }
    cout << sumAns;
    return 0;
}