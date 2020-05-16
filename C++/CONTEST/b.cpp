#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    int n;
    cin>>n;
    int arr[n+5];
    int count[12][n+3];
    for(int i=1;i<=11;i++)
    {
    	for(int j=0;j<n;j++)
    		count[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	s.insert(arr[i]);
    	if(i==0)
    		count[arr[i]][i] = 1;
    	else
	    	count[arr[i]][i]=count[arr[i]][i-1]+1;
    	if(i!=0)
    	{
	    	for(int j = 1;j<=10;j++)
	    	{
	    		if(j!=arr[i])
		    		count[j][i] = count[j][i-1];
	    	}
    	}
    }
    // for(int i=1;i<=10;i++)
    // {
    	// for(int j=0;j<n;j++)
    		// cout<<count[i][j]<<" ";
    	// cout<<endl;
    // }
    // cout<<endl<<endl;
    int ans;
    int temp_count[12];
    if(s.size()==n || s.size()==1)
    	cout<<n<<endl;
    else
    {
    	for(int i=n-1;i>=0;i--)
    	{
    		s.clear();
    		for(int j=1;j<=10;j++)
    		{
    			if(count[j][i]!=0)
    			{
    				s.insert(count[j][i]);
    				temp_count[count[j][i]]++;
    			}
    		}
    		if(s.size()==2)
    		{
    			int a = *s.begin();
    			int b = *s.rbegin();
    			// cout<<a<<" "<<b<<endl;
    			if(abs(a-b)==1 || ( temp_count[a] == 1 || temp_count[b]==1))
    			{
    				ans = i;
    				break;
    			}
    		}
    	}
    	cout<<ans+1<<endl;
    }
    return 0;
}