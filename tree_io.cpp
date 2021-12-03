#include "iostream"
#include <stack>
#include <queue>
#include "vector"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateBiTree(string& str)  //��һ��Ҫ��ָ��������ã�����
{
	int n = str.size();
	if (n == 0)return nullptr;
	TreeNode* root = new TreeNode(str[0] - '0');
	std::cout << 1 << " ";
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while (!q.empty() && i < n) {
		TreeNode* front = q.front();
		q.pop();
		if (str[i] != '#') {
			TreeNode* T = new TreeNode(str[i] - '0');
			std::cout << T->val << " ";
			front->left = T;
			q.push(front->left);
		}
		else std::cout << '#' << " ";
		i++;
		if (str[i] != '#'&&i < n) {
			TreeNode* T = new TreeNode(str[i] - '0');
			std::cout << T->val << " ";
			front->right = T;
			q.push(front->right);
		}
		else std::cout << '#' << " ";
		i++;
	}
	return root;

}

//������� 
void PreOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	cout << root->val << " ";				//����
	PreOrderTraverseRecursion(root->left);
	PreOrderTraverseRecursion(root->right);
}
void PreOrderTraverseIteration(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root) st.push(root);
	while (!st.empty()) {
		TreeNode* nd = st.top();
		st.pop();
		cout << nd->val << " ";
		if (nd->right) st.push(nd->right);
		if (nd->left) st.push(nd->left);
	}
}

//�������
void  InOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	InOrderTraverseRecursion(root->left);
	cout << root->val << " ";	//����
	InOrderTraverseRecursion(root->right);
}
void InOrderTraverseIteration(TreeNode* root)
{
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur || !st.empty()) {
		while (cur) {			//���Խ���while�����while�ϲ���һ����Ч����ȫ��ͬ������ 
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		cout << cur->val << " ";
		cur = cur->right;
	}
}

//��������
void  PostOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	PostOrderTraverseRecursion(root->left);
	PostOrderTraverseRecursion(root->right);
	cout << root->val << " ";	//����
}
void PostOrderTraverseIteration(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root) st.push(root);
	TreeNode* pre = nullptr;
	while (!st.empty()) {
		TreeNode* nd = st.top();
		if (!nd->left && !nd->right || pre && (nd->left == pre || nd->right == pre))	//Ҷ�ӽڵ㣺Ҷ�ӽڵ��Ϊ���֣�һ����ԭ������Ҷ�ӽڵ�Ľڵ㣻 
		{																			//��һ���Ǹ��ڵ������or�Һ����Ѿ���ջ���������˻���Ҷ�ڵ� 
			st.pop();																//�����or���߼��ϵ����ڵ�ͬʱ�����Һ����Ǳ�ʾ�� 
			cout << nd->val << " ";
			pre = nd;
		}
		else {	//��Ҷ�ӽڵ� 
			if (nd->right) st.push(nd->right);
			if (nd->left) st.push(nd->left);
		}
	}
}
//�������
void layerTraverse(TreeNode* root)
{
	queue<TreeNode*> q;
	if (root) q.push(root);
	while (!q.empty()) {
		TreeNode* front = q.front();
		q.pop();
		cout << front->val << " ";
		if (front->left) q.push(front->left);
		if (front->right) q.push(front->right);
	}
}

int TreeDepth(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	return left > right ? left + 1 : right + 1;
}


int main()
{
	string  str = "1234#56#7##8";
	cout << "������������";
	TreeNode* root = CreateBiTree(str);
	std::cout << '\n' << endl;

	cout << "���������������";
	PreOrderTraverseRecursion(root);
	cout << "\n���������������";
	InOrderTraverseRecursion(root);
	cout << "\n���������������";
	PostOrderTraverseRecursion(root);

	cout << "\n\n�ǵݹ飺" << endl;
	cout << "���������������";
	PreOrderTraverseIteration(root);
	cout << "\n���������������";
	InOrderTraverseIteration(root);
	cout << "\n���������������";
	PostOrderTraverseIteration(root);

	cout << "\n\n���������������";
	layerTraverse(root);
	cout << endl;
	int h = TreeDepth(root);
	std::cout << "\n���������Ϊ��" << h << endl;
	return 0;
}