#include "iostream"
#include "stack"
#include "vector"
using namespace std;

void printStack(stack<int> d)
{
	while (!d.empty())
	{
		cout << d.top() << " ";
		d.pop();
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 4,2,3,8 };
	stack<int> a;
	for (int i = 0; i < input.size(); i++) {
		a.push(input[i]);
	}

	printStack(a);

	return 0;


}