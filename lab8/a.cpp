#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

string hash_f(string s, int op = 1e9 + 7, int enl = 11) { 
	ll p = 1;  
	ll res = 0;     
	for (int i = 0; i < s.size(); i++) {
		res = (res + ((s[i] - 47) * p) % op) % op; 
		p = (p * enl) % op;   
	}
	return to_string(res); 
}

int main() {

	ll n;
	cin >> n;
    int k;
    int f;
	vector<string> vec;
	
	for (ll i = 0; i < n * 2; i++) { 
		string s;
		cin >> s;
		vec.push_back(s);
	}
	
	for (auto i : vec) {
		string h = hash_f(i);
		if (find(vec.begin(), vec.end(), h) != vec.end()) {
			printf("Hash of string \"%s\" is %s\n", i.c_str(), h.c_str());
		}
	}
	return 0;
}