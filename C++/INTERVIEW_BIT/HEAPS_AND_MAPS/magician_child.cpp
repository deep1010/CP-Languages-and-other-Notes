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
int solve(vector<int> A,int B)
{
	int k = 0;
	int cur_choc;
	long long int ans = 0;
	int mod = 1000000007;
	priority_queue<int> max_choc;
	for(int choc: A)
	{
		max_choc.push(choc);
	}
	while(k < B && max_choc.size() > 0)
	{
		ans = ((ans % mod) + (max_choc.top()%mod))%mod;
		cur_choc = max_choc.top();
		// cout<<"k "<<k<<" cur_choc "<<cur_choc<<endl;
		max_choc.pop();
		cur_choc /=2;
		if(cur_choc > 0)
		{
			max_choc.push(cur_choc);
		}
		k++;
	}
	return (int)ans%mod;
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	int n,k,temp;
	cin>>n;
	vector<int>input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cin>>k;
	cout<<solve(input,k)<<endl;

	
	return 0;
}