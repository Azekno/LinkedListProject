#pragma once
#include <iostream>
struct Node
{
	int data;
	Node* previous;
	Node* next;
};
class DoubleLinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int elementCount;
public:
	//void LinkedList();
	void AddNodeToFront(int variable);
	void AddNodeToBack(int variable);
	void InsertAfterNode(Node*, int newData);
	void PopFront();
	void PopBack();
	//void Erase()
};
