#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
int solve(vector<int> &A)
{
	int n = A.size();
	if (n == 0)
	{
		return -1;
	}
	else
	{
		int first, second, firstCount, secondCount;
		first = second = INT_MAX;
		firstCount = secondCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == first)
			{
				firstCount++;
			}
			else if (A[i] == second)
			{
				secondCount++;
			}
			else if (firstCount == 0)
			{
				firstCount = 1;
				first = A[i];
			}
			else if (secondCount == 0)
			{
				secondCount = 1;
				second = A[i];
			}
			else
			{
				firstCount--;
				secondCount--;
			}
		}
		firstCount = 0;
		secondCount = 0;
		for (int i = 0; i < n; i++)
		{
			if(A[i] == first)
			{
				firstCount++;
			}
			else if(A[i]==second)
			{
				secondCount++;
			}
		}
		if(firstCount > n/3)
		{
			return first;
		}
		if(secondCount > n/3)
		{
			return second;
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int temp;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	cout << solve(input) << endl;
	return 0;
}