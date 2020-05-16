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

int main()
{
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	vl A;
	vl B;
	while (t--)
	{
		int n;
		cin >> n;
		A.clear();
		B.clear();
		A.assign(n,0);
		B.assign(n,0);
		for(int i=0;i<n;i++)
		{
			cinl(A[i]);
		}
		for(int i=0;i<n;i++)
		{
			cinl(B[i]);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		ll sum =0;
		for (int i = 0; i < n; i++)
		{
			sum += min(A[i],B[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}