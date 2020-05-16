#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxi(ll a, ll b) {return a>b?a:b;}
ll mini(ll a, ll b) {return a<b?a:b;}
int main()
{
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    string input;
	    cin>>input;
	    input = 'I' + input;
	    int n = input.size();
	    
		vector<int> v(n,0);
	    v[0] = 1;
	    
	    if(input[n-1]=='D')
	    {
	        v[n-1] = 1;
		}
	    for(int i=1;i<n;i++)
	    {
	        if(input[i]=='I')
	        {
	            if(input[i-1]=='I')
	                v[i] = v[i-1] + 1;
	            else
	                v[i] = 2;
	        }
	    }
	    for(int i=n-2;i>=0;i--)
	    {
	        if(input[i]=='D')
	        {
	            if(input[i+1] == 'D')
	                v[i] = v[i+1] + 1;
	            else
	                v[i] = 1;
	        }
	    }
	    
	    int prev = 1;

	    for(int i=1;i<n;i++)
	    {
	        if(input[i]=='I')
	        {
	            v[i] = prev + 1;
	            prev = prev + 1;
	        }
	        else if(input[i]=='D')
	        {
	            if(input[i-1] == 'D')
	            {
	                v[i] = v[i-1] -1;
	            }
	            else
	            {
	                v[i-1] += v[i];
	                prev = v[i-1];
	                v[i] = v[i-1] -1;
	            }
	        }
	    }


	    for(int i=0;i<v.size();i++)
	    {
	        cout<<v[i];
	    }
	    cout<<endl;
	}
	return 0;
}