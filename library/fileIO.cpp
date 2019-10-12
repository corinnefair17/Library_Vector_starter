#include "../includes_usr/fileIO.h"
#include <iostream>
#include <fstream>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	std::ifstream myfile;
	myfile.open(filename);
	if (myfile.fail()) {
		return COULD_NOT_OPEN_FILE;
	}

	else if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}

	// TODO
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	std::ofstream myfile;
	myfile.open(filename);
	if (myfile.fail()) {
		return COULD_NOT_OPEN_FILE;
	}

	else if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}

	// TODO
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	std::ifstream myfile;
		myfile.open(filename);
		if (myfile.fail()) {
			return COULD_NOT_OPEN_FILE;
		}

		else if (patrons.size() == 0) {
			return NO_PATRONS_IN_LIBRARY;
		}

	// TODO
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	std::ofstream myfile;
		myfile.open(filename);
		if (myfile.fail()) {
			return COULD_NOT_OPEN_FILE;
		}

		else if (patrons.size() == 0) {
			return NO_BOOKS_IN_LIBRARY;
		}

	// TODO
	return SUCCESS;
}
