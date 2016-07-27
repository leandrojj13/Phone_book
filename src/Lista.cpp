/*
 * Lista.cpp
 *
 *  Created on: 23 jul. 2016
 *      Author: VMeta
 */

#include "Lista.h"

namespace ITLA
{

	Lista::Lista() : _first(NULL), _last(NULL), _length(0)
	{


	}

	void Lista::add(Contact* nodo)
	{
		if(_first == NULL)
		{
			_first = nodo;
			_last = nodo;
		}else
		{
			_last -> setNext(nodo);
			_last = nodo;
		}
		_length++;

	}

	bool Lista::add(Contact* contact, int indice)
	{
		Contact* reference = get(indice);

		if(reference == NULL){
			return false;
		}
		contact -> setNext(reference -> getNext());
		reference -> setNext(contact);

		_length++;
		return true;
	}

	Contact* Lista::get(int indice)
	{
		int i = 1;
		Contact* iterador = _first;

		while(iterador != NULL){
			if(i == indice){
				return iterador;
			}else{
				iterador = iterador -> getNext();
				i++;
			}
		}
		return NULL;

	}

	bool Lista::erase(int index)
	{

		if(index == 1){
			_first = _first -> getNext();
			_length--;
			return true;
		}
		else{
			int i = 1;
			Contact* iterador = _first;
			Contact* lastIterator;

			while(iterador != NULL){
				if(i == index){
					lastIterator -> setNext( iterador -> getNext());
					delete iterador;
					_length--;
					return true;
				}else{
					lastIterator = iterador;
					iterador = iterador -> getNext();
					i++;
				}
			}
		}
		return false;
	}

	Lista::~Lista()
	{

	}

} /* namespace ITLA */


