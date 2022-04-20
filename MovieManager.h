#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Movie{
    string title;
    int movieId;
    int year;
    int popularity;
    string directorName;
    int directorId;
public:
    Movie(string t, int id, int yr, int pop, string dir, int dirID) {
        title = t;
        movieId = id;
        year = yr;
        popularity = pop;
        directorName = dir;
        directorId = dirID;
    };
    string getTitle() {
        return title;
    }
    int getMovieId() {
        return movieId;
    }
    int getYear() {
        return year;
    }
    int getPopularity() {
        return popularity;
    }
    string getDirectorName() {
        return directorName;
    }
    int getDirectorID() {
        return directorId;
    }
};
