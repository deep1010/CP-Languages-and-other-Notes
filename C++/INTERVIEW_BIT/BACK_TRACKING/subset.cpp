#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	if(t.size()==0)
	{
		cout<<"Empty Vector\n";
		return;
	}
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
	if(n==0)
	{
		vector<int> empty;
		ans.push_back(empty);
		return ans;
	}
	vector<int> temp;
	temp.clear();
	for (int i = 1; i < n; i++)
	{
		temp.push_back(A[i]);
	}
	auto perms = solve(temp);
	auto copy = perms;
	vector< vector<int> > temp_2;
	for (int i = 0; i < perms.size(); i++)
	{
		perms[i].insert(perms[i].begin(),A[0]);
		temp_2.push_back(perms[i]);
	}
	temp_2.insert(temp_2.begin(),copy[0]);
	for (int i = 1; i < copy.size(); i++)
	{
		temp_2.push_back(copy[i]);
	}
	
	return temp_2;
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