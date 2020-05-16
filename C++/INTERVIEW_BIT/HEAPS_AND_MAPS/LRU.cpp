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

int main()
{
	cin.tie(0);
	cout.tie(0);
	int queryCount;
	int cacheSize;
	cin >> queryCount >> cacheSize;
	return 0;
}



// -1 -1 -1 -1 -1 3 -1 8 -1 7 7 -1 2 -1 8 7 2 7 -1 -1 12 -1 12 6 -1 -1
// -1 -1 -1 -1 -1 3 -1 8 -1 7 7 -1 2 -1 8 7 2 7 -1 -1 12 -1 12 6 -1 -1