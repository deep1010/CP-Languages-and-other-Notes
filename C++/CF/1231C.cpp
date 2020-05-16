#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	if(t.size()==0)
	{
		cout<<"Empty Vector\n";
		return;
	}
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[505][505];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>arr[i][j];
		}
		
	}
	for (int i = n-2; i >=0 ; i--)
	{
		for (int j = m-2; j >= 0; j--)
		{
			if(arr[i][j]==0)
				arr[i][j] = min(arr[i+1][j],arr[i][j+1]) - 1;
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
		
	// }
	if(arr[n-1][m-1] <= arr[n-2][m-1] || arr[n-1][m-1] <= arr[n-1][m-2])
	{
		cout<<-1<<endl;
		return 0;
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			// cout<<"i "<<i<<" j "<<j<<endl;
			if(arr[i][j] >= arr[i+1][j] || arr[i][j] >= arr[i][j+1])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += arr[i][j];
		}
	}	
	cout<<sum<<endl;
	return 0;
}