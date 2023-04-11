#include <bits/stdc++.h>
using namespace std;


bool check(pair<int, int> & v1, pair<int, int> & v2){
    if(v1.second == v2.second){
        return v1.first > v2.first;
    }else return v1.second > v2.second;
}

struct ListNode{
    int val;
    int cnt;
    ListNode * next;
    ListNode(){
        this->val = 0;
        this->next = NULL;
        this->cnt = 1;
    }
    ListNode(int val){
        this->val = val;
        this->next = NULL;
        this->cnt = 1;
    }
};

struct LinkedList{
    ListNode * head;
    int size;
    LinkedList(){
        this->head = NULL;
        this->size = 0;
    }
    void AddatTail(int val){
        if(!this->head){
            this->head = new ListNode(val);
            this->size++;
        }
        else {
            ListNode *cur = this->head;
            while(cur->next){
                if(cur->val == val){
                    cur->cnt++;
                    return;
                }
                cur = cur->next;
            }
            if(cur->val == val){
                    cur->cnt++;
                    return;
            }
            cur->next = new ListNode(val);

        }
    }
    void mode(){
        ListNode * cur = this->head;
        vector <pair<int, int> > v;
        while(cur){
            v.push_back(make_pair(cur->val, cur->cnt));
            cur = cur->next;
        }
        sort(v.begin(), v.end(), check);
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == v[0].second)cout << v[i].first << " ";
        }
    }
};

int main() {
    LinkedList * ans = new LinkedList();
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        ans->AddatTail(m);
    }
    ans->mode();
}