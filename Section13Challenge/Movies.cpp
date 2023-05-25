#include "Movies.h"

Movies::Movies() {
	movies = new vector<Movie>;
}

Movies::~Movies() {
	delete movies;
}

void Movies::AddMovie(string _name, string _rating, int _watched) {
	movies->push_back(Movie(_name, _rating, _watched));
};

void Movies::PlusWatched(string _name) {
	for (auto& c : *movies) {
		if (c.name == _name)
		{
			c.watched++;
		}
	}
}

void Movies::Display() {
	for (auto& c : *movies)
	{
		c.Print();
	}
}