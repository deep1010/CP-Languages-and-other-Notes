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
map<string, int> getDict(vector<string> A)
{
	map<string, int> ans;
	for (int i = 0; i < A.size(); i++)
	{
		if(ans.find(A[i])==ans.end())
		{
			ans.insert(make_pair(A[i],1));
		}
		else
		{
			ans[A[i]]+=1;
		}
	}
	return ans;
	
}
vector<string> breakString(string A,int B)
{
	vector<string> ans;
	string temp = "";
	for (int i = 0; i < A.size(); i++)
	{
		temp += A[i];
		if(temp.size() == B)
		{
			ans.push_back(temp);
			temp.clear();
		}
	}
	return ans;
}
vector<int> solve(string A, vector<string> B)
{
	vector<int> ans;
	if(B.size() == 0)
		return ans;
	auto countDict = getDict(B);
	int subLen = (int)B.size() * (int)B[0].size();
	if (subLen > A.size())
	{
		return ans;
	}
	
	int toFindLen = (int)B[0].size();
	string temp_str;
	for (int i = 0; i < A.size()-subLen+1; i++)
	{
		temp_str = A.substr(i,subLen);
		auto temp_vec = breakString(temp_str,toFindLen);
		auto tempDict = getDict(temp_vec);
		bool flag = true;
		for(auto it = tempDict.begin();it!=tempDict.end();it++)
		{
			if(countDict.find(it->first)==countDict.end() || tempDict[it->first] > countDict[it->first])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			ans.push_back(i);
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	string A,temp;
	int n;
	vector<string> input;
	cin>>A;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(solve(A,input));
	return 0;
}