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
vi getNextGreaterArray(vl &A)
{
	int n = A.size();
	vi ans(n,-1);
	stack<int> s;
	s.push(0);
	int i = 1;
	while( i < n)
	{
		if(A[i] <= A[s.top()])
		{
			s.push(i);
		}
		else
		{
			while( !s.empty() && A[i] > A[s.top()])
			{
				ans[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		i++;
		
	}
	return ans;
}

vi getNextSmallerArray(vl &A)
{
	int n = A.size();
	vi ans(n,-1);
	stack<int> s;
	s.push(0);
	int i = 1;
	while( i < n)
	{
		if(A[i] >= A[s.top()])
		{
			s.push(i);
		}
		else
		{
			while( !s.empty() && A[i] < A[s.top()])
			{
				ans[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		i++;
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vl A(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vi F = getNextGreaterArray(A);
	vi G = getNextSmallerArray(A);
	printVector(A);
	printVector(F);
	printVector(G);
	for (int i = 0; i < n; i++)
	{
		if(F[i] == -1 || G[F[i]]==-1)
		{
			cout<<"-1 ";
		}
		else
		{
			cout<<A[G[F[i]]]<<" ";
		}
	}
	cout<<endl;
	return 0;
}