#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(string A)
{
	int ans = 0;
	int n = A.size();
	for (int i = 0; i < A.size(); ++i)
	{
		ans += pow(26,(n-i-1))*(A[i]-'A'+1);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	string s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<solve(s)<<endl;
	}
	return 0;
}