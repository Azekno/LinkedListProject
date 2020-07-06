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
	void InsertAfterNode(int nodeData, int newData);
	
	void DeleteNodeAtFront();
	void DeleteNodeAtBack();
	void DeleteArbitraryNode(int datatoDelete);

	int DeleteFirstAlternative();
	int DeleteLastAlternative();

	//void Erase()
};
