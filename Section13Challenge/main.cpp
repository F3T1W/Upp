#include "Movies.h"

#include <iostream>

using namespace std;

int main() {

    Movies* movies = new Movies;

    cout << "Movies list created" << endl;

    movies->AddMovie("Gym", "PG", 228);
    
    cout << "Gym movie was added with 228 watched" << endl;

    movies->PlusWatched("Gym");

    cout << "Gym watched field was increased" << endl;

    movies->Display();

    movies->AddMovie("Jaba Mistera Jabroni", "PG-13", 0);

    cout << "Jaba was added" << endl;

    movies->PlusWatched("Jaba Mistera Jabroni");

    cout << "Jaba watched field was increased" << endl;

    movies->Display();

    delete movies;
    
    return 0;
}