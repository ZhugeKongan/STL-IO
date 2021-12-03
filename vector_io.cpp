#include "iostream"
#include "vector"
using namespace std;


void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> a = { 1,2,3,8 };
	printVector(a);
	std::cout << "Hello World!\n" << endl;

	return 0;


}