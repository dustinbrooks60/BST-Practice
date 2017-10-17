/*
 * BST.h
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

 #pragma once

#include "BSTNode.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

using namespace std;

template <class ElementType>
class BST {
	
private:
	BSTNode<ElementType>* root; 
    int elementCount;           

    // Utility methods
    bool insertR(const ElementType& element, BSTNode<ElementType>* current) ; // throw(ElementAlreadyExistsException);

    ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException);


	void traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const;


    void makeEmpty(BSTNode<ElementType>* current);

    int nodesCountR(BSTNode<ElementType>* current);

    ElementType& minR(BSTNode<ElementType>* current);
  
    ElementType& maxR(BSTNode<ElementType>* current);

    void removeR(const ElementType& targetElement, BSTNode<ElementType>* current);

    BSTNode<ElementType>* find_Insucc(BSTNode<ElementType>* current) const;

    BSTNode<ElementType>* find_Inpred(BSTNode<ElementType>* current) const;
         
    int duplicateR(const ElementType& targetElement, BSTNode<ElementType>* current);

    int numberOfLevelsR(BSTNode<ElementType>* current) const;

    BSTNode<ElementType>* findParentR(const ElementType& key, BSTNode<ElementType>* current);

    void deleteMinR(BSTNode<ElementType>* current);
 
    void deleteMaxR(BSTNode<ElementType>* current);

public:
    // Constructors and destructor:
	BST();                               // Default constructor
    BST(ElementType& element);           // Parameterized constructor 
	BST(const BST<ElementType>& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
    // BST operations:

    // Time efficiency: O(1)
	int getElementCount() const;

	// Time efficiency: O(log2 n)
	void insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException);	

	// Time efficiency: O(log2 n)
	ElementType& retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException);

	// Time efficiency: O(n)
	void traverseInOrder(void visit(ElementType&)) const;

        int nodesCount();

        ElementType& min();
 
        ElementType& max();

        void remove(const ElementType& targetElement) throw(ElementDoesNotExistInBSTException);

        int duplicate(const ElementType& targetElement);
	
        int numberOfLevels() const;

        BSTNode<ElementType>* findParent(const ElementType& key);

        bool isBST(BSTNode<ElementType>* current, const ElementType& maxElement, const ElementType& minElement);

        void deleteMin();

        void deleteMax();
   
}; // end BST

#include "BST.cpp"
