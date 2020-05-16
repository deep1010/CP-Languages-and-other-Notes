#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
vector<bool> get_primes(int n)
{
	std::vector<bool> isPrime;
	isPrime.assign(n+1,true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i*i <= n; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i*2; j <=n; j+=i)
			{
				isPrime[j]=false;
			}
		}
	}
	return isPrime;
}
vector<int> solve(int A)
{
	int n = A;
	std::vector<int> ans;
	if(n == 4)
	{
		ans.push_back(2);
		ans.push_back(2);
		cout<<"2 2"<<endl;
		return ans;
	}
	auto isPrime = get_primes(n);
	for (int i = 3; i <=n/2; i+=2)
	{
		if(isPrime[i] && isPrime[n-i])
		{
			ans.push_back(i);
			ans.push_back(n-i);
			cout<<i<<" "<<n-i<<endl;
			return ans;
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	auto x = solve(n);
	return 0;
}