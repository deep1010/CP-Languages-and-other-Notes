#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector<int> A)
{
	int n = A.size();
	stack<int> s;
	// stack<int> back;

	vector<int> left;
	vector<int> right;

	left.assign(n,-1);
	right.assign(n,-1);
	s.push(0);
	int max_ans = -1;
	for (int i = 1; i < n; i++)
	{
		if(A[i] > A[s.top()])
		{
			s.push(i);
		}
		else
		{
			while( s.size() > 0 && A[i] < A[s.top()])
			{
				right[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	while(s.size() > 0)
	{
		s.pop();
	}

	s.push(n-1);
	for (int i = n-2; i >= 0; i--)
	{
		if(A[i] > A[s.top()])
		{
			s.push(i);
		}
		else
		{
			while( s.size() > 0 && A[i] < A[s.top()])
			{
				left[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cout<<left[i]<<" ";
	// }
	// cout<<endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	cout<<right[i]<<" ";
	// }
	// cout<<endl;
	int l,r;
	for (int i = 0; i < n; i++)
	{
		if(right[i]==-1)r=n;
		else r=right[i];

		l=left[i];

		cout<<A[i]<<" "<<l<<" "<<r<<" "<<(r-l-1)*A[i]<<endl;
		max_ans = max(max_ans,(r-l-1)*A[i]);
	}
	
	return max_ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> input;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cout<<solve(input)<<endl;
	
	return 0;
}