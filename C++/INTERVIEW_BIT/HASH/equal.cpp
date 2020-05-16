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
vector<int> lex_small(vector<int> A, vector<int> B)
{
	for (int i = 0; i < A.size(); i++)
	{
		if(A[i] < B[i])
			return A;
		else if (B[i] < A[i])
			return B;	
	}
	return A;
}
vector<int> solve(vector<int> A)
{
	map<ll, pair<int,int> > sum_map;
	vector<int> ans;
	ll temp_sum;
	int n = A.size();
	ans.assign(4,n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			temp_sum = A[i] + A[j];
			if(sum_map.find(temp_sum) == sum_map.end())
			{
				sum_map.insert(make_pair(temp_sum,make_pair(i,j)));
			}
			else
			{
				auto id = sum_map[temp_sum];
				vector<int> temp_ans;
				int a,b,c,d;
				a = id.first;
				b = id.second;
				c = i;
				d = j;
				if(a < c && b!=d && b!=c)
				{
					temp_ans.push_back(a);
					temp_ans.push_back(b);
					temp_ans.push_back(c);
					temp_ans.push_back(d);
					ans = lex_small(ans,temp_ans);
				}
			}	
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
	printVector(solve(input));
	return 0;
}