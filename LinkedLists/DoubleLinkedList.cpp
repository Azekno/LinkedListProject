#include "DoubleLinkedList.h"

void DoubleLinkedList::AddNodeToFront(int variable)
{
	Node* tempPtr = new Node;
	//tempPtr->data = variable;
	
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
	delete tempPtr;
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
	delete tempPtr;
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


void DoubleLinkedList::InsertAfterNode(int nodeData, int newData)
{
	Node* tempPtr; 
	Node* newNodePtr = new Node;
	
	tempPtr = head;
	if (head == nullptr)
	{
		std::cout << "Could not insert because the head is referencing a nullptr." << std::endl;
		return;
	}
	if (head == tail)
	{
		if (head->data != newData)
		{
			std::cout << "could not insert" << std::endl;
			return;
		}
		newNodePtr->data = newData;
		head->next = newNodePtr;
		newNodePtr->next = nullptr;
		head->previous = nullptr;
		newNodePtr->previous = head;
		tail = newNodePtr;
		return;
	}
	if (tail->data == newData)
	{
		newNodePtr->next = nullptr;
		newNodePtr->previous = tail;
		tail->next = newNodePtr;
		tail = newNodePtr;
		return;
	}
	while (tempPtr->data != nodeData)
	{
		tempPtr = tempPtr->next;
		if (tempPtr == nullptr)
		{
			std::cout << "Data couldn't be inserted" << std::endl;
			std::cout << "New data couldn't be found" << std::endl;
			return;
		}
	}

	newNodePtr->next = tempPtr->next;
	newNodePtr->previous = tempPtr;
	newNodePtr->data = newData;
	tempPtr->next->previous = newNodePtr;
	tempPtr->next = newNodePtr;

	delete newNodePtr;
}

void DoubleLinkedList::DeleteNodeAtFront()
{
	if (head == nullptr)
	{
		return;
	}
	if (head == tail)
	{
		Node* tempPtr;
		tempPtr = head;
		head = nullptr;
		tail == nullptr;
		delete tempPtr;
		return;
	}
	else
	{
		Node* tempPtr;
		tempPtr = head;
		head = head->next;
		head->previous = nullptr;
		delete tempPtr;
		return;
	}
}

void DoubleLinkedList::DeleteNodeAtBack()
{
	if (head == nullptr)
	{
		return;
	}
	if (head == tail)
	{
		Node* tempPtr;
		tempPtr = head;
		head = nullptr;
		tail = nullptr;
		delete tempPtr;
		return;
	}
	else
	{
		Node* tempPtr;
		tempPtr = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete tempPtr;
		return;
	}
}

void DoubleLinkedList::DeleteArbitraryNode(int dataToDelete)
{
	Node* tempPtr = new Node;
	tempPtr = head;
	if (head == tail)
	{
		if (head->data != dataToDelete)
		{
			std::cout << "Could not delete the data as it isn't in the list." << std::endl;
			return;
		}
		head == nullptr;
		tail == nullptr;
		delete tempPtr;
		return;
	}
	if (head->data == dataToDelete)
	{
		head = head->next;
		head->previous = nullptr;
		delete tempPtr;
		return;
	}
	while (tempPtr->data != dataToDelete)
	{
		tempPtr = tempPtr->next;
		if (tempPtr == nullptr)
		{
			std::cout << "There is no data to delete" << std::endl;
			return;
		}
	}
	tempPtr->next->previous = tempPtr->previous;
	tempPtr->previous->next = tempPtr->next;
	delete tempPtr;
}

int DoubleLinkedList::DeleteFirstAlternative()
{
	return 0;
}

int DoubleLinkedList::DeleteLastAlternative()
{
	return 0;
}

