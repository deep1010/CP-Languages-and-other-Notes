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
	int n, m;
	cin >> n >> m;
	vector<int> weight(n + 5, 0);
	vector<int> position(n + 5, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i + 1];
	}
	int curBook;
	ll finalSum = 0;
	for (int j = 1; j <= m; j++)
	{
		cin >> curBook;
		for (int i = 1; i <= n; i++)
		{
			if(position[i] > position[curBook])
			{
				finalSum += weight[i];
			}
		}
		position[curBook] = j;
	}
	cout << finalSum << endl;
	return 0;
}