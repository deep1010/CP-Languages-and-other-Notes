#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define cin(a) scanf("%d",&a)
#define cinl(a) scanf("%lld",&a)
#define b begin
#define e end
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long int>
#define INF IMT_MAX-100
#define pb push_ back
#define mp make_pair


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

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>> n;
		ll count0 = 0;
		ll count2 = 0;
		ll temp;
		ll ans = 0;
		for(int i=0;i<n;i++)
		{
			cin >> temp;
			if(temp == 2)
			{
				count2++;
			}
			else if(temp == 0)
			{
				count0++;
			}
		}
		count0 = max(0LL,(count0*(count0-1))/2LL);
		count2 = max(0LL,(count2*(count2-1))/2LL);
		ans = count0 + count2;
		cout << ans << endl;
	}
	return 0;
}