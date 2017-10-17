/*
 * ElementDoesNotExistsInBSTException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT does not contain the element
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class ElementDoesNotExistInBSTException : public logic_error
{
public:
   ElementDoesNotExistInBSTException(const string& message = "");
   
}; // end ElementDoesNotExistInBSTException
