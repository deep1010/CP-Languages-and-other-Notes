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
		cout << t[i] << "\t";
	}
	cout << endl;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	vector<char> movieOrder = {'A', 'B', 'C', 'D'};
	vector<int> moviePrice = {25, 50, 75, 100};
	int t;
	cin >> t;
	ll totalProfit = 0;
	while (t--)
	{
		ll currentProfit = 0;
		vector<int> temp(4, 0);
		vector<vector<int>> movieCount(4, temp);
		int n;
		char movieID;
		int showtime;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> movieID >> showtime;
			movieCount[movieID - 'A'][(showtime / 3) - 1]++;
		}
		ll curProfit = -500;
		do
		{
			do
			{
				ll tempProfit = 0;
				for (int i = 0; i < 4; i++)
				{
					if (movieCount[movieOrder[i] - 'A'][i] == 0)
						tempProfit += -100;
					else
						tempProfit += movieCount[movieOrder[i] - 'A'][i] * moviePrice[i];
				}
				curProfit = max(curProfit, tempProfit);

			} while (next_permutation(movieOrder.begin(), movieOrder.end()));

		} while (next_permutation(moviePrice.begin(), moviePrice.end()));
		totalProfit += curProfit;
		cout << curProfit << endl;
	}
	cout << totalProfit << endl;
	return 0;
}