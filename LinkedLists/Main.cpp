#include <iostream>
#include "DoubleLinkedList.h"


int main()
{
	DoubleLinkedList test;
	DoubleLinkedList otherTest;

	test.AddNodeToFront(3);
	test.AddNodeToFront(40);
	test.AddNodeToFront(2);
	test.AddNodeToFront(54);
	test.AddNodeToFront(78);
	test.AddNodeToFront(5);
	std::cout << "Add node to the Front 'pushfront'" << std::endl;


	otherTest.AddNodeToBack(3);
	otherTest.AddNodeToBack(40);
	otherTest.AddNodeToBack(2);
	otherTest.AddNodeToBack(54);
	otherTest.AddNodeToBack(78);
	otherTest.AddNodeToBack(5);
	std::cout << "Add node to the back 'pushback'" << std::endl;
}