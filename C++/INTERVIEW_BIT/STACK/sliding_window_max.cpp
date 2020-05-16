#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}

vector<int> solve(vector<int> A, int B)
{
	stack<int> s;
	vector<int> ans;
	int N= A.size();
	if(B >= N)
	{
		ans.push_back(*max_element(A.begin(),A.end()));
		return ans;
	}
	for (int i = 0; i < N-B+1 ; i++)
	{
		while(!s.empty() && ( s.top() < i || s.top() >= i+B ))
		{
			s.pop();
		}
		if(s.empty())
		{
			s.push(i);
			for (int j = i+1; j < i+B; j++)
			{
				if(A[j] > A[s.top()])
				{
					s.pop();
					s.push(j);
				}
			}
		}
		else
		{
			if(A[i+B-1] > A[s.top()])
				{
					s.pop();
					s.push(i+B-1);
				}
		}
		ans.push_back(A[s.top()]);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp,b;
	vector<int> input;
	cin>>n>>b;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(solve(input,b));
	
	return 0;
}