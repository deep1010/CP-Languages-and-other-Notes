// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
#define ALPHABET_SIZE (26)

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isWordEnd;
  int weight;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isWordEnd = false;
  pNode->weight = -1;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

void insert(struct TrieNode *root, const string key,int weight)
{
	struct TrieNode *pCrawl = root;

	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isWordEnd = true;
  pCrawl->weight = weight;
}

bool search(struct TrieNode *root, const string key)
{
	int length = key.length();
	struct TrieNode *pCrawl = root;
	for (int level = 0; level < length; level++)
	{
		int index = key[level] - 'a';

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isWordEnd);
}

bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}


void suggestionsRec(struct TrieNode* root, string currPrefix,int &maxWeight)
{

	if (root->isWordEnd)
	{
    maxWeight = max(maxWeight,root->weight);
	}

	if (isLastNode(root))
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			currPrefix.push_back('a' + i);
      suggestionsRec(root->children[i], currPrefix,maxWeight);
		}
	}
}

int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;
	int level;
	int n = query.length();
  int maxWeight = -1;
	for (level = 0; level < n; level++)
	{
		int index = query[level] - 'a';

		if (!pCrawl->children[index])
			return -1;

		pCrawl = pCrawl->children[index];
	}
	if(true)
	{
		string prefix = query;
		suggestionsRec(pCrawl, prefix,maxWeight);
		return maxWeight;
	}
  return maxWeight;
}

int main()
{
	struct TrieNode* root = getNode();
	int n,q,w;
  string s;
  cin>>n>>q;
  for (size_t i = 0; i < n; i++) {
    cin>>s>>w;
    insert(root,s,w);
  }
  map<string,int> qMap;
  for (size_t i = 0; i < q; i++) {
    cin>>s;
    if(qMap.find(s)==qMap.end())
    {
        int temp = printAutoSuggestions(root,s);
        qMap.insert(make_pair(s,temp));
        cout<<temp<<endl;
    }
    else
    {
        cout<<qMap[s]<<endl;
    }
  }
	return 0;
}
