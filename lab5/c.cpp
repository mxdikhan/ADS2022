#include <iostream>

using namespace std;

struct Heap {
private:
    int* arr;
    int capacity;
    int length;

    void _add(int val) {
        arr[length] = val;
        length++;
        heap_up(length - 1);
    }

    void heap_up(int i) {
        if(i > 0) {
            int p_pos = (i - 1) / 2;
            if(arr[i] > arr[p_pos]) {
                swap(arr[i], arr[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max_pos = i;
        if(l < length and arr[max_pos] < arr[l]) max_pos = l;
        if(r < length and arr[max_pos] < arr[r]) max_pos = r;
        if(max_pos != i) {
            swap(arr[i], arr[max_pos]);
            heap_down(max_pos);
        }
    }

    void _cut_max() {
        if(arr[0] - 1 > 0) {
            arr[0] = arr[0] - 1;
        }
        else {
            arr[0] = arr[length - 1];
            length = max(length - 1, 0);
        }
        heap_down(0);
    }

public:
    Heap(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }

    void add(int val) {
        _add(val);
    }

    int cut_max() {
        int res = arr[0];
        _cut_max();
        return res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Heap heap(100001);
    while(n--) {
        int val;
        cin >> val;
        heap.add(val);
    }
    long long maxSum = 0;
    while(k--) {
        maxSum += heap.cut_max();
    }
    cout << maxSum;
}



