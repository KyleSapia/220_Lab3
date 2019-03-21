//============================================================================
// Ian Romano, Kyle Sapia
// TA: Daniel Gaston
// 2/22/19
//
// Lab_3a.cpp
//	This project uses the Class "Book" to create a series of books
//	and print out their info. Requires Book.hpp
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Book.hpp"
using namespace std;

//Function Decelerations
void printLine();
Book bestRated(Book books[], int len);

int main() {
	int bookRatings[10];
	//Problem 1 Header
	cout << "Problem 1" << endl;

	//Creating Book 1
	for (int i=0; i<10; i++) {
		bookRatings[i] = i;
	}
	Book doom("Fabien", "Sanglard", "Game Engine Black Book: DOOM", 2018, bookRatings);

	//Creating Book 2
	for (int i=0; i<10; i++) {
		bookRatings[i] = i + 6;			//This will give knight the highest rating
	}
	Book knight("George R. R.", "Martin", "A Knight of the Seven Kingdoms", 2015, bookRatings);

	//Creating Book 3
	for (int i=0; i<10; i++) {
		bookRatings[i] = i + 2;
	}
	Book papillon("Henri", "Charriere", "Papillon", 1970, bookRatings);

	//Creating Book 4
	for (int i=0; i<10; i++) {
		bookRatings[i] = i + 3;
	}
	Book pillers("Ken", "Follet", "Pillers of the Earth", 1989, bookRatings);

	//Creating Book 5
	for (int i=0; i<10; i++) {
		bookRatings[i] = i + 4;
	}
	Book sematary("Stephen", "King", "Pet Sematary", 1983, bookRatings);

	Book books[5] = {doom, knight, papillon, pillers, sematary};

	cout << "Five books are generated in the array books[5]." << endl;
	cout << "The best rated book of the array is: " << endl;
	cout << endl;

	Book bestBook = bestRated(books, 5);			//This should return "A Knight of the Seven Kingdoms" since it's the highest rated book.
	bestBook.printBookInfo();
	cout << endl;

	printLine();

	//Problem 2 Header
	cout << "Problem 2" << endl;
	cout << "Here we're creating a new book \"Aztec\" on the heap" << endl;
	cout << endl;

	int aztecRatings[] = { 5, 6, 9, 9, 0, 10, 9, 9, 9, 9};
	//Book *aztec = new Book("Gary", "Jennings", "Aztec", 1980, aztecRatings);
	Book *aztec = new Book( "Gary", "Jennings", "Aztec", 1980, aztecRatings);
	aztec->printBookInfo();

	cout << endl;

	printLine();

	//Problem 3 Header
	cout << "Problem 3" << endl;

	Book *books3 = new Book[2];

	for (int i=0; i<10; i++) {
		bookRatings[i] = i;
	}
	Book wolf( "Fabien", "Sanglard", "Game Engine Black Book: Wolfenstein 3D", 2017, bookRatings);

	Book chili( "Joe", "Lansdale", "Bad Chili", 1997);

	books3[0] = wolf;
	books3[1] = chili;

	cout << "An array of books called books3[2] was created on the heap: " << endl;
	cout << endl;
	books3[0].printBookInfo();
	cout << endl;
	books3[1].printBookInfo();

	delete &(books3[1]);
	delete &(books3[0]);

	return 0;
}

void printLine() {
	cout << "**************************************************************************************" << endl;
	return;
}

/*
 * This function sorts through an array of books and returns the book with the greatest average rating
 * Requires "Book.hpp"
 * Parameters:
 * 		Book books[]: an array of books to be sorted.
 * 		int len: the length of the array of books.
 * Returns:
 * 		Book best: The book with the highest rating.
 */
Book bestRated(Book books[], int len) {
	Book best = books[0];
	for (int i=1; i<len; i++) {
		if (books[i] > best)
			best = books[i];
	}
	return best;
}
