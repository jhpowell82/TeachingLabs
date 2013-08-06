#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void)
{
	LinkedList<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushFront(4);
	list.PushFront(5);
	Node<int>* current = list.head;
	cout << "Just printing..." << endl;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	
	cout << "Element at index 2 = " << list.ElementAt(2) << endl;
	cout << "Popping off the front..." << endl;
	while(list.head != NULL)
	{
		cout << list.PopFront() << endl;
	}
	cout << "After pushing to back:" << endl;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	cout << "Just printing..." << endl;
	current = list.head;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << "Element at index 2 = " << list.ElementAt(2) << endl;
	cout << "Popping off the back..." << endl;
	while(list.head != NULL)
	{
		cout << list.PopFront() << endl;
	}
	int in;
	cin >> in;
}

