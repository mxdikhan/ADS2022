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

	int get(int index)
	{
		if (index < 0 || index >= this->size)
		{
			return -1;
		}
		ListNode *cur = this->head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val)
	{
		ListNode *newNode = new ListNode(val);
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode->next = this->head;
			this->head = newNode;
		}
		this->size++;
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

	void addAtIndex(int index, int val)
	{
		if (index < 0 || index > this->size)
		{
			return;
		}
		if (index == 0)
		{
			this->addAtHead(val);
		}
		else if (index == this->size - 1)
		{
			this->addAtTail(val);
		}
		else
		{
			ListNode *newNode = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
			this->size++;
		}
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

	int solve(int b) {
		int mini = 1e9;
		int ind = 0;
		int answer = 0;
		ListNode *cur = head;
		while (cur) {
			// mini = min(mini, abs(cur->val - b));
			if (mini > abs(cur->val - b)) {
				mini = abs(cur->val - b);
				answer = ind;
			}
			ind++;
			cur = cur->next;
		}
		return answer;
	}
};

int main()
{
	LinkedList ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		ll.addAtTail(x);
	}
	int b;
	cin >> b;
	cout << ll.solve(b);
	return 0;
}