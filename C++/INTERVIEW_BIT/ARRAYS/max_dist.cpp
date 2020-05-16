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
int solve(vector<int> A)
{
	int n = A.size();
	if(n==0)
	{
		return -1;
	}

	vector<pair<int,int> > B;
	for (int i = 0; i < n; i++)
	{
		B.push_back(make_pair(A[i],i));
	}
	sort(B.begin(),B.end());
	int ans = 0;
	int curMax = -1;
	for (int i = n-1; i>=0; i--)
	{
		curMax = max(curMax,B[i].second);
		ans = max(ans,curMax - B[i].second);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int temp;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cout<<solve(input)<<endl;
	return 0;
}