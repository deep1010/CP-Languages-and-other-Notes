#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[1005];
int n,m;
int gn(int cur)
{
	if(arr[(cur+2)%n] !=-1)
	{
		// arr[(cur+2)%n] =-1;
		return (cur+2)%n;
	}
	else{
		return gn((cur+1)%n);
	}
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(n==m)
    {
    	cout<<0<<endl;
    	return 0;
    }
    if(m==0)
    {
    	cout<<1<<endl;
    	return 0;
    }
    for(int i=0;i<n;i++)
    	arr[i]=0;
    int cur = 0;
    for (int i = 0; i < m; ++i)
    {
    	// cout<<i<<" ";
    	arr[cur] = -1;
    	cur=gn(cur);
    	// m-=1;
    }
    // cout<<endl;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
    	// cout<<arr[i]<<" ";
    	if(arr[i]==-1 && arr[(i+1)%n]!=-1)
    		ans++;
    }
    // cout<<endl;
    cout<<ans<<endl;

    return 0;
}