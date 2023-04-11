#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
private:
    long long* arr;
    int capacity;
    int length;
    long long cost;

    void heap_up(long long i){
        if(i > 0){
            int p_pos = (i - 1) / 2;
            if(arr[i] < arr[p_pos]){
                swap(arr[i], arr[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void _add(long long val) {
        arr[length] = val;
        length++;
        heap_up(length - 1);
    }

    void heap_down(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if(l < this->length and arr[min_pos] > arr[l]) min_pos = l;
        if(r < this->length and arr[min_pos] > arr[r]) min_pos = r;
        if(i != min_pos) {
            swap(arr[i], arr[min_pos]);
            heap_down(min_pos);
        }
    }

    void _cut_min(){
        arr[0] = arr[length - 1];
        length = max(length - 1, 0);
        heap_down(0);
    }

public:
    Heap(int capacity) {
        arr = new long long[capacity];
        this->capacity = capacity;
        length = 0;
        cost = 0;
    }

    long long cut_min(){
        long long res = arr[0];
        _cut_min();
        return res;
    }

    void add(long long val){
        _add(val);
    }

    void print(){
        for(int i = 0; i < length; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    long long mergeCost() {
        while(length != 1) {
           long long a = cut_min();
           long long b = cut_min();
        //    cout << a << " " << b << endl;
           cost += a + b;
           add(a + b);
        }
        // print();
        return cost;
    }
};

int main() {
    Heap h(200001);
    int n;
    cin >> n;
    while(n--) {
        long long val;
        cin >> val;
        h.add(val);
    }
    // h.print();
    cout << h.mergeCost();
}