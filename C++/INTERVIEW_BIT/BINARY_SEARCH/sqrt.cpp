#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(int A)
{
	int low=1,high=A;
	long long int mid = (high - low)/2 + low;
	while(low<high)
	{
		// cout<<"low\tmid\thigh\n";
		mid = (high - low)/2 + low;
		// cout<<low<<"\t"<<mid<<"\t"<<high<<endl;
		if(mid*mid > A)
			high = mid;
		else if (mid*mid < A)
		{
			if((mid+1)*(mid+1) > A)
				return (int)mid;
			else
				low = mid+1;
		}
		else if(mid*mid==A)
			return (int)mid;
	}
	return (int)mid;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}