/*
 * FileManager.cpp
 *
 *  Created on: 25 jul. 2016
 *      Author: VMeta
 */

#include "FileManager.h"

namespace ITLA {

	FileManager::FileManager(Lista* lista) : _lista(lista)
	{


	}

	void FileManager::save()
	{
		ofstream output("src/Contact/Contacts.dat");
		Contact* contact = _lista->getFirst();

		if(contact == NULL){
			output << "";
		}else{
			while(contact != NULL){
				output << contact->getName() << endl << contact->getLastName() << endl <<contact->getPhone() << endl << contact->getAddress() << endl;
				contact = contact -> getNext();
			}
		}

	}

	Lista* FileManager::getAllContacts()
	{
		ifstream input("src/Contact/Contacts.dat");
		string linea;
		if(input.fail()){
			cout<< "We're so sorry, we could not access to yours contacts. " << endl;
		}else{
			while(!input.eof()){
				Contact* contact = new Contact();
				getline(input, linea);
				contact->setName(linea);
				getline(input, linea);
				contact->setLastName(linea);
				getline(input, linea);
				contact->setPhone(linea);
				getline(input, linea);
				contact->setAddress(linea);
				if(!contact->getName().empty() && !contact->getLastName().empty() && !contact->getPhone().empty() && !contact->getAddress().empty()){
					_lista->add(contact);
				}
			}
		}

		return _lista;

	}

	FileManager::~FileManager()
	{

	}

} /* namespace ITLA */
