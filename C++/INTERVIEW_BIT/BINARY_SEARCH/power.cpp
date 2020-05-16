#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(int A,int B,int C)
{
	long long int ans=1;
	long long int temp=A;
	while(B)
	{
		if (B%2==1)
		{
			ans=(ans*temp)%C;
		}

		temp = (temp*temp)%C;		
		B/=2;
	}
	ans = ans%C;
	if (ans < 0)
		ans = (ans + C)%C;
	return (int)ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int x,n,d;
	cin>>x>>n>>d;
	cout<<solve(x,n,d)<<endl;
	return 0;
}