#include <unordered_map>
#include <MovieManager.h>

class movieMap {
    Movie movie;
    map <string, vector<string> movieInfo> movieMap;
public:
    void addMovie(vector<string> movieInfo, Movie &movie) {
        string title = movie.getTitle;
        movieMap.insert(title, movieInfo);
    }
    movie returnMovie(string title) {
      
    }
    void printAll(&movieMap) {
        for (auto it = movieMap.begin(); it != movieMap.end(); it++) {
            cout << it->first << " : " << it->second << endl;
        }
    }
};
