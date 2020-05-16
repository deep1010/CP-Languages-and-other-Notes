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
int solve(string A)
{
	stack<char> s;
	int n = A.size();
	for(int i=0;i<n;i++)
	{
		if( A[i]!=')')
		{
			s.push(A[i]);
		}
		else
		{
			string temp;
			temp += ')';
			while(s.top() != '(' && !s.empty() )
			{
				temp += s.top();
				s.pop();
			}
			temp += s.top();
			s.pop();
			if(temp.size() <=3)
			{
				return 1;
			}
			s.push('A');
		}
	}
	return 0;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	string input;
	getline(cin,input);
	cout<<solve(input)<<endl;
	return 0;
}
