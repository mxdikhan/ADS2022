#include <bits/stdc++.h>
using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = INT_MAX;
        size = 0;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    int sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
        return i;
    }

    int counter(int i){
        int l = left(i);
        int r = right(i);
        int cnt = 0;
        while(l < size){
            if(a[l] < a[r]){
                cnt++;
            }
            i++;
            l = left(i);
            r = right(i);
        }
        return cnt;
    }
};

int main(){
    Heap hp;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        hp.insert(num);
    }
    cout << hp.counter(0);
}