#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
vector< vector<int> > solve(vector<int> A)
{
	vector< vector<int> > ans;
	vector<int> temp;
	set< vector<int> > s;
	temp.assign(3,-1);
	int n = A.size();
	int prev_a=-1,prev_b=-1,prev_c=-1;
	int a,b,c;
	long long int sum;
	bool to_loop = true;
	sort(A.begin(),A.end());
	for (int i = 0; i < n-2 && to_loop; i++)
	{
		int l = i+1, r = n-1;
		while(l < r)
		{
			cout<<i<<" "<<l<<" "<<r<<endl;
			a = A[i];
			b = A[l];
			c = A[r];
			sum = a+b+c;
			if(a > 0 && b > 0 && c > 0)
			{
				to_loop = false;
				break;
			}
			if( (sum == 0) )
			{
				if(!(a==prev_a && b==prev_b && c==prev_c))
				{
					prev_a = temp[0] = a;
					prev_b = temp[1] = b;
					prev_c = temp[2] = c;
					s.insert(temp);
				}
				l++;
				r--;
			}
			else if (sum > 0)
				r--;
			else if (sum < 0)
				l++;
			
		}
	}
	for(auto i = s.begin();i!=s.end();i++)
	{
		ans.push_back(*i);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	vector< vector<int> > ans = solve(input);
	cout<<"No of triplets "<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
	}
	cout<<endl;
	return 0;
}