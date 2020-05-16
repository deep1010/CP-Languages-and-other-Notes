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

	int k;
	cin >> k;
	string number;
	cin >> number;
	int n = number.size();
	vector<int> oneCount(n, 0);
	oneCount[0] = number[0] - '0';

	for (int i = 1; i < n; i++)
	{
		oneCount[i] = oneCount[i - 1] + number[i] - '0';
	}
	// printVector(oneCount);
	vector<int> start(oneCount[n - 1] + 1, -1);
	vector<int> end(oneCount[n - 1] + 1, -1);
	start[oneCount[0]] = 0;
	for (int i = 1; i < n; i++)
	{
		if (oneCount[i] != oneCount[i - 1])
		{
			start[oneCount[i]] = i;
		}
	}
	end[oneCount[n - 1]] = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (oneCount[i] != oneCount[i + 1])
		{
			end[oneCount[i]] = i;
		}
	}
	// printVector(start);
	// printVector(end);
	ll finalSum = 0;
	ll maxcount = oneCount[n - 1];

	for (int i = 0; i < n; i++)
	{
		int required = -1;
		if (number[i] == '0')
		{

			required = oneCount[i] + k;
			if (required > maxcount)
				break;
			// cout << "\n-----------HERE0-----------\n";
			// cout << "i " << i << endl;
			// cout << "required " << required << endl;
			if (k == 0)
			{
				// cout << "c " << end[required] - i + 1 << endl;
				finalSum += end[required] - i + 1;
			}
			else
			{
				finalSum += (end[required] - start[required] + 1);
			}
		}
		else if (number[i] == '1' && k != 0)
		{
			required = oneCount[i] + k - 1;
			if (required > maxcount)
				break;
			else
			{
				// cout << "\n-----------HERE1-----------\n";
				// cout << "i " << i << endl;
				// cout << "required " << required << endl;
				// cout << "c " << (end[required] - start[required] + 1) << endl;
				finalSum += (end[required] - start[required] + 1);
			}
		}
	}
	cout << finalSum << endl;
	return 0;
}