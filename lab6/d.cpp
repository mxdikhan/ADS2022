#include<bits/stdc++.h>
using namespace std;

bool find_date(string &frst, string &scnd){
    string year_frst = frst.substr(6, 4);
    string year_scnd = scnd.substr(6, 4);
    if(year_frst.compare(year_scnd) != 0){
        if(year_frst > year_scnd){
            return true;
        }
        else{
            return false;
        }           
    }
    string month_frst = frst.substr(3, 2);
    string month_scnd = scnd.substr(3, 2);
    if (month_frst.compare(month_scnd) != 0){
        if(month_frst > month_scnd){
            return true;
        }
        else{
            return false;
        }
    }
 
    string day_frst = frst.substr(0, 2);
    string day_scnd = scnd.substr(0, 2);
    if(day_frst.compare(day_scnd) != 0){
        if(day_frst > day_scnd){
            return true;
        }
        else{
            return false;
        }
	}
	return false;
}

int partition(vector<string> &v, int low, int high){
    string pivot = v[high]; 
    int i = low; 
    for(int j = low; j <= high - 1; j++){
        if(find_date(pivot, v[j])){
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[high]);
    return i;
}
  
void quicksort(vector <string> &v, int k, int r){
    if (k < r) {
        int p = partition(v, k, r);
        quicksort(v, k, p - 1);
        quicksort(v, p + 1, r);
    }
}
  

int main(){
    int n;
    cin >> n;
    int f;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    quicksort(v, 0, v.size() - 1);
    for(int i = 0; i < n; i++){    
        cout << v[i] << '\n';
    }
}