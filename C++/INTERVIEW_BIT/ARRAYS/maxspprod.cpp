#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxi(ll a, ll b){ return (a > b)?a:b;}
ll mini(ll a, ll b){ return (a < b)?a:b;}
ll get_ans(vector<int> A)
{
	vector<ll> leftSpecial;
	vector<ll> rightSpecial;
	int n = A.size();
	leftSpecial.assign(n,-1);
	rightSpecial.assign(n,-1);
	stack<int> s;
	s.push(0);
	for (ll i = 1; i < n; ++i)
	{
		if(A[i] <= A[s.top()])
			s.push(i);
		else
		{
			while(!s.empty() && A[i] > A[s.top()])
			{
				rightSpecial[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	while(!s.empty())
	{
		s.pop();
	}

	s.push(n-1);
	for(ll i=n-2;i>=0;i--)
	{
		if(A[i] <= A[s.top()])
			s.push(i);
		else
		{
			while(!s.empty() && A[i] > A[s.top()])
			{
				leftSpecial[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	ll max_ans = -1;
	for (int i = 0; i < n; ++i)
	{
		max_ans = maxi((leftSpecial[i]+1)*(rightSpecial[i]+1),max_ans);
	}
	return max_ans;

}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,temp;
    cin>>n;
    vector<int> input;
    for(int i=0;i< n;i++)
    {
    	cin>>temp;
    	input.push_back(temp);
    }
    cout<<get_ans(input)<<endl;
    return 0;
}