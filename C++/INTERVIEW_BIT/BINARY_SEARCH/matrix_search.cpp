#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector< vector <int> > A,int B)
{
	int m = A.size();
	if(m==0)
		return 0;
	int n = A[0].size();
	if(n==0)
		return 0;
	int low = 0;
	int high = m-1;
	int mid;
	int req_row = -1;
	while(low <=high)
	{
		mid = (high-low)/2 + low;
		if (A[mid][0] > B)
		{
			high = mid - 1;
		}
		else if (A[mid][0]<=B && A[mid][n-1]>=B)
		{
			return binary_search(A[mid].begin(),A[mid].end(),B);
		}
		else
		{
			low = mid +1;
		}
	}
	if (req_row == -1)
	{
		return 0;
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int m,n,x;
	cin>>m>>n;
	vector< vector <int> > v;
	std::vector<int> temp;
	for (int i = 0; i < m; ++i)
	{
		temp.clear();
		for (int j = 0; j < n; ++j)
		{
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	int to_search;
	cin>>to_search;
	cout<<solve(v,to_search)<<endl;
	return 0;
}