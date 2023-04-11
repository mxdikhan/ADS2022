#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s){
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 and s[i] != s[j]){
			j = pi[j - 1];
        }
		if(s[i] == s[j]){
            j++;
        }
		pi[i] = j;
	}
	return pi;
}

int main(){
    string city1;
    cin >> city1;
    city1[0] = tolower(city1[0]);
    int n;
    cin >> n;
    vector<string> ans;
    int maxlength = 1;
    while(n--){
        string city;
        cin >> city;
        city[0] = tolower(city[0]);
        string p = city + "#" + city1;
        vector<int> pi = prefix_function(p);
        city[0] = toupper(city[0]);
        if(pi.back() > maxlength){
            maxlength = pi.back();
            ans.clear();
            ans.push_back(city);
        }
        else if(pi.back() == maxlength){
            ans.push_back(city);
        }
    }
    cout << ans.size() << endl;
    for(string city: ans){
        cout << city << endl;
    }
    return 0;
}