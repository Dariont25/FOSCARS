#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Movie {
    string title;
    string movieId;
    string year;
    string directorName;
    string directorId;
public:
    long popularity;
    Movie(string t, string id, string yr, long pop, string dir, string dirID) {
        title = t;
        movieId = id;
        year = yr;
        popularity = pop;
        directorName = dir;
        directorId = dirID;
    }
    string getTitle() {
        return title;
    }
    string getMovieId() {
        return movieId;
    }
    string getYear() {
        return year;
    }
    long getPopularity() {
        return popularity;
    }
    string getDirectorName() {
        return directorName;
    }
    string getDirectorID() {
        return directorId;
    }
};

