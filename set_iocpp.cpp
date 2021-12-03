#include "iostream"
#include "set"
#include "vector"
using namespace std;

void printSet(const set<int>& st)
{
	for (set<int>::const_iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	set<int> x = { 4,2,3,8 };
	multiset<int> mx = { 2,2,3,3 };
	printSet(x);

	return 0;
}