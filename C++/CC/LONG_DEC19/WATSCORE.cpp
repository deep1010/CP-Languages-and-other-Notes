#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define cint(a) scanf("%d",&a)
#define clong(a) scanf("%lld",&a)
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

	int t=0;
	cin>>t;
	while(t--)
	{
		vi score(15,0);
		int n,s,p;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> p >> s;
			score[p] = max(score[p],s);
		}
		ll ans = 0;
		for(int i=1; i<=8;i++)
		{
			ans += score[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}