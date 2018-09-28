// queuetp.h — шаблон очереди с вложенным классом 
#ifndef QUEUETP_H_
#define QUEUETP_H_

//-------------------------------------------------------------------------------------------------
template <class Item>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	// Node - определение вложенного класса 
	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item & i) :item(i), next(0) { }
	};
	Node* front;       // указатель на начало очереди 
	Node* rear;        // указатель на конец очереди 
	int items;          // текущее количество элементов в очереди 
	const int qsize;    // максимальное количество элементов в очереди 
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const
	{
		return items == 0;
	}
	bool isfull() const
	{
		return items == qsize;
	}
	int queuecount() const
	{
		return items;
	}
	bool enqueue(const Item &item); // добавление item в конец 
	bool dequeue(Item &item);       // удаление item из начала 
};
//-------------------------------------------------------------------------------------------------
// Методы QueueTP 
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}
//-------------------------------------------------------------------------------------------------
template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node * temp;
	while (front != 0)      // пока очередь не пуста 
	{
		temp = front;        // сохранение адреса первого элемента 
		front = front->next; // сдвиг указателя на следующий элемент 
		delete temp;         // удаление предыдущего первого 
	}
}
//-------------------------------------------------------------------------------------------------
// Добавление элемента в очередь 
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node(item);    // создание узла 
	// В случае сбоя операция new генерирует исключение std::bad_alloc 
	items++;
	if (front == 0)         // если очередь пуста, 
		front = add;        // элемент добавляется в начало 
	else
		rear->next = add;   // иначе добавляем в конец 
	rear = add;             // последний элемент назначается новым узлом 
	return true;
}
//-------------------------------------------------------------------------------------------------
// Помещение первого элемента в переменную item и удаление его из очереди 
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;     // item — первый элемент в очереди 
	items--;
	Node * temp = front;    // сохранение местоположения первого элемента 
	front = front->next;    // сдвиг на следующий элемент 
	delete temp;            // удаление предыдущего первого элемента 
	if (items == 0)
		rear = 0;
	return true;
}
//-------------------------------------------------------------------------------------------------
#endif // QUEUETP_H_