/*
 * SLL.cpp
 *
 *  Kyle Sapia and Ian Romano
 */

#include "SNode.hpp"
#include "SLL.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

SLL::SLL() {
	first = NULL;
	last = NULL;
	size = 0;
}

SLL::~SLL() {
	SNode *tmp = first;
	while (first != NULL) {
		delete first;
		tmp = first->next;
		first = tmp;
		size--;
	}
	delete tmp;
	cout<<"deleted each node in 11" << endl;
}

void SLL::printSLL() {
	SNode *tmp = first;
	while (tmp != NULL) {
		//cout << tmp->rating << ",";
		tmp->printNode();
		tmp = tmp->next;
		//cout<<"While1"<<endl;
	}
	cout << endl;
}

void SLL::insertInOrder(int r, string c) {
	if (first == NULL) {
		addFirst(r, c);
	} else if (r < first->rating) {
		addAtFront(r, c);
	} else if (r > last->rating) {
		push(r, c);
	} else {
		SNode *tmp = first;
		SNode *tmp1 = first;

		while (r > tmp1->rating) {
			tmp = tmp1;
			tmp1 = tmp1->next;
			//cout<<"WHile"<<endl;
		}
		SNode *tmp2 = new SNode(r,c);
		tmp->next = tmp2;
		tmp2->next = tmp1;
		size++;
		//size++;
	}

}

void SLL::push(int r, string c) {
	SNode *tmp = new SNode(r, c);
	last->next = tmp;
	last = tmp;
	size++;
}

void SLL::addAtFront(int r, string c) {
	SNode *tmp = new SNode(r, c);
	tmp->next = first;
	first = tmp;
	size++;
}

void SLL::addFirst(int r, string c) {
	SNode *tmp = new SNode(r, c);
	first = last = tmp;
	size = 1;
}

int SLL::pop() {
	int val;
	SNode *tmp = first;
	if (size > 0) {
		val = last->rating;
		if (first != last) {
			tmp = first;
			for (int i = 0; i < size - 2; i++) {
				tmp = tmp->next;
			}
			cout<<"removing " << val << ", " << last->comments << endl;
			//cout<<"deleting " << val << "," << last->comments << endl;
			delete last;
			last = tmp;
			last->next = NULL;
		} else {
			delete last;
			first = NULL;
			last = NULL;
		}
		size--;
		return val;
	} else {
		return -1;
	}
}

double SLL::getAve() {
	SNode *tmp = first;
	double sum = 0;
	while (tmp != NULL) {
		sum += tmp->rating;
		tmp = tmp->next;
	}
	//cout<<sum<<","<<size<<endl;
	return (sum / size);
}
