#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* solve(ListNode* A)
{
	ListNode* temp;
	temp = A;
	if(temp==NULL || temp->next == NULL)
	{
		return temp;
	}
	else
	{
		ListNode* next = temp->next;
		if(temp->val != next->val)
		{
			temp->next = solve(next);
			return temp;
		}
		else
		{
			temp->next = next->next;
			return solve(temp);
		}
		
	}
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ListNode* head = NULL;
	ListNode* newNode = NULL;
	ListNode* prev= NULL;
	int n,temp;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		newNode = new ListNode(temp);
		if(i==0)
		{
			head = newNode;
			prev = head;
		}
		else
		{
			prev->next = newNode;
			prev = newNode;
		}
	}
	
	prev = solve(head);
	while(prev != NULL)
	{
		cout<<prev->val<<" ";
		prev = prev->next;
	}
	cout<<endl;
	return 0;
}