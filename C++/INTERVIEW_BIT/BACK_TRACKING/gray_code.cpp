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
vector<string> getString(int A)
{
	vector<string> ans;
	vector<string> temp;
	ans.clear();
	temp.clear();

	if(A==0)
	{
		return ans;
	}
	if(A==1)
	{
		ans.push_back("0");
		ans.push_back("1");
		return ans;
	}
	else
	{
		temp = getString(A-1);
		for (int i = 0; i < temp.size(); i++)
		{
			ans.push_back(temp[i]+"0");
		}
		for (int i = temp.size() -1; i >=0 ; i--)
		{
			ans.push_back(temp[i]+"1");
		}
		return ans;
	}
}
vector<int> solve(int A)
{
	auto numbers = getString(A);
	vector<int> ans;
	for (int i = 0; i < numbers.size(); i++)
	{
		ans.push_back(stoi(numbers[i],0,2));
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	printVector(solve(n));
	return 0;
}