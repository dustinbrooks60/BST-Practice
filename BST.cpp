/*
 * BST.cpp
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

using namespace std;

template <class ElementType>
bool BST<ElementType>::insertR(const ElementType& element, BSTNode<ElementType>* current) {
   

if (element == current->element) 
    throw ElementAlreadyExistsInBSTException("The element already exists");


if (element < current->element) {

         if (current->hasLeft() == false) {
            current->left = new BSTNode<ElementType>(element, NULL, NULL);
            elementCount++;
}

         else {
             insertR(element, current->left);
}
}

else  {

        if (current->hasRight() == false) {
          current->right = new BSTNode<ElementType>(element, NULL, NULL);
          elementCount++;
}
    
        else {
         insertR(element, current->right);
}
}

return true;
}
         


 // throw(ElementAlreadyExistsException);

template <class ElementType>
ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException) {

   if (current == NULL)
     throw ElementDoesNotExistInBSTException("The element is not in the BST");

     else if (current->element == targetElement)
       return current->element;

     else if (targetElement < current->element)
       return retrieveR(targetElement, current->left);

     else 
       return retrieveR(targetElement, current->right);


}

template <class ElementType>
void BST<ElementType>::traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const {

    if (current == NULL) 
      return;

    traverseInOrderR(visit, current->left);

    visit(current->element);

    traverseInOrderR(visit, current->right);
}

template <class ElementType>    
void BST<ElementType>::makeEmpty(BSTNode<ElementType>* current) {

    if (current != NULL) {

       makeEmpty(current->left);

       delete current->element;
       current->element = NULL;
       delete current;
       current = NULL;
       
       makeEmpty(current->right);
}
}
           
template <class ElementType>
int BST<ElementType>::nodesCountR(BSTNode<ElementType>* current) {

   if (current == NULL)
  return 0;

else {

int counter = 1;

if (current->left != NULL) {
  counter += nodesCountR(current->left);
}

if (current->right != NULL) {
  counter += nodesCountR(current->right);

}

return counter;
}
}



//Returns the minimum element
template <class ElementType>
ElementType& BST<ElementType>::minR(BSTNode<ElementType>* current) {

     if (current == NULL) {
       cout << "No minimum because tree is empty" << endl;
}       
       

     if (current->left == NULL)
       return current->element;


     else
        return minR(current->left);
}


//Returns the maximum element
template <class ElementType>
ElementType& BST<ElementType>::maxR(BSTNode<ElementType>* current) {

     if (current == NULL) {
       cout << "No maximum because tree is empty" << endl;
}       
       

     if (current->right == NULL)
       return current->element;


     else
        return maxR(current->right);
}





//Recursive Remove
template <class ElementType>
void BST<ElementType>::removeR(const ElementType& targetElement, BSTNode<ElementType>* current) {

 BSTNode<ElementType>* succ;
 BSTNode<ElementType>* pred;
    
int flag = 0, delcase;
    //step to find location of node

while (current != NULL && flag != 1)
    {
        if (targetElement < current->element){
            pred = current;
            current = current->left;
        }

        else if (targetElement > current->element) {
            pred = current;
            current = current->right;
        }

        else {
            flag = 1;
        }
    }

    if (flag == 0)
      throw ElementDoesNotExistInBSTException("The element is not in the BST!");
    

//Decide the  case of deletion
if (current->left == NULL && current->right == NULL)
        delcase = 1; //Node has no children

if (current->left != NULL && current->right != NULL)
        delcase = 3; //Node contains children on both sides

else
        delcase = 2; //Node contains only one child


//Deletion Case 1
if (delcase == 1) {

        if (pred->left == current) //if the node is a left child
            pred->left = NULL;     
            pred->right = NULL;

        delete current;
        elementCount--;
        
                  
    }

//Deletion Case 2
if (delcase == 2) {

        if (pred->left == current) { //if the node is a left child

            if(current->left == NULL)
                pred->left = current->right;
            else
                pred->left = current->left;
        }

        else {

            if (current->left==NULL)
                pred->right = current->right;
            else
                pred->right = current->left;
        }

        delete current;
        elementCount--;
        
       
    }

//Deletion case 3
if (delcase == 3) {

        succ = find_Insucc(current); //Find the in_order successor

        ElementType item = succ->element;
        removeR(item, current);  //Delete the inorder successor
        current->element = item; //Replace the data with the data of inorder
    }

}



//Finds the predecessor
template <class ElementType>
BSTNode<ElementType>* BST<ElementType>::find_Inpred(BSTNode<ElementType>* current) const {

BSTNode<ElementType>* pred = current->left;

if (pred != NULL) {

while (pred->right != NULL)
  pred = pred->right;
}

return pred;
}



//Finds the successor
template <class ElementType>
BSTNode<ElementType>* BST<ElementType>::find_Insucc(BSTNode<ElementType>* current) const {

BSTNode<ElementType>* succ = current->right;

if (succ != NULL) {

while (succ->left != NULL)
  succ = succ->left;
}

return succ;
}




//Returns the number of duplicate elements
template <class ElementType>
int BST<ElementType>::duplicateR(const ElementType& targetElement, BSTNode<ElementType>* current) {

int counter = 0;

if (current == NULL)
  return counter;

counter += duplicateR(targetElement, current->left);
 
if (targetElement == current->element)
  counter += 1;

counter += duplicateR(targetElement, current->right);
  
return counter;


}


//Max Depth or "Height" of the tree
//Recursive Helper for numberOfLevels
template <class ElementType>
int BST<ElementType>::numberOfLevelsR(BSTNode<ElementType>* current) const {

if (current == NULL)
  return 0;

else {

  int leftDepth = numberOfLevelsR(current->left);
  int rightDepth = numberOfLevelsR(current->right);

return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}
}




//Find the parent node of the key value -- can adjust to find the parent value
template <class ElementType>
BSTNode<ElementType>* BST<ElementType>::findParentR(const ElementType& key, BSTNode<ElementType>* current) {

if (current == NULL)
  return;


if ((current->left != NULL && current->left->element == key) || (current->right != NULL && current->right->element == key))
   return current;
   


if (key < current->element)
   findParent(key, current->left);

else findParent(key, current->right);
}




//Delete Min helper
template <class ElementType>
void BST<ElementType>::deleteMinR(BSTNode<ElementType>* current) {

BSTNode<ElementType>* temp = current;

if (current == NULL)
  return;

while (temp->left->left != NULL) {

   temp = temp->left;
}

temp->left = NULL;
delete temp->left;
elementCount--;
}


//Delete Max Helper
template <class ElementType>
void BST<ElementType>::deleteMaxR(BSTNode<ElementType>* current) {

if (current == NULL)
  return;

if (current->right)
  return deleteMaxR(current->right);

BSTNode<ElementType>* temp = current;

current = current->left;

temp = NULL;
delete temp;
elementCount--;



}





    

    // Constructors and destructor:
template <class ElementType>
BST<ElementType>::BST() {
      root = NULL;
      elementCount = 0;
}
    
template <class ElementType>                           
BST<ElementType>::BST(ElementType& element) {
       root->element = element;
       elementCount = 1;
} 

/*
template <class ElementType>
BST<ElementType>::BST(const BST<ElementType>& aBST); */



