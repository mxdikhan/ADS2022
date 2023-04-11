#include <bits/stdc++.h>
using namespace std;

int part(int a[], int low, int high){
    int pivot = a[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(a[j] > pivot){
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}
void quicksort(int a[], int k, int r){
    if(k < r){
        int p = part(a, k, r);
        quicksort(a, k, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main(){
    int n, m;
    int x;
    cin >> n >> m;
    int a[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        quicksort(a[i], 0, n - 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[j][i]<<" ";
        }
        cout << endl;
    }
    return 0;
}