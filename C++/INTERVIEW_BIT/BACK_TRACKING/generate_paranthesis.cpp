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
bool valid(string A)
{
    stack<char> s;
    for(char a:A)
    {
        if(a=='(')
        {
            s.push(a);
        }
        else
        {
            if(s.empty() || s.top() != '(')
                return false;
            else
                s.pop();
            
        }
    }
    return s.empty();
}
vector<string> generateAll(int openCount,int closeCount)
{
	vector<string> ans;
	ans.clear();
	if(openCount == 0)
	{
		string temp;
		temp.assign(closeCount,')');
		ans.push_back(temp);
		return ans;
	}
	else if (closeCount == 0)
	{
		string temp;
		temp.assign(openCount,'(');
		ans.push_back(temp);
		return ans;
	}
	else
	{
		auto withoutOpen = generateAll(openCount-1,closeCount);
		for(string s: withoutOpen)
		{
			ans.push_back("("+s);
		}
		auto withoutClose = generateAll(openCount,closeCount-1);
		for(string s: withoutClose)
		{
			ans.push_back(")"+s);
		}
		return ans;
	}
	
}
vector<string> solve(int n)
{
	vector<string> ans;
	
	if(n==0)
	{
		ans.clear();
		return ans;
	}

	auto response = generateAll(n,n);
	for(string s:response)
	{
		if(valid(s))
			ans.push_back(s);
	}
	sort(ans.begin(),ans.end());
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