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
	kontener->insert(c, 1);
	(*kontener)[0] = 5;
	kontener->DisplayList();
	cout << endl;

	
	cout << (*kontener)[2] << endl;

	for (auto it = kontener->begin(); it != kontener->end(); ++it)
		std::cout << *it << " ";
		cout << endl;
	
	kontener->~List();
	
	


	return 0;

}
