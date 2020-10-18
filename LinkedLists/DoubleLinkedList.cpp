#include "DoubleLinkedList.h"

void DoubleLinkedList::InitList()
{
	head = nullptr;
	tail = nullptr;
}

void DoubleLinkedList::IsListEmpty()
{
	if (head == nullptr)
	{
		std::cout << "The List is currently empty." << std::endl;
		system("pause");
		return;
	}
}

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
		//tempPtr->data = variable;
		tempPtr->next = nullptr;
		tail = tempPtr;
	}
	else
	{
		tempPtr->previous = tail;
		//tempPtr->data = variable;
		tail->next = tempPtr;
		tempPtr->next = nullptr;
		tail = tempPtr;
	}
	//delete tempPtr;
	elementCount++;
}

void DoubleLinkedList::AddArbitraryNode(int nodeData, int newData)
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
			std::cout << "Could not insert" << std::endl;
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

	//delete newNodePtr;
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
		std::cout << "Successfully deleted the selected node of the double linked list\n" << std::endl;
		return;
	}
	if (head->data == dataToDelete)
	{
		head = head->next;
		head->previous = nullptr;
		delete tempPtr;
		std::cout << "Successfully deleted the selected node of the double linked list\n" << std::endl;
		return;
	}
	else if (tail->data == dataToDelete)
	{
		tempPtr = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete tempPtr;
		std::cout << "Successfully deleted the selected node of the double linked list\n" << std::endl;
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

Node* DoubleLinkedList::SearchNodes(int valueToSearch)
{
	Node* tempPtr;
	tempPtr = head;
	
	while (tempPtr != nullptr)
	{
		if (tempPtr->data == valueToSearch)
		{
			return tempPtr;
			break;
		}
		tempPtr = tempPtr->next;
	}
	return nullptr;
}

void DoubleLinkedList::PrintLinkedListContents()
{
	Node* tempPtr;
	tempPtr = head;
	std::cout << "The contents in the Linked List are: \n" << std::endl;
	while (tempPtr != nullptr)
	{
		std::cout << tempPtr->data << "\n" << std::endl;
		tempPtr = tempPtr->next;
	}
}

void DoubleLinkedList::PrintSortedLinkedListContents()
{
	Node* tempPtr;
	tempPtr = head;
	std::cout << "The sorted contents in the Linked List are: \n" << std::endl;
	while (tempPtr != nullptr)
	{
		if (tempPtr->data > tempPtr->next->data)
		{
			std::swap(tempPtr->data, tempPtr->next->data);
		}
		std::cout << tempPtr->data << "\n" << std::endl;
		tempPtr = tempPtr->next;
	}


}

void DoubleLinkedList::PrintFirstOfList()
{
	std::cout << "The first of the double linked list is: \n" << head->data << std::endl;
}

void DoubleLinkedList::PrintLastOfList()
{
	std::cout << "The last of the double linked list is: \n" << tail->data << std::endl;
}
