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
vector<int> solve(vector<int> A,int B)
{
	int k = B;
	int n= A.size();
	vector<int> ans;
	ans.clear();
	if(B > A.size())
	{
		return ans;
	}
	else
	{
		map<int,int> countMap;
		for (int i = 0; i < k; i++)
		{
			if(countMap.find(A[i])==countMap.end())
			{
				countMap[A[i]] = 1;
			}
			else
			{
				countMap[A[i]] +=1;
			}
		}
		ans.push_back(countMap.size());
		for (int i = 1; i < n-k+1; i++)
		{
			countMap[A[i-1]] -=1;
			if(countMap[A[i-1]]==0)
			{
				countMap.erase(A[i-1]);
			}

			if(countMap.find(A[i+k-1])==countMap.end())
			{
				countMap[A[i+k-1]] = 1;
			}
			else
			{
				countMap[A[i+k-1]] +=1;
			}
			ans.push_back(countMap.size());
		}
		return ans;
	}
	

}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,k,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cin>>k;
	printVector(solve(input,k));
	return 0;
}