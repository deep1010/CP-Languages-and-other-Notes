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
pair<bool,vector< vector<int> > > get_combi_sum(vector<int> A, int B)
{
    vector< vector<int> > ans;
    vector<int> temp;
    ans.clear();
    temp.clear();
    if(B==0)
    {
        ans.push_back(temp);
        return make_pair(true,ans);
    }
    else if( A.empty() || A[0] > B )
    {
        return make_pair(false,ans);
    }
    else
    {
        int n = A.size();
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            temp.clear();
            temp.assign(A.begin()+i+1,A.end());
            auto response = get_combi_sum(temp,B-A[i]);
            if(response.first)
            {
                for(auto it=response.second.begin();it!=response.second.end();it++)
                {
                    if(it->empty() || A[i] <= it->at(0))
                    {   
                        flag = true;
                        it->insert(it->begin(),A[i]);
                        ans.push_back(*it);
                    }
                }
            }
        }
        return make_pair(flag,ans);
    }
}
vector<vector<int> > solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    auto response = get_combi_sum(A,B);
    set<vector<int> > s;
    std::copy(response.second.begin(),response.second.end(),std::inserter(s,s.end()));
    vector<vector<int> > ans;
    std::copy(s.begin(),s.end(),back_inserter(ans));
    return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp,k;
	cin>>n>>k;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	auto ans = solve(input,k);
	for (int i = 0; i < ans.size(); i++)
	{
		printVector(ans[i]);
	}
	
	return 0;
}