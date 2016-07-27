//============================================================================
// Name        : Address.cpp
// Author      : VMeta
// Version     :
// Copyright   : Your copyright notice
// Description : Phone book in C++, Ansi-style
//============================================================================

#include "AddressBook.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>


using namespace ITLA;
int main() {

	AddressBook* addressBook = new AddressBook();
	while(true){
		addressBook -> printMenu();
	}
	delete addressBook;
	return 0;
}
