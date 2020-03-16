#include "List.h"

int main()
{
	List<int>* kontener = new List<int>();

	int a = 1;
	int b = 2;
	int c = 3;

	kontener->pushBack(c);
	kontener->pushBack(a);
	kontener->pushBack(a);
	kontener->remove(c);
	kontener->pushBack(a);
	kontener->pushFront(b);
	kontener->pushBack(a);

	kontener->DisplayList();

	cout << endl;

	return 0;

}
