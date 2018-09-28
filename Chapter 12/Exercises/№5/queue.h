// queue.h — интерфейс для очереди 
#ifndef QUEUE_H_  
#define QUEUE_H_ 
#include <cstdlib>

//-------------------------------------------------------------------------------------------------
// Очередь, содержащая элементы Customer 
class Customer
{
private:
	long arrive;		// момент появления клиента 
	int processtime; 	// время обслуживания клиента 
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
//-------------------------------------------------------------------------------------------------
using Item = Customer;
//-------------------------------------------------------------------------------------------------
class Queue
{
private:
	// Определения области действия класса 
	// Node - вложенная структура, локальная для данного класса 
	struct Node 
	{ 
		Item item; 
		struct Node* next; 
	};
	enum { Q_SIZE = 10 };
	// Закрытые члены класса 
	Node * front = nullptr;			// указатель на начало Queue 
	Node * rear = nullptr;			// указатель на конец Queue 
	int items = 0;					// текущее количество элементов в Queue 
	const int qsize;				// максимальное количество элементов в Queue 
				 
	// Упреждающие объявления для предотвращения открытого копирования 
	Queue(const Queue & q) : qsize(0) { }
	Queue & operator = (const Queue & q) { return *this; }
public:
	Queue(int qs = Q_SIZE); // создание очереди с предельным размером qs 
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item); // добавление элемента в конец 
	bool dequeue(Item &item);		// удаление элемента из начала 
};
//-------------------------------------------------------------------------------------------------
#endif //QUEUE_H_