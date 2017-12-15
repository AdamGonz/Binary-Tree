//============================================================================
// Name        : binaryTree.cpp
// Author      : Adam Gonzalez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TreeNode.hpp"
#include "utilities.hpp"

using namespace std;


int main() {
	//will contain root node of tree

	TreeNode* tree = new TreeNode();

	tree -> insert(5);
	tree -> insert(10);
	tree -> insert(15);
	tree -> insert(20);
	tree -> insert(25);
	tree -> insert(30);
	tree -> insert(35);
	tree -> insert(40);
	tree -> insert(45);
	tree -> insert(50);




	cout << "\n\n\nPrinting Out The Tree In Order!" << endl;
	cout << "\n-------------------------------\n";
	tree -> Print();

	cout << "\n\nPrinting Out The Tree In Reverse Order!" << endl;
	cout << "\n-------------------------------\n";
	tree -> reverseOrder();

	cout << "\n\nPrinting Out The Tree In Post Order!" << endl;
	cout << "\n-------------------------------\n";
	tree -> postOrder();

	cout << "\n\nPrinting Out The Size Of The Tree!" << endl;
	cout << "\n-------------------------------\n";
	cout << tree -> Size() << "\n\n";

	cout << "\n\nHeight of The Tree!" << endl;
	cout << "\n-------------------------------\n";
	cout << tree -> Height() << "\n\n";

	cout << "\n\nBalance Factor!" << endl;
	cout << "\n-------------------------------\n";

	cout << "\n\nBalance Factor!" << endl;
	cout << "\n-------------------------------\n";
	cout << tree -> calculateBalance();

	cout << "\n\nDelete for 600!" << endl;
	cout << "\n-------------------------------\n";

	cout << "\n\nDeleting The Tree!" << endl;
	cout << "\n-------------------------------\n";
	tree -> Clear();



	cout << "Program is now ending, Please have a good day!" << endl; // prints end message
	return 0;
}//main

