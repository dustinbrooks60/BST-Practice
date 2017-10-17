/*
 * ElementDoesNotExistInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class does not contain the element
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 

#include "ElementDoesNotExistInBSTException.h"  

using namespace std;

ElementDoesNotExistInBSTException::ElementDoesNotExistInBSTException(const string& message): 
logic_error("Element does not exist in BST Exception: " + message)
{
}  // end constructor

// End of implementation file.
