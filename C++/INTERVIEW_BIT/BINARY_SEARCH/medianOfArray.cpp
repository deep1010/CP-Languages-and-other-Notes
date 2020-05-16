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
int solve(vi A, vi B)
{
	if (A.size() == 0 && B.size() > 0)
	{
		return B[B.size() / 2];
	}
	else if (B.size() == 0 && A.size() > 0)
	{
		return A[A.size() / 2];
	}
	else
	{
		int m = A.size();
		int n = B.size();
		int target = (m + n + 1) / 2;
		int low, high, mid;
		// printf("target %d\n",target);
		// assuming median is in A
		low = 0;
		high = m - 1;
		while (low <= high)
		{
			mid = (high + low) / 2;
			int inB = upper_bound(B.begin(), B.end(), A[mid]) - B.begin();
			// printf("low %d mid %d high %d inB %d\n",low,mid,high,inB);
			if (mid + inB == target - 1)
			{
				if(m+n%2==1)
					return A[mid];
				else
				{
					/* code */
				}
				
			}
			else if (mid + inB > target - 1)
			{
				high = mid - 1;
			}
			else
			{
				low = mid+1;
			}
		}

		// assuming median is in B
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			int inA = upper_bound(A.begin(), A.end(), B[mid]) - A.begin();
			// printf("low %d mid %d high %d inA %d\n",low,mid,high,inA);
			if (mid + inA == target)
			{
				if(m+n%2==1)
					return B[mid];
				else
				{
					
				}
			}
			else if (mid + inA > target)
			{
				high = mid - 1;
			}
			else
			{
				low = mid+1;
			}
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int m, n;
	cin >> m >> n;
	vi a(m, 0);
	vi b(n, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << solve(a, b) << endl;
	return 0;
}