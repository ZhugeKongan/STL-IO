#include "iostream"
#include "map"
#include "vector"
#include "unordered_map"
using namespace std;

void printMap(map<int, char>&m) {
	for (map<int, char>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << "  value=" << it->second << endl;
	}
	cout << endl;
}
void printMultimap(multimap<int, char>&m) {
	for (multimap<int, char>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << "  value=" << it->second << endl;
	}
	cout << endl;
}
void printUordermap(unordered_map<int, char>&m) {
	for (unordered_map<int, char>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << "  value=" << it->second << endl;
	}
	cout << endl;
}

int main()
{
	map<int, char> x = { {4,'a'},{3,'b'} ,{2,'c'} ,{1,'d'} };
	multimap<int, char> mx = { {4,'a'},{3,'b'} ,{2,'c'} ,{3,'d'} };
	unordered_map<int, char> ux = { {4,'a'},{3,'b'} ,{2,'c'} ,{1,'d'} };
	printMap(x);
	printMultimap(mx);
	printUordermap(ux);

	return 0;



}