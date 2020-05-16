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
	while (t--)
	{
		ll n, p;
		cin >> n >> p;
		vector<ll> coin(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
		}
		bool flag = true;
		int id=0;
		for (int i = 0; i < n; i++)
		{
			if (p % coin[i] != 0)
			{
				flag = false;
				id = i;
				break;
			}
		}
		if (flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES ");
			for (int i = 0; i < id; i++)
			{
				cout << "0 ";
			}
			cout << (p / coin[id]) + 1;
			for (int i = id + 1; i < n; i++)
			{
				cout << " 0";
			}
			cout << endl;
		}
	}

	return 0;
}