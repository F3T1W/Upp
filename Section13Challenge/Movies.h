#pragma once

#include <vector>
#include <string>

#include "Movie.h"

using namespace std;

class Movies {
private:
	vector<Movie>* movies;

public:
	Movies();

	~Movies();

	void AddMovie(string _name, string _rating, int _watched);

	void PlusWatched(string _name);

	void Display();
};