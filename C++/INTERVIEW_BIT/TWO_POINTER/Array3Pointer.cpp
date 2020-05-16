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
int solve(vi A, vi B, vi C)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	int max_ans = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(A[i] - C[k])));
	int cur_ans;
	while (i < A.size() && j < B.size() && k < C.size())
	{
		// printf("i %d j %d k %d\n",i,j,k);
		// update cur_ans;
		cur_ans = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(A[i] - C[k])));
		max_ans = min(max_ans,cur_ans);
		if (A[i] <= B[j] && A[i] <= C[k])
			i++;

		else if (B[j] <= A[i] && B[j] <= C[k])
			j++;

		else if (C[k] <= B[j] && A[i] >= C[k])
			k++;
	}
	return max_ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi a(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> n;
	vi b(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cin >> n;
	vi c(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	cout << solve(a, b, c) << endl;

	return 0;
}