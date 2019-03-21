/*
 * Lab3b.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: kylesapia
 */


#include "SNode.hpp"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

SNode::SNode() {
	int rating;
	string comments;
	cout << "Enter a numerical rating: ";
	cin >> rating;
	cout << "Enter any comments about the book: ";
	cin >> comments;
	this->rating = rating;
	this->comments = comments;
	next = NULL;
}

SNode::SNode(int r, string c) {
	this->rating = r;
	this->comments = c;
	next = NULL;
}

void SNode::printNode() {
	cout << "Rating: " << rating << endl;
	cout << "Comments: " << comments << endl;

}

SNode::~SNode() {
	cout << "deleting " << rating << ", " << comments << endl;
}


