#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Map.h"
#include <stack>
#include <queue>
#include <list>
#include <iterator>

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

		cout << "-----------* HASHMAP *------------" << endl;

		Map<int, int>* mapINT = new Map<int, int>();
		Map<string, int>* mapSTRING = new Map<string, int>();
		

		mapINT->insert(100, 1);
		mapINT->insert(20, 2);

		mapSTRING->insert("Adam", 3);
		mapSTRING->insert("John", 4);

		mapINT->DisplayHash();
		mapSTRING->DisplayHash();

		cout << "Test konstruktora kopiujacego i operatora '='" << endl;

		Map<int, int>* mapINTKO = new Map<int, int>(mapINT);
		Map<string, int>* mapSTRINGOP = new Map<string, int>();

		*mapSTRINGOP = *mapSTRING;
		mapINTKO->DisplayHash();
		mapSTRINGOP->DisplayHash();

		

		delete mapINT;
		delete mapSTRING;
		delete mapINTKO;
		delete mapSTRINGOP;


		cout << "-----------------------* STL *----------------------" << endl;
		cout << '.' << endl << '.' << endl << '.' << endl;
		cout << "---------------* LISTA *---------------" << endl;
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_front(5);
		list.push_front(3);
		auto it = list.begin();
		list.insert(it, 9);

		std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

		cout << endl << endl;

		for (auto it = list.begin(); it != list.end(); ++it) // dodaje za pomoca iteratora do kazdego elementu 1
			*it += 1;

		std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

		cout << endl << endl;

		list.remove(4);   // usuwa wszystkie 4
		std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));
		cout << endl;

		cout << "---------------* STOS *----------------" << endl;
		std::stack<int> stack;
		stack.push(1);
		stack.push(2);
		stack.push(3);

		cout << stack.top() << " ";
		stack.pop();

		cout << stack.top() << " ";
		stack.pop();

		cout << stack.top() <<endl;
		stack.pop();
		cout << "---------------* QUEUE *----------------" << endl;
		std::queue<int> kolejka;
		kolejka.push(1);
		kolejka.push(2);
		kolejka.push(3);

		std::cout << kolejka.front() << " ";
		kolejka.pop();

		std::cout << kolejka.front() << " ";
		kolejka.pop();

		cout << kolejka.front() << endl;
		kolejka.pop();
		cout << "-----------* PriorityQueue *------------" << endl;
		std::priority_queue<int> kolejkaP;
		kolejkaP.push(3);
		kolejkaP.push(5);
		kolejkaP.push(1);

		cout << kolejkaP.top() << " ";
		kolejkaP.pop();

		cout << kolejkaP.top() << " ";
		kolejkaP.pop();

		cout << kolejkaP.top() <<endl;
		kolejkaP.pop();

	return 0;

}
