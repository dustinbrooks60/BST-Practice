/*
 * ElementAlreadyExistsInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class contains the element already
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 

#include "ElementAlreadyExistsInBSTException.h"  

using namespace std;

ElementAlreadyExistsInBSTException::ElementAlreadyExistsInBSTException(const string& message): 
logic_error("Element already exists in BST Exception: " + message)
{
}  // end constructor

// End of implementation file.
