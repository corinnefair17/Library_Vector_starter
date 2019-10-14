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

	else if (myfile.peek() == std::ifstream::traits_type::eof()) {
		return NO_BOOKS_IN_LIBRARY;
	}

	books.clear();

	// TODO
	std::string line;
	while (myfile.peek() != std::ifstream::traits_type::eof()) {
		getline(myfile, line);
		std::stringstream ss(line);
		std::vector<std::string> lineVector;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');

			lineVector.push_back(substr);
		}
		book b;
		b.book_id = std::atoi(lineVector[0].c_str());
		b.title = lineVector[1];
		b.author = lineVector[2];
		switch (std::atoi(lineVector[3].c_str())) {
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

		if (lineVector[4].compare("-2 ") == 0
				|| lineVector[4].compare("-2") == 0) {
			b.loaned_to_patron_id = NO_ONE;
		} else {
			b.loaned_to_patron_id = std::atoi(lineVector[4].c_str());
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
	int length = books.size();
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

	else if (myfile.peek() == std::ifstream::traits_type::eof()) {
		return NO_PATRONS_IN_LIBRARY;
	}

	patrons.clear();

// TODO
	std::string line;
	while (myfile.peek() != std::ifstream::traits_type::eof()) {
		getline(myfile, line);
		std::stringstream ss(line);
		std::vector<std::string> svector;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			svector.push_back(substr);
		}
		patron p;
		p.patron_id = std::atoi(svector[0].c_str());
		p.name = svector[1];
		p.number_books_checked_out = std::stoi(svector[2]);
	}
	myfile.close();

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
	int length = patrons.size();
	for (int i = 0; i < length; i++) {
		myfile << patrons[i].patron_id << "," << patrons[i].name << ","
				<< patrons[i].number_books_checked_out << std::endl;
	}
	myfile.close();

	return SUCCESS;
}

// For testing
int main() {
	std::vector<book> books;

	loadBooks(books, BOOKFILE.c_str());
	saveBooks(books, TMP_FILE.c_str());
}
