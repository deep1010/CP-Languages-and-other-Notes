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
	sort(A.begin(), A.end());
	int i, j, k, n;
	n = A.size();
	if (n < 3)
	{
		return -1;
	}

	int a, b, c;
	int cursum;
	int min_diff = abs(A[0] + A[1] + A[2] - B);
	int best_sum = A[0] + A[1] + A[2];
	i = 0;
	while (i < n - 2)
	{
		a = A[i];
		j = i + 1;
		k = n - 1;
		while (j < k)
		{
			b = A[j];
			c = A[k];
			cursum = a + b + c;
		//	printf("i %d j %d k %d\n",i,j,k);
		//	printf("min_diff %d cursum %d best_sum %d\n",min_diff,cursum,best_sum);
			if (abs(B - cursum) < min_diff)
			{
				
				min_diff = abs(B - cursum);
				best_sum = cursum;
			}
			if (cursum > B)
			{
				k--;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return best_sum;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi v(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int t;
	cin >> t;
	cout << solve(v, t) << endl;
	return 0;
}