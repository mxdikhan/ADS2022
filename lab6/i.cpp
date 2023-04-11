#include <bits/stdc++.h>
using namespace std;

int part(string&a, int low, int high){
    int pivot = a[high];
    int i = low;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void quicksort(string&a, int k, int r){
    if(k < r){
        int p = part(a, k, r);
        quicksort(a, k, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main(){
    int f;
    string s;
    cin >> s;
    int k = s.length() - 1;
    quicksort(s, 0, k);
    cout << s;
}