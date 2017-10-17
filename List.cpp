/*
 * List.cpp
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: June 2017
 * Author: Dustin Brooks
 */

#include <iostream>
#include <string>
#include "Player.h"
#include "List.h"

using namespace std;



// Default constructor
template <class ElementType>
List<ElementType>::List() {

   elementCount = 0;
   arraySize = 20;
   elements = new ElementType[arraySize];
   
}


// Copy Constructor	
template <class ElementType>
List<ElementType>::List(const List& lst) {

arraySize = lst.arraySize;
ElementType * newList = new ElementType[2 * arraySize];

for (int i = 0; i < arraySize; i++) {

    newList[i] = lst.elements[i];
} 

delete [] elements;
elements = newList;

}




// Destructor
template <class ElementType>
List<ElementType>::~List() {

  arraySize = 0;
  elementCount = 0;
  delete [] elements;

}



// Description: Returns the total element count currently stored in List.
template <class ElementType>
int List<ElementType>::getElementCount() const {

   return elementCount;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
template <class ElementType>
bool List<ElementType>::insert(const ElementType& newElement) {

if (search(newElement) != NULL) {
     return false;
}

int location = 0;
bool toSearch = (location < elementCount);
bool hasRoomToAdd = (elementCount < arraySize);

if (!hasRoomToAdd) {
   
     ElementType* oldArray = elements;
     elements = new ElementType[2 * arraySize];

     for (int i = 0; i < arraySize; i++)
         elements[i] = oldArray[i];

     delete [] oldArray;
     arraySize = 2 * arraySize;
}


while (toSearch) {

    if (elements[location] > newElement)
      toSearch = false;
     
      
    else {
      location++;
      toSearch = (location < elementCount);
}
}

for (int i = elementCount; i > location; i--) 
   elements[i] = elements[i - 1];

elements[location] = newElement;
elementCount++;

return true;
}  

// Description: Remove an element. 
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
template <class ElementType>
bool List<ElementType>::remove( const ElementType& toBeRemoved ) {

if (search(toBeRemoved) == NULL)
  return false;


int location = 0;
bool toSearch = (location < elementCount);

while (toSearch) {

   if (elements[location] == toBeRemoved)
      toSearch = false;

   else {      

      location++;
      toSearch = (location < elementCount); }
}

for (int i = location + 1; i < elementCount; i++) {
    elements[i - 1] = elements[i];
}

elementCount--;

return true;
}


	
// Description: Remove all elements.
template <class ElementType>
void List<ElementType>::removeAll() {

elementCount = 0;
}
   
// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
template <class ElementType>
ElementType* List<ElementType>::search(const ElementType& target) {

bool found = false;
ElementType result = NULL;

for (int i = 0; i < elementCount && !found; i++) {

  if (elements[i] == target) {
     result = elements[i];
     found = true;
}
}


return result;
}
   
// Description: Prints all n elements stored in List in sort order and does so in O(n).
template <class ElementType>
void List<ElementType>::printList() {

for (int i = 0; i < elementCount; i++) 
    elements[i].printPlayer();

}
	




