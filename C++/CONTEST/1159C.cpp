#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>b;
    vector<int>g;
    int temp;
    ll g_sum = 0;
    for(int i=0;i<n;i++)
    {
    	cin>>temp;
    	b.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
    	cin>>temp;
    	g.push_back(temp);
    	g_sum+=temp;
    }
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
  

    if(b[n-1] > g[0])
    	cout<<-1<<endl;
  
    else if (n >=m )
    {
    	ll tot_ans=0;
    	int to_satis=m-1;
    	for(int i=n-1;i>=0;i--)
    	{
    		if(to_satis>=0)
    		{
    			tot_ans+=g[to_satis] + b[i]*(m-1);
    			to_satis--;
    		}
    		else
    		{
    			tot_ans+= b[i]*m;
    		}
    	}
	    cout<<tot_ans<<endl;
    }
    else
    {
    	ll tot_ans = 0;
    	if(b[n-1] == g[0])
    	{
	    	tot_ans += g_sum;
	    	for(int i=n-2;i>=0;i--)
	    	{
	    		tot_ans += b[i]*m;
	    	}
    	}
    	else
    	{
    		tot_ans += g_sum;
    		tot_ans -= g[0];
    		tot_ans += b[0];
    		tot_ans += b[1]*(m-1) + g[0];
    		for(int i=2;i<m;i++)
    		{
    			tot_ans += b[i]*m;
    		}
    	}
    	cout<<tot_ans<<endl;
    }
    return 0;
}