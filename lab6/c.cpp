#include <bits/stdc++.h>
using namespace std;

int part(int a[], int low, int high){
    int pivot = a[high]; 
    int i = low; 
    for(int j = low; j <= high - 1; j++){
        if (a[j] < pivot){
            swap(a[i], a[j]);
            i++;
            int i;
            
        }
    }
    swap(a[i], a[high]);
    return i;
}
  
void quickSort(int a[], int l, int r){
    if (l < r) {
        int p = part(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n -1 );
    int min = 1152151;
    for(int i = 0; i < n; i++){
        if(abs (a[i + 1] - a[i]) < min){
            min = abs(a[i + 1] - a[i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(abs(a[i + 1] - a[i] == min)){
            cout << a[i] <<" "<< a[i + 1] << " ";
        }
    }
}