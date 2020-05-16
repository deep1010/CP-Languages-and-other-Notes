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
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << " ";
	}
	cout << "$";
}

vector<vi> solve(vector<int> A, int B)
{
	sort(A.begin(), A.end());
	int n = A.size();
	int a, b;
	vi t(2, 0);
	set<vi> ans;
	multimap<int, vi> sumMap;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			a = A[i];
			b = A[j];
			t[0] = i;
			t[1] = j;
			sumMap.insert(mp(a + b, t));
		}
	}
	int target;
	vi q(4, 0);
	vi temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			target = B - A[i] - A[j];
			if (sumMap.find(target) != sumMap.end())
			{
				for (auto itr = sumMap.find(target); itr != sumMap.end() && itr->first == target; itr++)
				{
					vi cur = itr->second;
					if (i != cur[0] && j != cur[0] && i != cur[1] && j != cur[1])
					{
						q[0] = A[i];
						q[1] = A[j];
						q[2] = A[cur[0]];
						q[3] = A[cur[1]];
						sort(q.begin(), q.end());
						ans.insert(q);
					}
				}
			}
		}
	}
	vector<vi> finalAns;
	for (auto it = ans.begin(); it != ans.end(); it++)
	{
		finalAns.push_back(*it);
	}
	return finalAns;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, target;
		cin >> n;
		cin >> target;
		vi input(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
		}
		auto ans = solve(input, target);
		if (ans.size() == 0)
		{
			cout << "-1\n";
		}
		else
		{
			for (auto i : ans)
			{
				printVector(i);
			}
			cout << endl;
		}
	}
	return 0;
}