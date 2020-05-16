#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
vector<int> solve(vector <int> A, vector <int> B)
{
	int i=0,j=0;
	std::vector<int> ans;
	while(i < A.size() && j < B.size())
	{
		if(A[i] < B[j])
			i++;
		else if (A[i] > B[j])
		{
			j++;
		}
		else
		{
			ans.push_back(A[i]);
			i++;
			j++;
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	int a,b,temp;
	vector<int> A;
	vector<int> B;
	cin>>a;
	for (int i = 0; i < a; ++i)
	{
		cin>>temp;
		A.push_back(temp);
	}
	cin>>b;
	for (int i = 0; i < b; ++i)
	{
		cin>>temp;
		B.push_back(temp);
	}
	vector<int> v = solve(A,B);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}