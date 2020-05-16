#include <bits/stdc++.h>
using namespace std;

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
typedef long long int ll;
ll mod = 1000000007;
vector<ll> dp;
vector< vector<ll> > nck;

ll getLeftCount(int n)
{
	if(n==1)
		return 0;
	ll height  = log2(n);
	ll lastRowCount = n + 1 - (1<<(height));
	ll lastRowCapacity = 1<<(height);

	if(lastRowCount >= lastRowCapacity/2)
	{
		return lastRowCapacity -1;
	}
	else
		return lastRowCount + (lastRowCapacity/2) - 1;

}
ll nCk(int n,int k)
{
	if(k > n)
		return 0;
	if(n<=1 || k==0)
		return 1;
	if(nck[n][k]!=-1)
		return nck[n][k];
	else
	{
		ll temp = nCk(n-1,k-1)%mod;
		temp = (temp + nCk(n-1,k))%mod;
		nck[n][k] = temp % mod;
		return nck[n][k];
	}
}
ll solveHelper(int n)
{
	if(n<=1)
	{
		dp[n] = 1;
		return dp[n];
	}
	if(dp[n]!=-1)
		return dp[n];
	else
	{
		ll leftCount = getLeftCount(n);
		ll combinations = nCk(n-1,leftCount) % mod;
		ll temp = combinations;
		temp = (temp * solveHelper(leftCount)%mod)%mod;
		temp = (temp * solveHelper(n-1-leftCount)%mod)%mod;
		// cout<<"n leftCount combinations:\t"<<n<<" "<<leftCount<<" "<<combinations<<endl;
		// dp[n] = (combinations%mod) * (solveHelper(leftCount)%mod) * (solveHelper(n-1-leftCount)%mod);
		dp[n] = temp % mod;
		return temp;
	}
}
int solve(int n)
{
	dp.assign(n+2,-1);
	nck.assign(n+2,dp);
	return (int)solveHelper(n);
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