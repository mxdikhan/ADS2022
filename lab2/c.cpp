#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

struct DoublyLinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	DoublyLinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_back(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			temp->prev = this->tail;
			this->tail = temp;
		}
	}

	void removeEveryKthNode(int k = 2)
	{
		ListNode *cur = head;

		int index = 1;
		while (cur != nullptr)
		{
			if (index % k == 0)
			{

				if (cur->next == nullptr)
				{
					cur->prev->next = nullptr;
				}
				else
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
				}
			}
			index++;
			cur = cur->next;
		}
	}

	void print()
	{
		ListNode *cur = head;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << '\n';
	}
};

int main()
{
	int n, m;
	cin >> n;
	DoublyLinkedList dll;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		dll.push_back(m);
	}

	dll.removeEveryKthNode();
	dll.print();

	return 0;
}