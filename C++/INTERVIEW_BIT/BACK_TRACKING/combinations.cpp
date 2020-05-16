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
vector< vector<int> > combinations(vector<int> A, int K)
{
	// printVector(A);
	vector< vector<int> > ans;
	vector<int> temp;
	temp.clear();
	if(K==0 || A.empty())
	{
		ans.push_back(temp);
		return ans;
	}
	else
	{
		int n = A.size();
		for (int i = 0; i < n-K+1; i++)
		{
			temp.clear();
			for (int j = i+1; j < n; j++)
			{
				temp.push_back(A[j]);
			}
			auto response = combinations(temp,K-1);
			for (int k = 0; k < response.size();k++)
			{
				response[k].insert(response[k].begin(),A[i]);
				ans.push_back(response[k]);
			}
		}
		return ans;
	}
}
vector< vector<int> > solve(int n, int k)
{
	vector<int> array;
	for (int i = 0; i < n; i++)
	{
		array.push_back(i+1);
	}
	return combinations(array,k);
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	auto response = solve(n,k);
	for (auto it = response.begin();it!=response.end();it++)
	{
		printVector(*it);
	}
	return 0;
}