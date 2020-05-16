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
	int n = A.size();
	int i=0,j=n-1;
	int maxWater = 0;
	int curWater = 0;
	while(i < j)
	{
		// find cur ans
		curWater = (j-i)*(min(A[i],A[j]));
		maxWater = max(maxWater,curWater);
		//move pointers
		if(A[i] <= A[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return maxWater;
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