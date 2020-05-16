#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
vector< vector<int> > solve(vector<string> A)
{
	map<string, vector<int> > group_map;
	for (int i = 0; i < A.size(); i++)
	{
		string temp = A[i];
		sort(temp.begin(),temp.end());
		if(group_map.find(temp) == group_map.end())
		{
			vector<int> temp_vec;
			temp_vec.push_back(i+1);
			group_map.insert(make_pair(temp,temp_vec));
		}
		else
		{
			group_map[temp].push_back(i+1);
		}
	}
	vector< vector<int> > ans;
	for(auto it = group_map.begin();it != group_map.end();it++)
	{
		ans.push_back(it->second);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	string temp;
	vector<string> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	// printVector(input);
	auto output = solve(input);
	for (int i = 0; i < output.size(); i++)
	{
		printVector(output[i]);
	}
	return 0;
}