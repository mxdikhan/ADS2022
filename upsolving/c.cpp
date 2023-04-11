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
    void add(int i, int val){
        a[i] += val;
        cout << sift_up(i) << endl;
    }
    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] <<" ";
        }
    }
};
int main(){
    Heap heap;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        heap.insert(num);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int pos, val;
        cin >> pos >> val;
        heap.add(pos, val);
    }
    heap.print();
}