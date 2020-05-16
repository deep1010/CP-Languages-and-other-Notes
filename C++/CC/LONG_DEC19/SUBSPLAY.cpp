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
	vi prev;
	vi dp;
	while (t--)
	{
		prev.clear();
		dp.clear();

		int n;
		cin >> n;
		string s;
		cin >> s;

		prev.assign(26, -1);
		dp.assign(n, 0);

		prev[s[0] - 'a'] = 0;

		for (int i = 1; i < n; i++)
		{
			if (prev[s[i] - 'a'] == -1) // occuring for first time;
			{

				if (dp[i - 1] == 0) // all char distinct till now
					dp[i] = 0;

				else // answer does exist before
					dp[i] = dp[i - 1] + 1;
			}

			else
				dp[i] = max(dp[i - 1] + 1, prev[s[i] - 'a'] + 1); // check for last index of character

			prev[s[i] - 'a'] = i;
		}

		cout << dp[n - 1] << endl;
	}
	return 0;
}