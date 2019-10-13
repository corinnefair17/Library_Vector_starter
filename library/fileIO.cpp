#include "../includes_usr/fileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char *filename) {
	std::ifstream myfile;
	myfile.open(filename);
	if (myfile.fail()) {
		return COULD_NOT_OPEN_FILE;
	}

	else if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}

	books.clear();

	// TODO
	std::string line;
	while (!myfile.eof()) {
		getline(myfile, line);
		std::stringstream ss(line);
		std::vector<std::string> svector;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			svector.push_back(substr);
		}
		book b;
		b.book_id = std::stoi(svector[0]);
		b.title = svector[1];
		b.author = svector[2];
		switch (std::stoi(svector[3])) {
		case 0:
			b.state = UNKNOWN;
			break;
		case 1:
			b.state = IN;
			break;
		case 2:
			b.state = OUT;
			break;
		default:
			b.state = UNKNOWN;
			break;
		}

		if (svector[4] == "-2") {
			b.loaned_to_patron_id = NO_ONE;
		} else {
			b.loaned_to_patron_id = std::stoi(svector[4]);
		}
		books.push_back(b);
	}
	myfile.close();
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char *filename) {
	std::ofstream myfile;
	myfile.open(filename);
	if (myfile.fail()) {
		return COULD_NOT_OPEN_FILE;
	}

	else if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}

	// TODO
	signed int length = books.size();
	for (int i = 0; i < length; i++) {
		myfile << books[i].book_id << "," << books[i].title << ","
				<< books[i].author << "," << books[i].state << ","
				<< books[i].loaned_to_patron_id << std::endl;
	}
	myfile.close();
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char *filename) {
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
int savePatrons(std::vector<patron> &patrons, const char *filename) {
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
