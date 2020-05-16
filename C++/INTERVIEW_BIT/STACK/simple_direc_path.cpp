#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}

string solve(string A)
{
	stack< string > s;
	stack< string > t;
	string temp = "";
	for (int i = 1; i < A.size(); i++)
	{
		if(A[i] != '/')
		{
			temp += A[i];
		}
			
		else
		{
			// cout<<temp<<endl;
			if(temp == "..")
			{
				if(s.size() > 0)
					s.pop();
			}
			else if(temp != "." && temp.size()>0)
			{

				s.push(temp);
			}
			temp="";
		}
	}
	if(temp == "..")
	{
		if(s.size() > 0)
			s.pop();
	}
	else if(temp != "." && temp.size()>0)
	{
		s.push(temp);
	}
	temp="";
	// cout<<s.size();
	string ans ="/";
	while(!s.empty())
	{
		t.push(s.top());
		s.pop();
	}
	while(!t.empty())
	{
		ans+=t.top();
		if(t.size() > 1)
			ans+="/";
		t.pop();
	}
	// cout<<ans<<endl;
	return ans;
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	string input;
	cin>>input;
	cout<<solve(input)<<endl;
	return 0;
}