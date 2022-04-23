#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include <sstream>
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
    string trash;
    getline(inFile, trash);
    while (getline(inFile, line)) {
        stringstream ss(line);
        string mID;
        string title;
        string releaseYear;
        long popularity;
        string pop;
        string dirID;
        string directorName;

        getline(ss, mID, ',');
        char n = ss.peek();
        if (n == '"') {
            getline(ss, trash, '"');
            getline(ss, title, '"');
            getline(ss, trash, ',');
        }
        else {
            getline(ss, title, ',');
        }

        getline(ss, releaseYear, ',');
        getline(ss, trash, ',');
        getline(ss, trash, ',');
        getline(ss, pop, ',');
        popularity = stol(pop);
        getline(ss, trash, ',');
        char c = ss.peek();
        if (c == '"') {
            getline(ss, trash, '"');
            getline(ss, dirID, '"');
            getline(ss, trash, '"');
            getline(ss, directorName, '"');

        }
        else {
            getline(ss, dirID, ',');
            getline(ss, directorName, ',');
        }
        getline(ss, trash);

        Movie movie(title, mID, releaseYear, popularity, directorName, dirID);
        movies.push_back(movie);

    }
    inFile.close();
    return movies;
}
