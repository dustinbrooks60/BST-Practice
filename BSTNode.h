/*
 * BSTNode.h
 *
 * Class Definition: Node for a BST 
 *                   in which the data is of Player class type.
 *
 * Created on: Oct 16th
 * Author: Dustin Brooks
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once
#include <cstdio>

template <class ElementType>
class BSTNode
{
public:

	ElementType data;   // The data in the node
	BSTNode<ElementType>* left;   // Pointer to left node
    BSTNode<ElementType>* right;  // Pointer to right node
	
	// Constructors and destructor
	BSTNode();
        ~BSTNode();
	BSTNode(const ElementType& theData);
	BSTNode(const ElementType& theData, BSTNode<ElementType>* theLeftNode, BSTNode<ElementType>* theRightNode);

}; // end Node



template <class ElementType>
BSTNode<ElementType>::BSTNode()
{
	left = NULL;
    right = NULL;
}


template <class ElementType>
BSTNode<ElementType>::~BSTNode()
{
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(const ElementType& theData)
{
	data = theData;
	left = NULL;
    right = NULL;
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(const ElementType& theData, BSTNode<ElementType>* theLeftNode, BSTNode<ElementType>* theRightNode)
{
	data = theData;
	left = theLeftNode;
    right = theRightNode;
}


