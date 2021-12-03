#include "iostream"
#include "list"
#include "vector"
using namespace std;

void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	list<int> x = { 4,2,3,8 };
	printList(x);
	
	return 0;
}