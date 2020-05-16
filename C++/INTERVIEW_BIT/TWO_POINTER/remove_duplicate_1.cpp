#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector<int> A)
{
	int cur_pos;
	if(A.size()<=1)
	{
		for (int i = 0; i < A.size(); i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
		return A.size();
	}
	else
	{
		cur_pos = 1;
		for (int i = 1; i < A.size(); i++)
		{
			if(A[i]!=A[i-1])
			{
				A[cur_pos++] = A[i];
			}
		}
		A.resize(cur_pos);
		for (int i = 0; i < A.size(); i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
		return A.size();
		
	}
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	cin>>n;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cout<<solve(input)<<endl;
	return 0;
}