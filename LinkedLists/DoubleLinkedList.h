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
	int elementCount;
public:
	Node* head;
	Node* tail;
	
	void InitList();
	void IsListEmpty();


	void AddNodeToFront(int variable);
	void AddNodeToBack(int variable);
	void AddArbitraryNode(int nodeData, int newData);
	
	void DeleteNodeAtFront();
	void DeleteNodeAtBack();
	void DeleteArbitraryNode(int datatoDelete);

	Node* SearchNodes(int valueToSearch);
	void PrintLinkedListContents();
	void PrintSortedLinkedListContents();
	void PrintFirstOfList();
	void PrintLastOfList();

	//void Erase()
};
