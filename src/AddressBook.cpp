/*
 * AddressBook.cpp
 *
 *  Created on: 25 jul. 2016
 *      Author: VMeta
 */

#include "AddressBook.h"


namespace ITLA {

	AddressBook::AddressBook() : _lista(new Lista()), _fileManager(new FileManager(_lista))
	{
		_fileManager->getAllContacts();
	}

	void AddressBook::printMenu()
	{
	  cout <<"\n\n\t\t\tWelcome to VMeta Phone Book\n"<< endl;
	  cout <<"You have to choose an option (Type the number of the option do you want to execute): \n"<< endl;
	  cout <<"1. List Contacts"<< endl;
	  cout <<"2. Add Contact"<< endl;
	  cout <<"3. Update Contact"<< endl;
	  cout <<"4. Delete Contact"<< endl;
	  cout <<"5. Exit"<< endl;
	  cout <<"\nType your option: ";
	  cin >> _option;
	  cout << endl;
	  verifyOption();

	}

	void AddressBook::verifyOption() {
        while(!(_option == "1" || _option == "2" || _option == "3" || _option == "4" || _option == "5")){
        	cout <<"Try again please you type an invalid option: ";
             cin >> _option;
         }

        if(_option == "1"){
        	listContacts();
        }
        else if(_option == "2"){
        	addContatc();
        }

        else if(_option == "3"){
        	editContact();
        }
        else if(_option == "4"){
        	deleteContatc();
        }
        else{
        	cout << "See, back soon" << endl;
        	exit(EXIT_SUCCESS);
        }
        _option="";
	}

	void AddressBook::addContatc() {
		cout <<"Entering contact"<< endl;
		_lista->add(formContact(new Contact()));
		_fileManager->save();
		cout <<"Book Added. Press ENTER to return to the main menu...";
	    cin.ignore();
	    cin.get();
	}

	void AddressBook::listContacts()
	{
		Contact* iterator = _lista -> getFirst();

		if(iterator == NULL){
			cout <<"You don't have any items in you shopping list, you'll be return to the main menu."<< endl;
			cout <<"Press enter to continue..";
		    cin.ignore();
		    cin.get();
		}else{
			cout <<"Contacts List:"<< endl;
			printAllContacts();
			cout <<"Press enter to continue..";
		    cin.ignore();
		    cin.get();
		}
	}

	void AddressBook::printContact(Contact* contact)
	{
		cout << "   Name: " << contact -> getName() << endl;
		cout << "   Last Name: " << contact -> getLastName() << endl;
		cout << "   Phone number: " << contact -> getPhone() << endl;
		cout << "   Address: " << contact -> getAddress() << endl;
		cout << "==============================Divisor==============================" << endl;
	}

	void AddressBook::deleteContatc()
	{
		Contact* iterator = _lista -> getFirst();

		if(iterator == NULL){
			cout <<"You don't have any items in you shopping list, you'll be return to the main menu."<< endl;
			cout <<"Press enter to continue..";
		    cin.ignore();
		    cin.get();
		}else{
			cout <<"Eliminated contacts:"<< endl;
			printAllContacts();
			cout <<"Select the contact' number to delete: ";
			cin >> _option;
			int indice =  atoi(_option.c_str());

			while(!_lista->erase(indice)){
				cout <<"Try again please you type an invalid index: ";
				cin >> _option;
				indice =  atoi(_option.c_str());
			}
			_fileManager->save();
			cout <<"Contact deleted. Press ENTER to return to the main menu...";
		    cin.ignore();
		    cin.get();
		}
	}

	void AddressBook::printAllContacts(){
		Contact* iterator = _lista -> getFirst();
		int i = 1;
		while(iterator != NULL){
			cout << "Contact " << i << ":"  << endl;
			printContact(iterator);
			iterator = iterator->getNext();
			i++;
		}
		cout <<  endl;
	}

	void AddressBook::editContact()
	{
		Contact* iterator = _lista -> getFirst();

		if(iterator == NULL){
			cout <<"You don't have any items in you shopping list, you'll be return to the main menu."<< endl;
			cout <<"Press enter to continue..";
		    cin.ignore();
		    cin.get();
		}else{
			cout <<"Edited contacts:"<< endl;
			printAllContacts();
			cout <<"Select the contact' number to edit: ";
			cin >> _option;
			int indice =  atoi(_option.c_str());
			Contact* contactEdited = _lista->get(indice);
			while(!contactEdited){
				cout <<"Try again please you type an invalid index: ";
				cin >> _option;
				indice =  atoi(_option.c_str());
				contactEdited = _lista->get(indice);
			}
			formContact(contactEdited);
			_fileManager->save();
			cout <<"Contact edited. Press ENTER to return to the main menu...";
		    cin.ignore();
		    cin.get();
		}

	}

	Contact* AddressBook::formContact(Contact* contact)
	{
		cout <<"Contact's name: ";
		cin >> _option;
		contact->setName(_option);
		cout << "Contact's last name: ";
		cin >> _option;
		contact->setLastName(_option);
		cout <<"Contact's phone: ";
		cin >> _option;
		contact->setPhone(_option);
		cout <<"Contact's address: ";
		cin >> _option;
		contact->setAddress(_option);
		return contact;
	}

	AddressBook::~AddressBook()
	{
		Contact* iterator = _lista->getFirst();

		while(iterator != NULL){
			delete iterator;
			iterator = iterator->getNext();
		}
		delete _fileManager;
		delete _lista;
	}

} /* namespace ITLA */
