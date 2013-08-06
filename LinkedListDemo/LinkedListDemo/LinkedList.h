#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
template <typename T>
struct Node
{
public:
	Node(T t) : data(t), next(NULL), prev(NULL) {}
	Node(T t, Node* p, Node* n) : data(t), prev(p), next(n) {}
	Node<T>* next;
	Node<T>* prev;
	T data;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void PushFront(T data);
	void PushBack(T data);
	T PopFront();
	T PopBack();
	T ElementAt(int index);
	int Size() { return count; };
	bool Empty() { return count == 0; };
	void Clear();
	Node<T>* head;
	Node<T>* tail;
	
private:
	int count;
};



template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* currentNode = this->head;
	while(currentNode != NULL)
	{
		Node<T>* tmp = currentNode;
		currentNode = currentNode->next;
		delete tmp;
	}
	head = NULL;
	tail = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::PushFront(T data)
{
	Node<T> *node = new Node<T>(data);
	if(this->Empty())
	{
		this->head = this->tail = node;
	}
	else
	{
		node->next = this->head;
		this->head = node;
	}
	count++;
}

template <typename T>
T LinkedList<T>::PopFront()
{
	Node<T> *oldHead = this->head;
	if(this->Size() == 1)
	{
		this->head = this->tail = NULL;
	}
	else
	{
		this->head = head->next;
	}
	T data = oldHead->data;
	delete oldHead;
	count--;
	return data;
}

template <typename T>
void LinkedList<T>::PushBack(T data)
{
	Node<T> *node = new Node<T>(data);
	if(this->Empty())
	{
		this->head = this->tail = node;
	}
	else
	{
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}
	count++;
}

template <typename T>
T LinkedList<T>::PopBack()
{
	Node<T> *oldTail = this->tail;
	if(this->Size() == 1)
	{
		this->head = this->tail = NULL;
	}
	else
	{
		this->tail = tail->prev;
	}
	T data = oldTail->data;
	delete oldTail;
	count--;
	return data;
}

template <typename T>
T LinkedList<T>::ElementAt(int index)
{
	int i = 0;
	Node<T>* curr = this->head;
	while(curr != NULL && i < index)
	{
		curr = curr->next;
		++i;
	}
	// Return NULL if index not found
	if(i != index)
	{
		curr = NULL;
	}
	return curr->data;
}
 
#endif