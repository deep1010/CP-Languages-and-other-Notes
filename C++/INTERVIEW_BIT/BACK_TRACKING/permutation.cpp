#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
vector< vector<int> > solve(vector<int> A)
{
	int n = A.size();
	vector< vector<int> > ans;
	if(n==1)
	{
		ans.push_back(A);
		return ans;
	}
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		temp.clear();
		for (int j = 0; j < n; j++)
		{
			if(j!=i)
				temp.push_back(A[j]);
		}
		auto perms = solve(temp);
		for (int k = 0; k < perms.size(); k++)
		{
			perms[k].insert(perms[k].begin(),A[i]);
			ans.push_back(perms[k]);
		}
	}
	return ans;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	auto ans = solve(input);
	for (int i = 0; i < ans.size(); i++)
	{
	 	printVector(ans[i]);
	}
	
	return 0;
}