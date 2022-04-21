#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include "MovieManagerTest.h"
using namespace std;

vector<Movie> readFile(string fileName) {

    vector<Movie> movies;

    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Warning: File failed to open" << endl;
    }

    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        string mID;
        string title;
        string releaseYear;
        long popularity;
        string pop;
        string dirID;
        string directorName;

        getline(inFile, mID, ',');
        char n = inFile.peek();
        if (n == '"') {
            getline(inFile, line, '"');
            getline(inFile, title, '"');
            getline(inFile, line, ',');
        }
        else {
            getline(inFile, title, ',');
        }

        getline(inFile, releaseYear, ',');
        getline(inFile, line, ',');
        getline(inFile, line, ',');
        getline(inFile, pop, ',');
        popularity = stol(pop);
        getline(inFile, line, ',');
        char c = inFile.peek();
        if (c == '"') {
            getline(inFile, line, '"');
            getline(inFile, dirID, '"');
            getline(inFile, line, '"');
            getline(inFile, directorName, '"');

        }
        else {
            getline(inFile, dirID, ',');
            getline(inFile, directorName, ',');
        }
        getline(inFile, line);

        Movie movie(title, mID, releaseYear, popularity, directorName, dirID);
        movies.push_back(movie);
    }
    inFile.close();
    return movies;
}
