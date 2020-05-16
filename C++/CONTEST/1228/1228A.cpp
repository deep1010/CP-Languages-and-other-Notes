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
bool all_distinct(int i)
{
	set<int> s;
	s.clear();
	int temp;
	while(i)
	{
		temp = i%10;
		if(s.find(temp)!=s.end())
		{
			return false;
		}
		else
		{
			s.insert(temp);
		}
		i = i/10;
	}
	return true;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int l;
	int r;
	cin>>l>>r;
	for(int i = l; i<=r;i++)
	{
		if(all_distinct(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}