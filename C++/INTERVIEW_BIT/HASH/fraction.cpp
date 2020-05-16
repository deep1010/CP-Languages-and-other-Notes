#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
string solve(int a,int b)
{
	ll A = a;
	ll B = b;
	string ans="";
	if((A < 0 && B > 0) || (A >0 && B < 0) )
	{
		// cout<<(A<0)<<endl;
		// cout<<(B<0)<<endl;
		ans += "-";
		// A = abs(A);
		// B = abs(B);
	}
	// A = max(A,A*-1);
	// B = max(B,B*-1);
	if(A < 0)
	{
		A = A*(-1);
	}
	if(B < 0)
	{
		B = B*(-1);
	}
	cout<<A<<" "<<B<<endl;
	ans += to_string(A/B);
	if(A%B!=0)
	{
		ans += ".";
		vector<int> decimal;
		map<long long int,int> present;
		long long int rem = (A % B)*10;
		int div = (rem) / B;
		int s_id = -1;
		while(rem)
		{
			cout<<"rem " + to_string(rem) + " div " + to_string(div)<<endl;
			if(present.find(rem) == present.end())
			{
				/* 
				not present in map.
				occuring for first time 
				*/ 
				div = (rem) / B;
				decimal.push_back(div);
				present.insert(make_pair(rem,decimal.size()-1));
				rem = (rem % B)*10;
				
			}
			else
			{
				/* 
				already present in map.
				calculate starting index for recursion.
				*/
				s_id = present[rem];
				break;
			}
		}
		if(s_id == -1)
		{
			for (int i = 0; i < decimal.size(); i++)
			{
				ans += to_string(decimal[i]);
			}
			
		}
		else
		{
			for (int i = 0; i < s_id ; i++)
			{
				ans += to_string(decimal[i]);
			}
			ans+= "(";
			for (int i = s_id; i < decimal.size(); i++)
			{
				ans += to_string(decimal[i]);
			}
			ans += ")";
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	return 0;
}