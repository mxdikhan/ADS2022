#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> v, int target)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		
		int mid = left + (right - left) / 2;
		if (target == v[mid]){
			return  true;
		}
		else if (target < v[mid])
		{
			right = mid - 1;
		}
		else if (target > v[mid])
		{
			left = mid + 1;
		}
	}
	return false; 
}



int main()
{

	vector<int> v ;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
	int target;
    cin>>target;

	if(binary_search(v, target)){
		cout<<"Yes";
	
	}
	else{
		cout<<"No";
	}

	return 0;
}