/*
 * Nodo.h
 *
 *  Created on: 23 jul. 2016
 *      Author: VMeta
 */

#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>

namespace ITLA
{

	class Contact
	{
		private:
			std::string _name;
			std::string _lastName;
			std::string _phone;
			std::string _address;
			Contact* _next;
		public:
			Contact();
			virtual ~Contact();

			Contact* getNext() { return _next;}

			void setNext(Contact* nodo) { _next = nodo; }

			std::string getName() { return _name;}

			void setName(std::string name) { _name = name; }

			std::string getAddress(){ return _address; }

			void setAddress(std::string address) { _address = address; }

			std::string getLastName() { return _lastName; }

			void setLastName(std::string lastName) { _lastName = lastName;}

			std::string getPhone() { return _phone;}

			void setPhone(std::string phone) { _phone = phone; }
};

} /* namespace ITLA */

#endif /* CONTACT_H_ */
