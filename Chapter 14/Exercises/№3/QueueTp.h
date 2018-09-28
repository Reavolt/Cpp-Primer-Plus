#ifndef QUEUETP_H_    
#define QUEUETP_H_

//-------------------------------------------------------------------------------------------------
template <typename T>
class QueueTp
{
private:
	struct Node 
	{ 
		T value; 
		Node* next = nullptr; 
		Node* prev = nullptr; 
	};
	using link = Node*;
	link head = nullptr;
	link tail = nullptr;
	void emptyList();
public:
	QueueTp();
	QueueTp(const QueueTp<T> & q);
	~QueueTp();
	
	bool enqueue(const T & val);
	bool dequeue(T & val);
	bool isEmpty() const;
	
	QueueTp<T> & operator = (const QueueTp<T> & q);
};
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::QueueTp() : head(nullptr), tail(nullptr)
{
	
}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::QueueTp(const QueueTp<T> & q)
{
	link tail = q.tail;
	while (tail != nullptr)
	{
		enqueue(tail->value);
		tail = tail->prev;
	}
}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T>::~QueueTp()
{
	emptyList();
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void QueueTp<T>::emptyList()
{
	link t = head;
	while (t != nullptr && t != tail)
	{
		t = t->next;
		delete t->prev;
	}
	delete t;
	head = nullptr;
	tail = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::enqueue(const T & val)
{
	link l = new (std::nothrow) Node;
	if (l == nullptr)
	{
		return false;
	}
	else 
	if (isEmpty())
	{
		l->value = val;
		l->next = nullptr;
		l->prev = nullptr;
		head = l;
		tail = l;
	}
	else
	{
		l->value = val;
		l->next = head;
		l->prev = nullptr;
		head->prev = l;
		head = l;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::dequeue(T & val)
{
	if (isEmpty())
	{
		return false;
	}
	else 
	if (head == tail)
	{
		val = tail->value;
		delete tail;
		head = tail = nullptr;
	}
	else
	{
		val = tail->value;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
bool QueueTp<T>::isEmpty() const
{
	if (nullptr == head && nullptr == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
template <typename T>
QueueTp<T> & QueueTp<T>::operator = (const QueueTp<T> & q)
{
	if (&q == this)
	{
		return *this;
	}
	
	emptyList();
	link t = q.tail;
	while (t != nullptr)
	{
		enqueue(t->value);
		t = t->prev;
	}
}
//-------------------------------------------------------------------------------------------------
#endif // QUEUETP_H_