#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> A,int B)
{
	int n = A.size();
	int m = B;
	vector<int> ans;
	if(m==0)
	{
		/*max  continuos no of 1*/
		// cout<<"here1\n";
		int max_start=-1,max_end=-1;
		int temp_len=0;
		int max_len=0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i]==1)
			{
				temp_len++;
			}
			else
			{
				if (temp_len > max_len)
				{
					max_len = temp_len;
					max_end = i-1;
					max_start = i-max_len;
				}
				temp_len = 0;
			}
		}
		if (temp_len > max_len)
		{
			max_len = temp_len;
			max_end = n-1;
			max_start = n-max_len;
		}
		if(max_start == -1 )
			return ans;
		else
		{
			for (int i = max_start; i <= max_end; ++i)
			{
				ans.push_back(i);
			}
			return ans;
		}
	}
	
	int max_l,max_s,max_e;
	vector<int> zero_id;
	zero_id.push_back(-1);
	for (int i = 0; i < n; ++i)
	{
		if (A[i]==0)
		{
			zero_id.push_back(i);
		}
	}
	zero_id.push_back(n);
	if(zero_id.size()==2)
	{
		// cout<<"her2\n";
		max_s = 0;
		max_e = n-1;
	}
	else
	{
		// cout<<"here3\n"<<"zero_id_size "<<zero_id.size()<<endl;
		int s = 1;
		int e = min(s+m-1,(int)zero_id.size()-2);
		max_l = max_s = max_e = -1;
		while(s < zero_id.size()-1 && e < zero_id.size()-1)
		{
			if (zero_id[e+1]-zero_id[s-1] > max_l)
			{
				max_l = zero_id[e+1]-zero_id[s-1];
				max_s = zero_id[s-1]+1;
				max_e = zero_id[e+1]-1;
			}
			s++;
			e++;
		}
	}
	// cout<<max_s<<" "<<max_e<<endl;
	for (int i = max_s; i <= max_e; ++i)
	{
		ans.push_back(i);
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	cin>>n;
	vector<int> input;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		input.push_back(temp);
	}
	int M;
	cin>>M;
	vector<int> v = solve(input,M);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}