#include <iostream>
#include "readDataFileTest.h"


using namespace std;

int main() {
    vector<Movie> movies;

    movies = readFile("movie_data.csv");
    for (int i = 0; i < 10; i++) {
        string title = movies[i].getTitle();
        cout << title << endl;
    }

    return 0;
}
