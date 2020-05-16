#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxi(ll a, ll b) {return a>b?a:b;}
ll mini(ll a, ll b) {return a<b?a:b;}
int solve(string A)
{
    stack<string> s;
    int n = A.size();
    int a,b;
    for(int i=0;i<n;i++)
    {
        if(A[i] == '*')
        {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
			s.pop();
			cout<<a<<'*'<<b<<endl;
            s.push(to_string(a*b));
        }
        else if(A[i] == '+')
        {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
			s.pop();
			cout<<a<<'+'<<b<<endl;
            s.push(to_string(a+b));
            
        }
        else if(A[i] == '-')
        {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
			s.pop();
			cout<<a<<'-'<<b<<endl;
            s.push(to_string(a-b));
        }
        else if(A[i] == '/')
        {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
			s.pop();
			cout<<a<<'/'<<b<<endl;
            s.push(to_string(a/b));
        }
        else
        {
			string temp;
			temp+=A[i];
            s.push(temp);
        }
    }
    return stoi(s.top());
}
int main()
{
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    string input;
	    cin>>input;
	    cout<<"\n"<<solve(input)<<"\n\n";
	}
	return 0;
}