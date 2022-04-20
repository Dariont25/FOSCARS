#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Movie{
    string title;
    int movieId;
    int year;
    int popularity;
    int directorName;
    int directorId;
public:
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
    int getDirectorName() {
        return directorName;
    }
    int getDirectorID() {
        return directorId;
    }
};
