#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<"\t";
	}
	cout<<endl;
}
vector<int> solve(vector<int> A)
{
	int n = A.size();
	stack<int> s;
	vector<int> ans;
	
	if(n==0)
	{
		return ans;
	}
	
	ans.assign(n,-1);
	s.push(n-1);

	for (int i = n-2; i >= 0; i--)
	{
		if(A[i] >= A[s.top()])
		{
			s.push(i);
		}
		else
		{
			while(!s.empty() && A[i] < A[s.top()])
			{
				ans[s.top()] = A[i];
				s.pop();
			}
			s.push(i);
		}
	}
	return ans;
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(input);
	printVector(solve(input));
	return 0;
}