#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
vector<int> solve(vector<int> A)
{
	int n=A.size();
	int temp_count = 1;
	int prev_id = 1;
	for (int i = 1; i < n; i++)
	{
		if(A[i] == A[i-1])
			temp_count++;
		else
		{
			if(temp_count >=2)
			{
				A[prev_id++] = A[i-1];
				A[prev_id++] = A[i];
			}
			else
			{
				A[prev_id++] = A[i];
			}
			temp_count = 1;
		}
	}
	if(temp_count >=2)
	{
		A[prev_id++] = A[n-1];
	}
	A.resize(prev_id);
	return A;
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
	vector<int> ans = solve(input);
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	cout<<ans.size()<<endl;
	
	return 0;
}