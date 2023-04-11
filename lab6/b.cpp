#include <bits/stdc++.h>
using namespace std;

int part(int a[], int low, int high){
    int pivot = a[high]; 
    int i = low; 
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot) {
            swap(a[i], a[j]);
            i++; 
        }
    }
    swap(a[i], a[high]);
    return i;
}
  
void quickSort(int a[], int k, int r){
    if(k < r){
        int p = part(a, k, r);
        quickSort(a, k, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main(){
    int n, m;
    int k;
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    quickSort(a, 0, n - 1);
    quickSort(b, 0, m - 1);
    if(n > m){
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(a[i] == b[j]){
                    cout << b[j] << " ";
                    a[i] =- 1;
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i] == b[j]){
                    cout << b[j] << " ";
                    break;
                }
            }
        }
    }
}