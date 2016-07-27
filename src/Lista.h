/*
 * Lista.h
 *
 *  Created on: 23 jul. 2016
 *      Author: VMeta
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "Contact.h"

namespace ITLA
{

	class Lista
	{
		private:
			Contact* _first;
			Contact* _last;
		public:
			int _length;
			bool erase(int indice);
			Contact* get(int indice);
			void add(Contact* nodo);
			bool add(Contact* nodo, int indice);
			int length();
			Lista();
			virtual ~Lista();

		    Contact* getFirst(){ return _first;}
		    Contact* getLast(){ return _last;}
};

} /* namespace ITLA */

#endif /* LISTA_H_ */
