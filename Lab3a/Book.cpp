//============================================================================
// Ian Romano, Kyle Sapia
// TA: Daniel Gaston
// 2/22/19
//
// Book.cpp
//============================================================================
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Book.hpp"
using namespace std;

Book::Book() {

}

Book::Book(string fName, string lName, string title, int year) {
	this->fName = fName;
	this->lName = lName;
	this->title = title;
	this->year = year;
	for (int i=0; i<10; i++) {
		ratings[i] = 0;
	}
}

Book::Book(string fName, string lName, string title, int year, int rating[]) {
	this->fName = fName;
	this->lName = lName;
	this->title = title;
	this->year = year;
	for (int i=0; i<10; i++) {
		this->ratings[i] = rating[i];
	}
}


Book::~Book() {

}

/*
 * This method returns a book's average rating from it's int ratings[] field
 * Parameters-
 * 		None
 * Returns-
 * 		double avg: Average of its ratings from it's ratings[] field
 */
double Book::avgRating() {
	double avg = 0;
	for (int i=0; i<10; i++)
		avg += ratings[i];
	avg /= 10;
	return avg;
}
/*
 * This method prints a book's average rating using avgRating() method.
 * Parameters-
 * 		None
 * Returns-
 * 		Nothing
 */
void Book::printAvgRating() {
	if (this->avgRating() == 0) {
		cout << "This book has no ratings yet." << endl;
		return;
	} else {
		cout << this->avgRating() << endl;
	}
	return;
}

void Book::printBookInfo() {
	cout << "Book Title: " << this->title << endl;
	cout << "Author: " << this->fName << ' ' << this->lName << endl;
	cout << "Year of Publication: " << this->year << endl;
	cout << "Average Rating: ";
	this->printAvgRating();
	return;
}
/* This is overloading the greater-than (>) operator to return true if this book's rating average is
 *		greater than the other book. Returns false otherwise.
 */
bool Book::operator > (Book b) {
	return this->avgRating() > b.avgRating();
}

/* This is overloading the less-than (<) operator to return true if this book's rating average is
 *		less than the other book. Returns false otherwise.
 */
bool Book::operator < (Book b) {
	return this->avgRating() > b.avgRating();
}
