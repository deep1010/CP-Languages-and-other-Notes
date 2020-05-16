#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
string solve(int A)
{
	string ans;
	if(A <= 26)
	{
		ans += 'A' + A -1;
		return ans;
	}
	int temp;
	int len = 0;
	temp = 0;
	for (int i = 0; ; ++i)
	{
		temp+= pow(26,i);
		if (temp > A)
		{
			len = i;
			break;
		}
	}
	cout<<len<<" ";
	for (int i = 0; i <len; ++i)
	{
		A -= pow(26,i);
	}
	cout<<A<<endl;
	for (int i = len-1; i >=0; --i)
	{
		temp = A/pow(26,i);
		ans += 'A' + temp;
		A-= temp*pow(26,i);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<"\n\n";
	}
	return 0;
}