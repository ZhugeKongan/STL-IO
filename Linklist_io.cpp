#include "iostream"
#include "vector"
using namespace std;

struct ListNode {

	int val;
	ListNode * next;//ָ����һ���ڵ�
	ListNode(int x) :val(x), next(NULL) {} //�вι��캯��
};

void CreatPostList(ListNode* Head, vector<int>& nums)//β�巨
{
	ListNode* p = Head;
	for (int i = 1; i < nums.size(); ++i)
	{
		ListNode* NewListNode = new ListNode(nums[i]);//�����½ڵ㲢��ֵ
		p->next = NewListNode;//����һ�ڵ��nextָ��ǰ�½��ڵ�
		p = NewListNode;
	}
}
void CreatPreList(ListNode* Head, vector<int>& nums)//ͷ�巨
{
	for (int i = 0; i < nums.size(); ++i)
	{
		ListNode* NewListNode = new ListNode(nums[i]);//�����½ڵ㲢��ֵ
		NewListNode->next = Head->next;
		Head->next = NewListNode;
	}
}


void PrintList(ListNode* Head)
{
	ListNode* p = Head;
	while (p != NULL)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	vector<int> nums = { 1,2,6,3,4,5,6 };
	ListNode* Head = new ListNode(1);//����ͷ���
	//CreatPreList(Head,nums);
	//Head = Head->next;
	CreatPostList(Head, nums);
	PrintList(Head);

	return 0;
}