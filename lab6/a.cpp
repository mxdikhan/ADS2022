#include <bits/stdc++.h>
using namespace std;

int part(char a[], int low, int high){
    char pivot = a[high];
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

void quicksort(char a[], int k, int r){
    if(k < r){
        int p = part(a, k, r);
        quicksort(a, k, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            cout << a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u'){
            cout << a[i];
        }
    }
}