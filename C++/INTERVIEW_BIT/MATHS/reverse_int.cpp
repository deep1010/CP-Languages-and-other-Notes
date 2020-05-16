#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
ll to_int(string x)
{
	ll ans=0;
	for (int i = 0; i < x.size(); ++i)
	{
		ans += pow(10,i)*(x[i]-'0');
	}
	return ans;
}
int solve(int A)
{
	long long int n = A;
	if( A < 0)
	{
		n*=-1;
	}
	string x = to_string(n);
	n = to_int(x);
	if(n > (pow(2,32)-1))
	{
		// cout<<"here\n";
		return 0;
	}
	if (A < 0)
	{
		n*=-1;
	}
	return (int)n;
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	int n;
	cout<<INT_MAX<<endl;
	// cin>>n;
	// cout<<solve(n)<<endl;
	return 0;
}