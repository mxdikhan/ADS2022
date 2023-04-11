#include <iostream>

using namespace std;

struct Heap {
private:
    long long* arr;
    int capacity;
    int length;
    long long cnt;

    void _add(long long val) {
        arr[length] = val;
        length++;
        heap_up(length - 1);
    }

    void heap_up(int i) {
        if(i > 0) {
            int p_pos = (i - 1) / 2;
            if(arr[i] < arr[p_pos]) {
                swap(arr[i], arr[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int min_pos = i;
        if(l < length and arr[l] < arr[min_pos]) min_pos = l;
        if(r < length and arr[r] < arr[min_pos]) min_pos = r;
        if(min_pos != i) {
            swap(arr[i], arr[min_pos]);
            heap_down(min_pos);
        }
    }

    void _cut_min() {
        arr[0] = arr[length - 1];
        length = max(length - 1, 0);
        heap_down(0);
    }

public:
    Heap(int capacity) {
        arr = new long long[capacity];
        this->capacity = capacity;
        length = 0;
        cnt = 0;
    }

    void add(long long val) {
        _add(val);
    }

    long long cut_min() {
        long long res = arr[0];
        _cut_min();
        return res;
    }

    long long getNumOfOperations(long long m) {
        while(length > 1) {
            long long a = cut_min();
            long long b = cut_min();
            // cout << a << " " << b << " " << a + 2 * b << endl;
            if(a >= m) return cnt;
            add(a + 2 * b);
            cnt++;
            // if(a + 2 * b >= m) return cnt;
        } 
        return -1;
    }
};

int main() {
    int n;
    long long m;
    cin >> n >> m;
    Heap heap(1000001);
    while(n--) {
        long long val;
        cin >> val;
        heap.add(val);
    }
    cout << heap.getNumOfOperations(m);
}