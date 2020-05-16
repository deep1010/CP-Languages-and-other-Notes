#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector<int> A)
{
	int mn=A[0],mx = -1;
	for (int i = 0; i < A.size(); ++i)
	{
		mx = max(mx,A[i]);
		mn = min(mn,A[i]);
	}
	int range = mx - mn +1;
	int temp;
	vector<int> bucket;
	bucket.assign(range+1,0);
	for (int i = 0; i < A.size(); ++i)
	{
		temp = A[i] - mn;
		bucket[temp]=1;
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int temp;
	std::vector<int> input;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cout<<solve(input)<<endl;
	return 0;
}