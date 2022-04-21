#include <iostream>
#include "readDataFileTest.h"
/*#include "heapImplementationTest.h"
#include "mapImplementation.h" */



using namespace std;
void printMenu() {
    cout << "1. Print 10 Popular Movies\n";
    cout << "2. Print 10 Non-Popular Movies\n";
    cout << "3. Search by title\n";
    cout << "4. Search by year \n";
    cout << "5. Search by director\n";
}

int main() {


    vector<Movie> movies;

    movies = readFile("movie_data.csv");
    bool exit = false;
    int n = 0;
    string t, y;
    movieMap map = movieMap();
    map.addCollection(movies);

    minHeap min = minHeap();
    maxHeap max = maxHeap();
    for (int i = 0; i < movies.size(); i++) {
        min.insertMovie(movies[i]);
        max.insertMovie(movies[i]);
    }
    while (exit != true) {
        printMenu();
        cin >> n;
        switch (n)
        {
        case 0:
            exit = true;
            break;
        case 1:
            for (int i = 0; i < 10; i++) {
                Movie m = max.extractMax();
                cout << m.getTitle() << "(" << m.getYear() << ")" << endl;
                cout << "Popularity Score: " << m.getPopularity();
            }

            break;
        case 2:
            for (int i = 0; i < 10; i++) {
                Movie m = min.extractMin();
                cout << m.getTitle() << "(" << m.getYear() << ")" << endl;
                cout << "Popularity Score: " << m.getPopularity();
            }
            break;
        case 3:
            cout << "Insert Title" << endl;
            cin >> t;
            map.getInfo(t);
            break;
        case 4:
            cout << "Insert Year" << endl;
            cin >> y;
            map.printMovie(map.getMovieYear(map.mMap, y));
            break;
        case 5:
            cout << "Insert Director" << endl;
            string direct;
            cin >> direct;
            //map.getDirectorsMovie(map.mMap, direct);
            break;
        }

    }

    return 0;
}

