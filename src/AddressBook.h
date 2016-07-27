/*
 * AddressBook.h
 *
 *  Created on: 25 jul. 2016
 *      Author: VMeta
 */

#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_
#include <cstdlib>
#include <sstream>
#include "Lista.h"
#include "FileManager.h"


namespace ITLA
{

	class AddressBook
	{
		private:
			Lista* _lista;
			FileManager* _fileManager;
			string _option;
		public:
			Contact* formContact(Contact* contact);
			void editContact();
			void printAllContacts();
			void deleteContatc();
			void printContact(Contact* contact);
			void listContacts();
			void addContatc();
			void printMenu();
			void verifyOption();
			AddressBook();
			virtual ~AddressBook();
		};

	} /* namespace ITLA */

#endif /* ADDRESSBOOK_H_ */
