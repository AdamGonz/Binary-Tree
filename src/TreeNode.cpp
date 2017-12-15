/*
 * TreeNode.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: adamgonzalez
 */

#include "TreeNode.hpp"
#include <iostream>
#include <iomanip>

namespace std {
TreeNode::TreeNode() {
	// TODO Auto-generated constructor stub
	Data = 0; //constructor setting data = 0
	Left = nullptr; //constructor setting left TreeNode = nullptr
	Right = nullptr ; //constructor setting right TreeNode = nullptr
	treePtr = nullptr;

}

TreeNode::~TreeNode() {
	// TODO Auto-generated destructor stub
	cout << "Deleting " << Data << endl; // destructor message
}

/***********************************/
	//Public Funtions

/**********************************/
int TreeNode::Height(void){
	return getHeight(treePtr);
}
bool TreeNode::insert(int value){
	temp = new TreeNode();
	temp -> Data = value;
	if(!insertNode(treePtr,temp)){
		cout << "Sorry the value " << temp -> Data << " already exist's" << endl;
		delete temp;
		return false;
	}//if
	else{
		cout << "The value " << temp -> Data << " added successfully" << endl;
		return true;
	}//else
}
void TreeNode::Clear(void){
	return ClearTree(treePtr);
}
void TreeNode::Print(void){
	return PrintTree(treePtr);
}
void TreeNode::reverseOrder(void){
	return PrintReverse(treePtr);
}
void TreeNode::postOrder(void){
	return PrintPost(treePtr);
}
int TreeNode::Size(void){
	return SizeOfTree(treePtr);
}
bool TreeNode::Delete(int value){
	return DeleteTree(treePtr, value);
}
TreeNode* TreeNode::search(int value){
	return searchNode(treePtr, value);
}
int TreeNode::calculateBalance(void){
	return calculateTreeBalance(treePtr);
}

/***************************************************/
		//Private Functions
/***************************************************/
void TreeNode::PrintTree(TreeNode* treePtr){ //function to print out the tree
	if(treePtr == nullptr) //checking if the tree is empty
		return; // if its empty break out
	PrintTree(treePtr -> Left); // traverse to the left
	cout << treePtr -> Data << endl; //print the data
	PrintTree(treePtr -> Right); // then traverse to the right

}

bool TreeNode::insertNode(TreeNode* &treePtr, TreeNode* newNode){// insert node function
	if(treePtr == nullptr){ //checking if the tree is empty
		treePtr = newNode; // if its empty then set the root to the newNode
		return true; // return true to show it was added
	}//if
	else if(newNode -> Data < treePtr -> Data){ // checking if the newNode value is less then the Data in the root if so then were going to the left
		return insertNode(treePtr -> Left, newNode); // adding the new value to the left were it is able to be placed
	}//else if
	else if(newNode -> Data > treePtr -> Data){ // the newNode value is greater then the root value which then means the it will have to be added to the right
		return insertNode(treePtr -> Right, newNode); // adding the new value to the right
	}
	else{
		return false;
	} // return false if no other options
}

void TreeNode::ClearTree(TreeNode* treePtr){ //clearing the whole tree
	if(treePtr == nullptr){ //if tree is empty then nothing to clear
		return; // returning false because then there is nothing to do
	}
	else{
		ClearTree(treePtr -> Right); // traverse to the right
		ClearTree(treePtr -> Left); // traverse to the left
		delete treePtr; //delete the current value of treePtr
	}
	treePtr = nullptr;//set treePtr to nullptr after deleteing everything

}

int TreeNode::SizeOfTree(TreeNode* treePtr){ // determines the size of the tree
	if(treePtr == nullptr){ // checks if the tree is empty
		return 0;
	}
	return(SizeOfTree(treePtr -> Left) + 1 + SizeOfTree(treePtr -> Right)); // adds 1 and takes the left and adds it to the right side
}

void TreeNode::PrintPost(TreeNode* treePtr){
	if(treePtr == nullptr)
		return;
	PrintPost(treePtr -> Left);
	PrintPost(treePtr -> Right);
	cout << treePtr -> Data << endl;

}

void TreeNode::PrintReverse(TreeNode* treePtr){
	if(treePtr == nullptr)
		return;
	PrintReverse(treePtr -> Right);
	cout << treePtr -> Data << endl;
	PrintReverse(treePtr -> Left);
}

bool TreeNode::DeleteTree(TreeNode*& treePtr, int value){
	if(treePtr == nullptr){ // checking if the tree is empty
		return false;
	}//if
	if(treePtr -> Data == value){ //is the value equal to the root value
		if(treePtr -> Left == nullptr && treePtr -> Right == nullptr){ // is the root to the left and right NULL
			delete treePtr; // if both sides are null delete the root
			treePtr = nullptr; //then set it to null ptr
		}//if
		else if(treePtr -> Right != nullptr){ //checking if the right is null
			TreeNode* leftNode = treePtr -> Left; // set the left value to leftNode and save it
			TreeNode* rightNode = treePtr -> Right; //set the right value to the rightNode and save it
			delete treePtr; // delete the root
			treePtr = rightNode; //set the root to the the rightNode
			insertNode(treePtr, leftNode); //add node into tree
			return false; //return false
		}
		else{
			TreeNode* leftNode = treePtr -> Left; // set the value to the leftNode and save it
			delete treePtr; //delete root
			treePtr = leftNode; //set the root to the leftNode
			return false; //return false
		}

	}//if
	else if(value < treePtr -> Data){ //is the value less then the root node if so go to left if not go to right
		return DeleteTree(treePtr -> Left, value); //recursing going to check and delete the value given if its on the left side
	}
	else{
		return  DeleteTree(treePtr -> Right, value); // recursing going to check and delete the value given if its on the right side
	}
	return 0;
}

int TreeNode::getHeight(TreeNode* treePtr){
	if(treePtr == nullptr){ // checking if the tree is empty if it is then return 0 because then there is no height
		return 0;
	}//if
	else{
		int left = getHeight(treePtr -> Left);
		int right = getHeight(treePtr -> Right);
		if(left > right){
			return 1 + left;
		}
		else{
			return 1 + right;
		}
	}
}

TreeNode* TreeNode::searchNode(TreeNode* treePtr, int value){
	if(treePtr == nullptr){
		return nullptr;
	}//if
	else if(treePtr -> Data == value){
		return treePtr;
	}//else if
	else{
		if(value > treePtr -> Data){
			return searchNode(treePtr -> Right, value);
		}//if
		else{
			return searchNode(treePtr -> Left, value);
		}//else
	}//else
}
int TreeNode::calculateTreeBalance(TreeNode*& treePtr){
	if(treePtr == nullptr){
		return 0;
	}
	int left = getHeight(treePtr -> Left) + 1;
	int right = getHeight(treePtr -> Right) + 1;






}
} /* namespace std */
