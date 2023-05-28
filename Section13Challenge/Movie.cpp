#include "Movie.h"

#include <iostream>

Movie::Movie(string _name, string _rating, int _watched) :
	name(_name), rating(_rating), watched(_watched)
{};

void Movie::Print() {
	cout << Movie::name << " " << Movie::rating << " " << watched << endl;
}