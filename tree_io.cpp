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

TreeNode* CreateBiTree(string& str)  //！一定要传指针或者引用！！！
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

//先序遍历 
void PreOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	cout << root->val << " ";				//操作
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

//中序遍历
void  InOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	InOrderTraverseRecursion(root->left);
	cout << root->val << " ";	//操作
	InOrderTraverseRecursion(root->right);
}
void InOrderTraverseIteration(TreeNode* root)
{
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur || !st.empty()) {
		while (cur) {			//可以将此while与外层while合并成一个，效果完全相同，如下 
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		cout << cur->val << " ";
		cur = cur->right;
	}
}

//后续遍历
void  PostOrderTraverseRecursion(TreeNode* root)
{
	if (root == nullptr) return;
	PostOrderTraverseRecursion(root->left);
	PostOrderTraverseRecursion(root->right);
	cout << root->val << " ";	//操作
}
void PostOrderTraverseIteration(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root) st.push(root);
	TreeNode* pre = nullptr;
	while (!st.empty()) {
		TreeNode* nd = st.top();
		if (!nd->left && !nd->right || pre && (nd->left == pre || nd->right == pre))	//叶子节点：叶子节点分为两种，一类是原本就是叶子节点的节点； 
		{																			//另一类是父节点的左孩子or右孩子已经出栈，其自身退化成叶节点 
			st.pop();																//这里的or，逻辑上当父节点同时有左右孩子是表示和 
			cout << nd->val << " ";
			pre = nd;
		}
		else {	//非叶子节点 
			if (nd->right) st.push(nd->right);
			if (nd->left) st.push(nd->left);
		}
	}
}
//层序遍历
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
	cout << "创建二叉树：";
	TreeNode* root = CreateBiTree(str);
	std::cout << '\n' << endl;

	cout << "先序遍历二叉树：";
	PreOrderTraverseRecursion(root);
	cout << "\n中序遍历二叉树：";
	InOrderTraverseRecursion(root);
	cout << "\n后序遍历二叉树：";
	PostOrderTraverseRecursion(root);

	cout << "\n\n非递归：" << endl;
	cout << "先序遍历二叉树：";
	PreOrderTraverseIteration(root);
	cout << "\n中序遍历二叉树：";
	InOrderTraverseIteration(root);
	cout << "\n后序遍历二叉树：";
	PostOrderTraverseIteration(root);

	cout << "\n\n层序遍历二叉树：";
	layerTraverse(root);
	cout << endl;
	int h = TreeDepth(root);
	std::cout << "\n二叉树深度为：" << h << endl;
	return 0;
}