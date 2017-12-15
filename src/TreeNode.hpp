/*
 * TreeNode.hpp
 *
 *  Created on: Oct 16, 2017
 *      Author: adamgonzalez
 */
#include <iostream>
#ifndef TREENODE_HPP_
#define TREENODE_HPP_

namespace std {
class TreeNode {
public:
	TreeNode();
	virtual ~TreeNode();
	int Data;
	bool insert(int);
	int Height(void);
	void Clear(void);
	void Print(void);
	void reverseOrder(void);
	void postOrder(void);
	int Size(void);
	bool Delete(int);
	int calculateBalance(void);
	TreeNode* search(int);
	TreeNode* temp;
private:
	TreeNode* treePtr;
	TreeNode* Left;
	TreeNode* Right;
	int getHeight(TreeNode*);
	bool insertNode(TreeNode*&, TreeNode*);
	int calculateTreeBalance(TreeNode*&);
	void ClearTree(TreeNode*);
	void PrintTree(TreeNode*);
	void PrintReverse(TreeNode*);
	int SizeOfTree(TreeNode*);
	void PrintPost(TreeNode*);
	bool DeleteTree(TreeNode*&, int);
	TreeNode* searchNode(TreeNode* treePtr, int);

};

} /* namespace std */

#endif /* TREENODE_HPP_ */
