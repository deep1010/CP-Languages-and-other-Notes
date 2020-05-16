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

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	string s;
	
	cin>>n>>k>>s;

	if(k==0)
		cout<<s<<endl;
	
	else if(n==1)
		cout<<0<<endl;
	
	else
	{
		int i = 0;
		while(i < n && k >0)
		{
			if(i==0 && s[i]!='1')
			{
				s[i] = '1';
				k--;
			}
			else if(s[i]!='0' && i!=0)
			{
				s[i] = '0';
				k--;
			}
			i++;
		}
		cout<<s<<endl;
	}
	return 0;
}