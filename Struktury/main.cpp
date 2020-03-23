#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
int main()
{
	cout << "---------------* LISTA *---------------" << endl;
	List<int>* Lista = new List<int>();
	List<int>* ListaOP = new List<int>();

	Lista->pushBack(1);
	Lista->pushBack(2);
	Lista->pushBack(3);
	Lista->pushFront(5);
	Lista->pushFront(3);
	Lista->insert(3, 1);
	(*Lista)[0] = 9;
	Lista->remove(3);
	Lista->DisplayList();
	cout << endl;

	
	cout <<"Test operatora [] ... "<< (*Lista)[2] << endl;

	cout << "Test iteratora, konstruktora kopiujacegp i operatora '=': " << endl;
	for (auto it = Lista->cbegin(); it != Lista->cend(); ++it)
		std::cout << *it << " ";
		cout << endl;

		List<int>* ListaKO = new List<int>(Lista);

		for (auto it = ListaKO->cbegin(); it != ListaKO->cend(); ++it)
			std::cout << *it << " ";
		cout << endl;
		*ListaOP = *Lista;
		ListaOP->DisplayList();
		cout << endl;


		delete Lista;
		delete ListaOP;
		delete ListaKO;
		cout <<"Listy zostaly usuniete"<< endl;

		cout << "---------------* STOS *----------------" << endl;

		Stack<int>* Stos = new Stack<int>();
		Stack<int>* StosOP = new Stack<int>();

		Stos->push(1);
		Stos->push(2);
		Stos->push(3);

		Stos->DisplayStack();

		std::cout << "pop: " << Stos->pop() << std::endl;
		Stos->DisplayStack();

		cout << "Test konstruktora kopiujacegp i operatora '=': " << endl;
		*StosOP = *Stos;
		Stack<int>* StosKO = new Stack<int>(Stos);

		StosOP->DisplayStack();
		StosKO->DisplayStack();

		delete StosOP;
		delete Stos;
		delete StosKO;

		cout << "---------------* QUEUE *----------------" << endl;

		Queue<int>* queue = new Queue<int>;
		Queue<int>* QueueOP = new Queue<int>;
		
		queue->enqueue(1);
		queue->enqueue(2);
		queue->enqueue(3);

		Queue<int>* QueueKO = new Queue<int>(queue);
		*QueueOP = *queue;

		for (int i = 0; i < 3; i++)
		{
			cout << queue->dequeue() << ' ';
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << QueueKO->dequeue() << ' ';
		}
		cout << endl;


		for (int i = 0; i < 3; i++)
		{
			cout << QueueOP->dequeue() << ' ';
		}
		cout << endl;
		
		queue->enqueue(1);
		QueueKO->enqueue(1);
		QueueOP->enqueue(1);
		delete queue;
		delete QueueKO;
		delete QueueOP;

		

		cout << "-----------* PriorityQueue *------------" << endl;

		PriorityQueue<int>* Pqueue = new PriorityQueue<int>;
		PriorityQueue<int>* PqueueKO = new PriorityQueue<int>;

		Pqueue->enqueue(1, 1);
		Pqueue->enqueue(1, 6);
		Pqueue->enqueue(1, 1);
		Pqueue->enqueue(5, 3);
		Pqueue->enqueue(3, 2);

		*PqueueKO = *Pqueue;
		PriorityQueue<int>* PqueueOP = new PriorityQueue<int>(Pqueue);
		for (int i = 0; i < 5; i++)
		{
			cout << Pqueue->dequeue() << ' ';
		}
		cout << endl;

		cout << "Test konstruktora kopiujacego i operatora '='" << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << PqueueOP->dequeue() << ' ';
		}
		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << PqueueKO->dequeue() << ' ';
		}
		cout << endl;

		
		Pqueue->enqueue(3, 2);
		PqueueOP->enqueue(3, 2);
		PqueueKO->enqueue(3, 2);
		delete Pqueue;
		delete PqueueOP;
		delete PqueueKO;


	return 0;

}
