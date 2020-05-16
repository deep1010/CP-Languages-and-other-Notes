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
int solve(vi A,int B)
{
	int count=0;
	int i=0,j=0;
	int n = A.size();
	while(i<n && j<n)
	{
		// printf("i %d j %d\n",i,j);
		if(A[j]!=B)
		{
			j++;
		}
		else if(A[i]==B)
		{
			count++;
			i++;
		}
		else
		{
			if(i > j)
			{
				swap(A[i],A[j]);
				i++;
				j++;
			}
			else
			{
				i++;
			}
			
		}
	}
	A.resize(A.size()-count);
    // printf("%d %d ",i,j);
    printVector(A);
    return A.size();
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n, t;
	cin >> n;
	vi v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cin>>t;
	cout << solve(v,t) << endl;
	return 0;
}