#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
int main()
{
	cout << "---------------* LISTA *---------------" << endl;
	List<int>* kontener = new List<int>();
	List<int>* testoperator = new List<int>();

	kontener->pushBack(1);
	kontener->pushBack(2);
	kontener->pushBack(3);
	kontener->pushFront(5);
	kontener->pushFront(3);
	kontener->insert(3, 1);
	(*kontener)[0] = 9;
	kontener->remove(3);
	kontener->DisplayList();
	cout << endl;

	
	cout <<"Test operatora [] ..."<< (*kontener)[2] << endl;

	cout << "Test iteratora, konstruktora kopiujacegp i operatora '=': " << endl;
	for (auto it = kontener->cbegin(); it != kontener->cend(); ++it)
		std::cout << *it << " ";
		cout << endl;

		List<int>* kopia = new List<int>(kontener);

		for (auto it = kopia->cbegin(); it != kopia->cend(); ++it)
			std::cout << *it << " ";
		cout << endl;
		*testoperator = *kontener;
		testoperator->DisplayList();
		cout << endl;


		delete kontener;
		delete kopia;
		delete testoperator;


		cout << endl;

		cout << "---------------* STOS *----------------" << endl;

		Stack<int>* stack = new Stack<int>();
		Stack<int>* testopstack = new Stack<int>();
		stack->push(1);
		stack->push(2);
		stack->push(3);

		stack->DisplayStack();

		std::cout << "pop: " << stack->pop() << std::endl;
		stack->DisplayStack();

		cout << "Test konstruktora kopiujacegp i operatora '=': " << endl;
		*testopstack = *stack;
		testopstack->DisplayStack();
		Stack<int>* kopiastack = new Stack<int>(stack);
		kopiastack->DisplayStack();
		delete testopstack;
		//delete stack;

		cout << "---------------* QUEUE *----------------" << endl;

		Queue<int>* queue = new Queue<int>;
		queue->enqueue(1);
		queue->enqueue(2);
		queue->enqueue(3);
		for (int i = 0; i < 3; i++)
		{
			cout << queue->dequeue() << ' ';
		}
		cout << endl;

		
		queue->enqueue(1);
	
		delete queue;
		

		cout << "-----------* PriorityQueue *------------" << endl;

		PriorityQueue<int>* Pqueue = new PriorityQueue<int>;
		Pqueue->enqueue(1, 1);
		Pqueue->enqueue(1, 6);
		Pqueue->enqueue(1, 1);
		Pqueue->enqueue(5, 3);
		Pqueue->enqueue(3, 2);
		PriorityQueue<int>* Pqueue1 = new PriorityQueue<int>(Pqueue);
		for (int i = 0; i < 5; i++)
		{
			cout << Pqueue->dequeue() << ' ';
		}
		cout << endl;
		cout << "Test konstruktora kopiujacego i operatora '='" << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << Pqueue1->dequeue() << ' ';
		}
		cout << endl;

		
		Pqueue->enqueue(3, 2);
		Pqueue1->enqueue(3, 2);
		delete Pqueue;


	return 0;

}
