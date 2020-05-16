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
vector<int> solve(int A)
{
	vector<int> ans;
	int n = A;
	ans.push_back(1);
	int previousVal;
	for (int i = 1; i <=n; i++)
	{
		previousVal = ans[i-1];
		ans.push_back(previousVal*(n-i+1)/i);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int k;
	cin>>k;
	printVector(solve(k));
	return 0;
}