#include <iostream>
#include <string>
#include <iostream>
#include "readDataFileTest.h"
#include "heapImplementationTest.h"
#include "mapImplementation.h" 



using namespace std;
void printMenu() {
    cout << "--------------------" << endl;
    cout << "0. Exit\n";
    cout << "1. Print 10 Popular Movies\n";
    cout << "2. Print 10 Unpopular Movies\n";
    cout << "3. Search by Title\n";
    cout << "4. Search by Year \n";
    cout << "5. Search by Range of Years\n";
    cout << "6. Search by Director\n";
    cout << "\nSelect a Menu Option: ";
}

int main() {


    vector<Movie> movies;

    movies = readFile("movie_data.csv");

    bool exit = false;
    int n = 0;
    string t, y, y1, p;
    movieMap map = movieMap();
    map.addCollection(movies);

    minHeap min = minHeap();
    maxHeap max = maxHeap();
    for (int i = 0; i < movies.size(); i++) {
        min.insertMovie(movies[i]);
        max.insertMovie(movies[i]);
    }
    minHeap unpopularMovies = minHeap();
    maxHeap popularMovies = maxHeap();
    minHeap minYear = minHeap();
    maxHeap maxYear = maxHeap();
    vector<Movie> year;
    vector<Movie> dirMovies;
    while (exit != true) {
        printMenu();
        cin >> n;
        switch (n)
        {
        case 0:
            exit = true;
            break;
        case 1:
            cout << endl;
            popularMovies = max;
            for (unsigned int i = 0; i < 10; i++) {
                Movie m = popularMovies.extractMax();
                cout << m.getTitle() << "(" << m.getYear() << ")" << endl;
                cout << "Popularity Score: " << m.getPopularity() << endl;
                cout << endl;
            }

            break;
        case 2:
            cout << endl;
            unpopularMovies = min;
            for (int i = 0; i < 10; i++) {
                Movie m = unpopularMovies.extractMin();
                cout << m.getTitle() << "(" << m.getYear() << ")" << endl;
                cout << "Popularity Score: " << m.getPopularity() << endl;
                cout << endl;
            }
            break;
        case 3:
            cout << endl;
            cout << "Insert Title:\n" << endl;
            getline(cin, t);
            getline(cin, t);
            map.getInfo(t);
            break;
        case 4:
            cout << endl;
            cout << "Insert Year: ";
            cin >> y;
            year = map.getMovieYear(map.mMap, y);
            minYear.resetMinHeap();
            maxYear.resetMaxHeap();
            for (int i = 0; i < year.size(); i++) {
                minYear.insertMovie(year[i]);
                maxYear.insertMovie(year[i]);
            }
            cout << endl;
            cout << "1. More Popular" << endl;
            cout << "2. Less Popular" << endl;
            cout << "Choose Popularity Level: ";
            cin >> p;
            cout << endl;
            if (p == "1") {
                for (unsigned int i = 0; i < 10; i++) {
                    Movie m = maxYear.extractMax();
                    cout << m.getTitle() << " (" << m.getYear() << ")";
                    cout << " - Dir. by: " << m.getDirectorName() << endl;
                    cout << "Popularity Score: " << m.getPopularity() << endl;
                    cout << endl;
                }
            }
            else if (p == "2") {
                for (int i = 0; i < 10; i++) {
                    Movie m = minYear.extractMin();
                    cout << m.getTitle() << " (" << m.getYear() << ")";
                    cout << " - Dir. by: " << m.getDirectorName() << endl;
                    cout << "Popularity Score: " << m.getPopularity() << endl;
                    cout << endl;
                }
            }
            break;
        case 5:
            cout << endl;
            cout << "Insert First Year: ";
            cin >> y;
            cout << "Insert Last Year: ";
            cin >> y1;
            minYear.resetMinHeap();
            maxYear.resetMaxHeap();
            for (int i = stoi(y); i <= stoi(y1); i++) {
                year = map.getMovieYear(map.mMap, to_string(i));
                for (int j = 0; j < year.size(); j++) {
                    minYear.insertMovie(year[j]);
                    maxYear.insertMovie(year[j]);
                }
            }
            cout << "\n1. More Popular" << endl;
            cout << "2. Less Popular" << endl;
            cout << "Choose Popularity Level: ";
            cin >> p;
            cout << endl;
            if (p == "1") {
                for (unsigned int i = 0; i < 10; i++) {
                    Movie m = maxYear.extractMax();
                    cout << m.getTitle() << " (" << m.getYear() << ")";
                    cout << " - Dir. by: " << m.getDirectorName() << endl;
                    cout << "Popularity Score: " << m.getPopularity() << endl;
                    cout << endl;
                }
            }
            else if (p == "2") {
                for (int i = 0; i < 10; i++) {
                    Movie m = minYear.extractMin();
                    cout << m.getTitle() << " (" << m.getYear() << ")";
                    cout << " - Dir. by: " << m.getDirectorName() << endl;
                    cout << "Popularity Score: " << m.getPopularity() << endl;
                    cout << endl;
                }
            }
            break;
        case 6:
            cout << "\nInsert Director: ";
            string direct;
            getline(cin, direct);
            getline(cin, direct);
            cout << endl;
            dirMovies = map.getDirectorMovie(map.mMap, direct);
            if (dirMovies.empty())
                cout << "Name not recognized." << endl;
            else {
                for (int i = 0; i < dirMovies.size(); i++) {
                    Movie m = dirMovies[i];
                    cout << m.getTitle() << "(" << m.getYear() << ")" << endl;
                    cout << "Popularity Score: " << m.getPopularity() << endl;
                    cout << endl;
                }
            }
            break;
        }
        cout << endl;
    }

    return 0;
}