template <class ElementType>
BST<ElementType>::~BST() {

     makeEmpty(root);
}                             // Destructor 
	
    // BST operations:

// Time efficiency: O(1)
template <class ElementType>
int BST<ElementType>::getElementCount() const {

       return elementCount;
}

            

// Time efficiency: O(log2 n)
template <class ElementType>
void BST<ElementType>::insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException) {


      if (root != NULL) {
        insertR(newElement, root);
}

      else {
  
        root = new BSTNode<ElementType>(newElement, NULL, NULL);
        elementCount++;
}


      return;
       
}

	// Time efficiency: O(log2 n)
template <class ElementType>
ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException) {

          return retrieveR(targetElement, root);
}

	// Time efficiency: O(n)
template <class ElementType>
void BST<ElementType>::traverseInOrder(void visit(ElementType&)) const {

           traverseInOrderR(visit, this->root);

           return;
   
}


template <class ElementType>
int BST<ElementType>::nodesCount() {

    return nodesCountR(root);
}


template <class ElementType>
ElementType& BST<ElementType>::min() {

  return minR(root);

}


template <class ElementType>
ElementType& BST<ElementType>::max() {

  return maxR(root);
}




//Recursive remove without helper function -- does not decrement elementCount

/*
template <class ElementType>
void BST<ElementType>::remove(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException) {

 BSTNode<ElementType>* current = root;
 BSTNode<ElementType>* succ;
 BSTNode<ElementType>* pred;
    
int flag = 0, delcase;
    //step to find location of node

while (current != NULL && flag != 1)
    {
        if (targetElement < current->element){
            pred = current;
            current = current->left;
        }

        else if (targetElement > current->element) {
            pred = current;
            current = current->right;
        }

        else {
            flag = 1;
        }
    }

    if (flag == 0)
      throw ElementDoesNotExistInBSTException("The element is not in the BST!");
    

//Decide the  case of deletion
if (current->left == NULL && current->right == NULL)
        delcase = 1; //Node has no children

if (current->left != NULL && current->right != NULL)
        delcase = 3; //Node contains children on both sides

else
        delcase = 2; //Node contains only one child


//Deletion Case 1
if (delcase == 1) {

        if (pred->left == current) //if the node is a left child
            pred->left = NULL;     
            pred->right = NULL;

        delete current;
        
                  
    }

//Deletion Case 2
if (delcase == 2) {

        if (pred->left == current) { //if the node is a left child

            if(current->left == NULL)
                pred->left = current->right;
            else
                pred->left = current->left;
        }

        else {

            if (current->left==NULL)
                pred->right = current->right;
            else
                pred->right = current->left;
        }

        delete current;
        
       
    }

//Deletion case 3
if (delcase == 3) {

        succ = find_Insucc(current); //Find the in_order successor

        ElementType item = succ->element;
        remove(item);  //Delete the inorder successor
        current->element = item; //Replace the data with the data of inorder
    }

}

*/


template <class ElementType>
void BST<ElementType>::remove(const ElementType& targetElement) throw(ElementDoesNotExistInBSTException) {

return removeR(targetElement, root);
}






template <class ElementType>
int BST<ElementType>::duplicate(const ElementType& targetElement) {

return duplicateR(targetElement, root);
}


//Description: Returns the number of levels found in this BST.
template <class ElementType>
int BST<ElementType>::numberOfLevels() const {

  return numberOfLevelsR(root);
}



template <class ElementType>
BSTNode<ElementType>* BST<ElementType>::findParent(const ElementType& key) {

return findParentR(key, root);

}



template <class ElementType>
bool BST<ElementType>::isBST(BSTNode<ElementType>* current, const ElementType& maxElement, const ElementType& minElement) {

if (!current)
  return true;


if (current->element < minElement || current->element > maxElement)
   return false;

return isBST(current->left, current->element, minElement) && isBST(current->right, maxElement, current->element);
}


template <class ElementType>
void BST<ElementType>::deleteMin() {

return deleteMinR(root);

}


template <class ElementType>
void BST<ElementType>::deleteMax() {

return deleteMaxR(root);
}




