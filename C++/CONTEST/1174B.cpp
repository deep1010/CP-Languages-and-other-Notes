#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n+2];
    int even_c= 0;
    int odd_c = 0;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(arr[i]%2==0)
    		even_c++;
    	else
    		odd_c++;
    }
    if(even_c==n || odd_c==n)
    {
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }
    else
    {
    	sort(arr,arr+n);
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }

    return 0;
}