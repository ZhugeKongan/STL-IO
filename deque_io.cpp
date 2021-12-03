#include "iostream"
#include "deque"
using namespace std;


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	deque<int> a = { 4,2,3,8 };
	printDeque(a);
	std::cout << "Hello World!\n" << endl;

	return 0;

}