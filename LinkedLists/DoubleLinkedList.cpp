#include "DoubleLinkedList.h"

void DoubleLinkedList::AddNodeToFront(int variable)
{
	Node* tempPtr = new Node;
	tempPtr->data = variable;
	
	if (head == nullptr)
	{
		head = tempPtr;
		tempPtr->previous = nullptr;
		tempPtr->data = variable;
		tempPtr->next = nullptr;
		tail = tempPtr;

	}
	else
	{
		tempPtr->next = head;
		tempPtr->data = variable;
		tempPtr->previous = nullptr;
		head->previous = tempPtr;
		head = tempPtr;
	}
	//delete tempPtr;
	elementCount++;
}

void DoubleLinkedList::AddNodeToBack(int variable)
{
	Node* tempPtr = new Node;
	tempPtr->data = variable;

	if (head == nullptr)
	{
		head = tempPtr;
		tempPtr->previous = nullptr;
		tempPtr->data = variable;
		tempPtr->next = nullptr;
		tail = tempPtr;
	}
	else
	{
		tempPtr->previous = tail;
		tempPtr->data = variable;
		tail->next = tempPtr;
		tempPtr->next = nullptr;
		tail = tempPtr;
	}
	//delete tempPtr;
	elementCount++;
}

//What I did from freehand
//void DoubleLinkedList::AddNode(int variable)
//{
//	Node* tempPtr = new Node;
//	tempPtr->data = variable;
//
//
//	if (head == nullptr)
//	{
//		head = tempPtr;
//		tail = tempPtr;
//	}
//	else
//	{
//		tail->next = tempPtr;
//		tail = tail->next;
//	}
//	elementCount++;
//}


void DoubleLinkedList::InsertAfterNode(Node*, int newData)
{

}