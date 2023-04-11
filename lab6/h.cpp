#include <bits/stdc++.h>
using namespace std;

int part(vector <char>& a, int low, int high){
    int pivot = a[high];
    int i = low;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void quicksort(vector <char>& a, int p, int k){
    if(p < k){
        int p = part(a, p, k);
        quicksort(a, p, p - 1);
        quicksort(a, p + 1, k);
    }
}

int main(){
    int n;
    cin >> n;
    char c;
    vector <char> v;
    
    while(n--){
        cin >> c;
        v.push_back(c);
    }

    quicksort(v, 0, v.size() - 1);
    char tar;
    cin >> tar;
    if(v[v.size() - 1] <= tar){
        cout << v[0];
    }
    else{
        for(int i = 0; i < v.size(); i++){
            if(v[i] > tar){
                cout << v[i];
                break;
            }
        }
    }
    
    return 0;
}