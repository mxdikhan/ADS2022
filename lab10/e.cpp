#include <iostream> 
using namespace std; 
 
int main(){ 
    int k, x, a;
    int cnt;
    cin >> k >> x; 
    int arr[k][k]; 
    for(int i = 0 ; i < k ; i++){ 
        for(int j = 0; j < k ;j++){ 
            int val; cin >> val; 
            arr[i][j] = val; 
        } 
    } 
    for(int i = 0 ; i < x; i++){ 
        int a, b, c; 
        cin >> a >> b >> c; 
        a -= 1; b -=1; c -=1; 
        if(arr[a][b] == 1 && arr[b][a] == 1 && arr[c][a] == 1 && arr[a][c] == 1 && arr[b][c] == 1 && arr[c][b] == 1){ 
            cout << "YES" << endl; 
        } 
        else{ 
            cout << "NO" << endl; 
        } 
    } 
 
    return 0; 
}

