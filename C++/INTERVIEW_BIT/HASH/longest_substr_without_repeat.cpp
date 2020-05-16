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

template<typename T>
void printSet(const T& t) {
	for(auto it = t.begin();it!=t.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
	return;
}

int solve(string A)
{
	set<char> s;
	int start = 0;
	int end = 0;
	int n = A.size();
	int max_len = 0;
	while(start < n && end < n)
	{
		if(s.find(A[end])==s.end())
		{
			s.insert(A[end]);
			end++;
			/*char is not present in substr*/
		}
		else
		{
			while(s.size() > 0 && s.find(A[end])!=s.end() && start < n)
			{
				s.erase(A[start]);
				start++;
			}
			s.insert(A[end]);
			end++;
			/*char has already occurred. move forward*/
		}
		max_len = max(max_len,(int)s.size());
		// printSet(s);
	}
	return max_len;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	string input;
	cin>>input;
	cout<<solve(input)<<endl;
	return 0;
}