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
class Trie
{
public:
	bool isLeaf;
	Trie* character[128];

	Trie()
	{
		this->isLeaf = false;

		for (int i = 0; i < 128; i++)
			this->character[i] = nullptr;
	}

	void insert(std::string);
	bool search(std::string);
};

void Trie::insert(std::string key)
{
	// start from root node
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		if (curr->character[key[i]] == nullptr)
			curr->character[key[i]] = new Trie();

		curr = curr->character[key[i]];
	}
	curr->isLeaf = true;
}

bool Trie::search(std::string key)
{
	if (this == nullptr)
		return false;

	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		curr = curr->character[key[i]];

		if (curr == nullptr)
			return false;
	}

	return curr->isLeaf;
}
void getWords(vector<string> &A, string B)
{
	string temp;
	temp="";
	B+="_";
	for (char i : B)
	{
		if(i!='_')
		{
			temp+=i;
		}
		else
		{
			A.push_back(temp);
			temp="";
		}
	}
	return;
	
}
bool compfunc(pair<int,int>& A,pair<int,int> &B)
{
	if(A.second > B.second)
		return true;
	else if(A.second == B.second && A.first < B.first)
		return true;
	return false;
}
vector<int> solve(string A, vector<string> B)
{
	vector<int> ans;
	vector<string> goodWords;
	getWords(goodWords,A);
	Trie* head = new Trie();
	for (string i : goodWords)
	{
		head->insert(i);
	}
	vector< pair<int,int> > count;
	for (int i = 0; i < B.size(); i++)
	{
		count.push_back(make_pair(i,0));
	}
	vector<string> temp;
	int id = 0;
	for (string review : B)
	{
		temp.clear();
		getWords(temp,review);
		for (string word : temp)
		{
			if(head ->search(word))
				count[id].second++;
		}
		id++;
	}
	sort(count.begin(),count.end(),compfunc);
	for (auto it : count)
	{
		ans.push_back(it.first);
	}
	
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	string goodWords;
	string temp;
	int reviewCount;
	vector<string> reviews;

	cin>>goodWords;
	cin>>reviewCount;
	for (int i = 0; i < reviewCount ; i++)
	{
		cin>>temp;
		reviews.push_back(temp);
	}
	printVector(solve(goodWords,reviews));
	return 0;
}