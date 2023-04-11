#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *prev;
	Node *next;
	string val;
	Node(string _val)
	{
		prev = NULL;
		next = NULL;
		val = _val;
	}
};
int size;
Node *head = NULL;
Node *tail = NULL;

int cnt;
void clear()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
void add_back(string s)
{
	Node *newNode = new Node(s);
	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}
void add_front(string s)
{
	Node *newNode = new Node(s);
	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	size++;
}
bool empty()
{
	return size == 0;
}
void erase_front()
{
	if (size == 1) {
		clear();
		return;
	}
	Node *toDelete = head;
	head = head->next;
	head->prev = nullptr;
	size--;
	delete (toDelete);
	
}
void erase_back()
{
	if (size == 1) {
		clear();
		return;
	}
	Node *toDelete = tail;
	tail = tail->prev;
	tail->next = nullptr;
	size--;
	delete (toDelete);
	
}
string front()
{
	return head->val;
}
string back()
{
	return tail->val;
}

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "add_front")
		{
			string t;
			cin >> t;
			add_front(t);
			cout << "ok" << endl;
		}
		if (s == "add_back")
		{
			string t;
			cin >> t;
			add_back(t);
			cout << "ok" << endl;
		}
		if (s == "erase_front")
		{
			if (empty())
			{
				cout << "error" << endl;
			}
			else
			{
				cout << front() << endl;
				erase_front();
			}
		}
		if (s == "erase_back")
		{
			if (empty())
			{
				cout << "error" << endl;
			}
			else
			{
				cout << back() << endl;
				erase_back();
			}
		}
		if (s == "front")
		{
			if (empty())
			{
				cout << "error" << endl;
			}
			else
			{
				cout << front() << endl;
			}
		}
		if (s == "back")
		{
			if (empty())
			{
				cout << "error" << endl;
			}
			else
			{
				cout << back() << endl;
			}
		}
		if (s == "clear")
		{
			clear();
			cout << "ok" << endl;
		}
		if (s == "exit")
		{
			cout << "goodbye" << endl;
			break;
		}
		// cout << "hi" << endl;
	}
	return 0;
}