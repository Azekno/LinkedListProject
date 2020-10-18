#include <string>
#include "DoubleLinkedList.h"


int main()
{
	bool programExecuting = false;
	bool programStart = true;
	DoubleLinkedList doubLink;
	doubLink.InitList();

	std::string userInput;
	std::string userDataInput;
	int newNode;
	int selectedIntNode;

	while (programStart)
	{
		system("cls");
		std::cout << "Welcome to my Double Linked List program." << std::endl;
		std::cout << "(Please type out what you wish to do, copying what is presented in the following.)" << std::endl;
		std::cout << "***Please note that all command entered are designened for lower case***\n" << std::endl;
		std::cout << "Add node to front, type in 'add front'\n" << std::endl;
		std::cout << "Add node to back, type in 'add back'\n" << std::endl;
		std::cout << "Add node arbitrarily, type in 'add arb'\n" << std::endl;
		std::cout << "Delete nodes to front, type in 'delete front'\n" << std::endl;
		std::cout << "Delete nodes to back, type in 'delete back'\n" << std::endl;
		std::cout << "Delete nodes arbitrarily, type in 'delete arb'\n" << std::endl;
		std::cout << "To search for nodes, type in 'search'\n" << std::endl;
		std::cout << "Print nodes in the list, type in 'print list'\n" << std::endl;
		std::cout << "To quit the application type in 'quit'\n" << std::endl;
		programExecuting = true;
		std::getline(std::cin, userInput);
		while (programExecuting)
		{
			if (userInput == "add front")
			{
				system("cls");
				std::cout << "Input the number you wish to enter into the front of the Double Linked List" << std::endl;
				std::cout << "***Please note that all data entered can only be numbers***" << std::endl;
				std::cin >> userDataInput;
				
				try
				{
					newNode = stoi(userDataInput);
				}
				catch(...)
				{
					std::cout << "Invalid input" << std::endl;
					doubLink.PrintLinkedListContents();
					std::cout << "\nPress enter to continue\n" << std::endl;
					std::cin.get();
					system("pause");
					break;
				}
				doubLink.AddNodeToFront(newNode);
				std::cout << "Successfully added a node to the front of the double linked list" << std::endl;
				doubLink.PrintLinkedListContents();
				std::cout << "Press enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "add back")
			{
				system("cls");
				std::cout << "Input the number you wish to enter to the back of the Double Linked List" << std::endl;
				std::cin >> userDataInput;
				try
				{
					newNode = stoi(userDataInput);
				}
				catch (...)
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Press enter to continue\n" << std::endl;
					std::cin.get();
					system("pause");
					break;
				}
				
				doubLink.AddNodeToBack(newNode);
				std::cout << "Successfully added a node to the back of the double linked list" << std::endl;
				doubLink.PrintLinkedListContents();
				std::cout << "\nPress enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "add arb")
			{
				system("cls");
				std::string selectedNode;

				std::cout << "Input the node you wish to input data after" << std::endl;
				std::cin >> selectedNode;
				try
				{
					selectedIntNode = stoi(selectedNode);
				}
				catch (...)
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Press enter to continue\n" << std::endl;
					std::cin.get();
					system("pause");
					break;
				}

				std::cout << "Input the data you wish to enter into the double linked list" << std::endl;
				std::cin >> userDataInput;

				try
				{
					newNode = stoi(userDataInput);
				}
				catch (...)
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Press enter to continue\n" << std::endl;
					std::cin.get();
					system("pause");
					break;
				}
				
				doubLink.AddArbitraryNode(selectedIntNode, newNode);
				std::cout << "Successfully added the selected node to the double linked list" << std::endl;
				doubLink.PrintLinkedListContents();
				std::cout << "\nPress enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "delete front")
			{
				system("cls");

				doubLink.DeleteNodeAtFront();
				std::cout << "Successfully deleted the front of the double linked list\n" << std::endl;
				doubLink.PrintLinkedListContents();
				std::cout << "\nPress enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "delete back")
			{
				system("cls");

				doubLink.DeleteNodeAtBack();
				std::cout << "Successfully delete the back of the double linked list\n" << std::endl;
				doubLink.PrintLinkedListContents();
				std::cout << "\nPress enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "delete arb")
			{
				system("cls");
				std::cout << "Type in the value you wish to delete in the double linked list" << std::endl;
				std::cin >> userDataInput;
				
				try
				{
					newNode = stoi(userDataInput);
				}
				catch (...)
				{
					std::cout << "Invalid input" << std::endl;
					std::cout << "Press enter to continue\n" << std::endl;
					std::cin.get();
					system("pause");
					break;
				}

				doubLink.DeleteArbitraryNode(newNode);
				
				doubLink.PrintLinkedListContents();
				std::cout << "\nPress enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "search")
			{
				system("cls");
				std::cout << "Type in the value you wish to search for." << std::endl;
				std::cin >> userDataInput;
				newNode = stoi(userDataInput);
				Node* searchResult = doubLink.SearchNodes(newNode);

				if (searchResult != nullptr)
				{
					std::cout << "The value is in the double linked list" << searchResult->data << std::endl;
				}
				else
				{
					std::cout << "The value is not within the double linked list" << std::endl;
				}
				break;
			}
			else if (userInput == "print list")
			{
			doubLink.IsListEmpty();
			system("cls");
				while (true)
				{
					std::cout << "What would you like to print" << std::endl;
					std::cout << "Typing in 'print list' will print the contents of the Double Linked List unsorted" << std::endl;
					std::cout << "Typing in 'print sort' will print the sorted contents of the Double Linked List" << std::endl;
					std::cout << "Typing in 'print first' will print the first of the Double Linked List" << std::endl;
					std::cout << "Typing in 'print last' will print the last of the Double Linked List" << std::endl;
					std::cin >> userInput;
					if (userInput == "print list")
					{
						doubLink.PrintLinkedListContents();
						std::cout << "Press enter to continue\n" << std::endl;
						std::cin.get();
						system("pause");
						break;
					}
					else if (userInput == "print sort")
					{
						doubLink.PrintSortedLinkedListContents();
						std::cout << "Press enter to continue\n" << std::endl;
						std::cin.get();
						system("pause");
						break;
					}
					else if (userInput == "print first")
					{
						doubLink.PrintFirstOfList();
						std::cout << "Press enter to continue\n" << std::endl;
						std::cin.get();
						system("pause");
						break;
					}
					else if (userInput == "print last")
					{
						doubLink.PrintLastOfList();
						std::cout << "Press enter to continue\n" << std::endl;
						std::cin.get();
						system("pause");
						break;
					}
				}
				std::cout << "Press enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
			else if (userInput == "quit")
			{
				//To quit the application
				std::cout << "The console is closing" << std::endl;
				programExecuting = false;
				programStart = false;
			}
			else
			{
				system("cls");
				std::cout << "Invalid command has been input. Try again\n" << std::endl;
				std::cout << "Press enter to continue\n" << std::endl;
				std::cin.get();
				system("pause");
				break;
			}
		}
	}
}