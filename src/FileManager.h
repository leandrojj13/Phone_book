/*
 * FileManager.h
 *
 *  Created on: 25 jul. 2016
 *      Author: VMeta
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Lista.h"


using namespace std;
namespace ITLA
{

	class FileManager
	{
		private:
			Lista* _lista;
		public:
			Lista* getAllContacts();
			void save();
			FileManager(Lista* lista);
			virtual ~FileManager();
	};

} /* namespace ITLA */

#endif /* FILEMANAGER_H_ */
