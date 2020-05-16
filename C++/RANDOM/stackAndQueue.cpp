#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define cin(a) scanf("%d",&a)
#define cinl(a) scanf("%lld",&a)
#define b begin
#define e end
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long int>
#define INF IMT_MAX-100
#define pb push_ back
#define mp make_pair


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

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >>n >>k;
	vector<int> array(n,0);
	vector<ll> prefixSum(n+1,0);
	for(int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		prefixSum[i] = prefixSum[i-1] + array[i-1];
	}
	// printVector(prefixSum);
	ll maxSum = -1;
	for (int x = 1; x <= k; x++)
	{
		maxSum = max(maxSum,prefixSum[x] + prefixSum[n] - prefixSum[n-k+x]);
	}
	cout<<maxSum<<endl;
	
	return 0;
}