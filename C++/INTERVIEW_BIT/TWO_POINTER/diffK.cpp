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
int solve(vi A, int B)
{
	int i=0;
	int j=0;
	int n = A.size();
	while(i < n && j < n)
	{
		if(A[i]-A[j] == B)
		{
			if(i!=j)
			{
				return true;
			}
			else
			{
				i++;
			}
		}
		else if(A[i] - A[j] > B)
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	return false;
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
	int k;
	cin >> k;
	cout << solve(v, k) << endl;

	return 0;
}
