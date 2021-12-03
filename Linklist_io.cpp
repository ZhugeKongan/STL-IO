#include "iostream"
#include "vector"
using namespace std;

struct ListNode {

	int val;
	ListNode * next;//指向下一个节点
	ListNode(int x) :val(x), next(NULL) {} //有参构造函数
};

void CreatPostList(ListNode* Head, vector<int>& nums)//尾插法
{
	ListNode* p = Head;
	for (int i = 1; i < nums.size(); ++i)
	{
		ListNode* NewListNode = new ListNode(nums[i]);//创建新节点并赋值
		p->next = NewListNode;//让上一节点的next指向当前新建节点
		p = NewListNode;
	}
}
void CreatPreList(ListNode* Head, vector<int>& nums)//头插法
{
	for (int i = 0; i < nums.size(); ++i)
	{
		ListNode* NewListNode = new ListNode(nums[i]);//创建新节点并赋值
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
	ListNode* Head = new ListNode(1);//创建头结点
	//CreatPreList(Head,nums);
	//Head = Head->next;
	CreatPostList(Head, nums);
	PrintList(Head);

	return 0;
}