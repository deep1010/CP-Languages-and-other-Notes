#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define cin(a) scanf("%d", &a)
#define cinl(a) scanf("%lld", &a)
#define b begin
#define e end
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long int>
#define INF IMT_MAX - 100
#define pb push_ back
#define mp make_pair

template <typename T>
void printVector(const T &t)
{
	if (t.size() == 0)
	{
		cout << "Empty Vector\n";
		return;
	}
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << " ";
	}
	cout << endl;
}
int solve(vi A)
{
	int ans = 0;
	int mod = 1000000007;
	sort(A.begin(), A.end(),greater<int>());
	printVector(A);
	int i,j,k;
	int n = A.size();
	for ( i = 0; i < n-2; i++)
	{
		j = i+1;
		k = n-1;
		while(j < k)
		{
			if(A[j] + A[k] > A[i])
			{
				ans = (ans + k-j)%mod;
				j++;
			}
			else
			{
				k--;
			}

		}
	}
	return ans % mod;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << solve(v) << endl;
	return 0;
}