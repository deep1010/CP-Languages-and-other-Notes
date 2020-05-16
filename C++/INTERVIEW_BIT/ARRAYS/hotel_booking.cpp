#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
struct booking
{
	int s;
	int e;
};
bool comp_func(booking a, booking b)
{
	if (a.s < b.s)
	{
		return true;
	}
	else if (a.s == b.s)
	{
		return a.e < b.e;
	}
	else
		return false;
}
int solve(vector<int>A,vector<int>B,int C)
{
	int k = C;
	vector<booking> arr;
	booking temp;
	for (int i = 0; i < A.size(); ++i)
	{
		temp.s = A[i];
		temp.e = B[i];
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(),comp_func);
	// for (int i = 0; i < arr.size(); ++i)
	// {
	// 	cout<<i<<" "<<arr[i].s<<" "<<arr[i].e<<endl;
	// }
	set<int> booked;
	bool ans = true;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(booked.size() < k)
		{
			booked.insert(i);
			// cout<<i<<" inserted\n";
		}
		else if (booked.size() == k)
		{
			vector<int> temp_arr;
			for (std::set<int>::iterator j = booked.begin(); j != booked.end(); ++j)
			{
				int id = *j;
				// cout<<id<<" "<<arr[id].s<<" "<<arr[id].e<<" "<<arr[i].s<<endl;
				if(arr[id].e < arr[i].s)
				{
					temp_arr.push_back(id);
					// cout<<id<<" removed\tnew size: "<<booked.size()-temp_arr.size()<<endl;
				}
			}
			for (std::vector<int>::iterator j = temp_arr.begin(); j != temp_arr.end(); ++j)
			{
				booked.erase(*j);
			}
			if (booked.size() == k)
			{
				ans = false;
				break;
			}
			else
			{
				booked.insert(i);
				// cout<<i<<" inserted-2\n";
			}
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,k,temp;
	cin>>n>>k;
	vector<int> arrive;
	vector<int> depart;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		arrive.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		depart.push_back(temp);
	}
	cout<<solve(arrive,depart,k)<<endl;
	return 0;
}