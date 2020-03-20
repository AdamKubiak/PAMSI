#include "List.h"
#include "Stack.h"
#include "Queue.h"
int main()
{
	cout << "---------------* LISTA *---------------" << endl;
	List<int>* kontener = new List<int>();

	kontener->pushBack(3);
	kontener->pushBack(1);
	kontener->pushBack(1);
	kontener->pushBack(3);
	kontener->pushBack(1);
	kontener->pushFront(2);
	kontener->pushBack(1);
	kontener->insert(3, 1);
	(*kontener)[0] = 5;
	kontener->remove(3);
	kontener->DisplayList();
	cout << endl;

	
	cout << (*kontener)[2] << endl;

	for (auto it = kontener->begin(); it != kontener->end(); ++it)
		std::cout << *it << " ";
		cout << endl;
	
		delete kontener;

		cout << endl;

		cout << "---------------* STOS *----------------" << endl;

		Stack<int>* stack = new Stack<int>();

		stack->push(1);
		stack->push(2);
		stack->push(3);
		std::cout << "stos: ";
		stack->display();
		std::cout << "pop: " << stack->pop() << std::endl;
		std::cout << "stos po popie: ";
		stack->display();
		std::cout << "pop: " << stack->pop() << std::endl;
		std::cout << "stos po popie: ";
		stack->display();
		std::cout << "pop: " << stack->pop() << std::endl;
		std::cout << "stos po popie: ";
		stack->display();
		delete stack;

		cout << "---------------* QUEUE *----------------" << endl;

		Queue<int>* queue = new Queue<int>();

		queue->enqueue(1);
		queue->enqueue(2);
		queue->enqueue(3);

		for (int i = 0; i < 3; i++)
		{
			cout << queue->dequeue() << endl;
		}

		




	return 0;

}
