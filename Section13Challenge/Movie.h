#pragma once

#include <string>

using namespace std;

class Movie {
private:
	string name;
	string rating;
	int watched;

	Movie(string _name, string _rating, int _watched);

	void Print();

public:
	friend class Movies;
};