/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Kevin Quirici
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
using namespace KP_FileIO;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream myFile;
	myFile.open(filename.c_str());

	std::cout << "Read Path: " << filename.c_str() << std::endl;

	if (!myFile.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;

	string line;

	while (getline(myFile, line))
		contents += line;

	myFile.close();
	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myFile;
	myFile.open(filename.c_str());

	std::cout << "Write Path: " << filename.c_str() << std::endl;

	if (!myFile.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;

	vector<string>::iterator vectorIterator;

	for (vectorIterator = myEntryVector.begin(); vectorIterator != myEntryVector.end(); vectorIterator++)
		myFile << *vectorIterator + "\n";

	return SUCCESS;
}


