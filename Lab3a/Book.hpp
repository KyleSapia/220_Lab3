//============================================================================
// Ian Romano, Kyle Sapia
// TA: Daniel Gaston
// 2/22/19
//
// Book.hpp
//============================================================================

#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

class Book {
		string fName;
		string lName;
		int *ratings = new int[10];
		string title;
		int year;

	public:
		Book();
		Book(string fName, string lName, string title, int year);
		Book(string fName, string lName, string title, int year, int ratings[10]);
		~Book();	//destructor
		double avgRating();
		void printAvgRating();
		void printBookInfo();
		bool operator > (Book b);
		bool operator < (Book b);

};

#endif /* BOOK_HPP_ */
