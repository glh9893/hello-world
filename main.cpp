#include "heap.h"
using namespace std;
int main()
{
	int a[5] = { 2,1,4,5,3 };
	Heap h(a, 5);
	cout << h.Top() << endl;
	h.Push(0);
	cout << h.Top() << endl;
	return 0;
}