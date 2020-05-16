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
bool isInt(double A)
{
	if (floor(A) == ceil(A))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		double a, b;
		double x, y;
		cin >> a >> b;
		x = (double)((double)(2.0*b - a)/(double)3.0);
		y = (double)((double)(2.0*a - b)/(double)3.0);
		// cout<<x<<y<<endl;
		if(x >= 0 && y>=0 && isInt(x) && isInt(y))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}