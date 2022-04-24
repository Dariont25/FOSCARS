#pragma once
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;


class movieMap {
public:
	unordered_map<string, Movie> mMap;
	movieMap();
	~movieMap();
	void addMovie(Movie m) {
		string title = m.getTitle();
		mMap.insert({ title, m });
	}
	void addCollection(vector<Movie> collection) {
		for (int i = 0; i < collection.size(); i++) {
			string title = collection[i].getTitle();
			mMap.insert({ title, collection[i] });
		}
	}
	void getInfo(string title) {
		if (mMap.find(title) == mMap.end()) {
			cout << "Movie Not Found" << endl;
		}
		else {
			auto it = mMap.find(title);
			int pop = it->second.getPopularity();
			string dirName = it->second.getDirectorName();
			string mYear = it->second.getYear();
			cout << "Directed by: " << dirName << endl;
			cout << "Released in: " << mYear << endl;
			cout << "Popularity Score: " << pop << endl;
		}
	}
	void printAll(unordered_map<string, Movie> mMap) {
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			cout << it->first << " : " << it->second.getPopularity() << endl;
		}
	}

	vector<Movie> getMovieYear(unordered_map<string, Movie> mMap, string year) {
		vector<Movie> moviesFromYear;
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			if (it->second.getYear() == year) {
				moviesFromYear.push_back(it->second);
			}
		}
		return moviesFromYear;
	}
	vector<Movie> getDirectorMovie(unordered_map<string, Movie> mMap, string dir) {
		vector<Movie> dirMovies;
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			if (it->second.getDirectorName() == dir) {
				dirMovies.push_back(it->second);
			}
		}
		return dirMovies;
	}
	void printMovie(vector<Movie> movies) {
		cout << "Movies based on your search:" << endl;
		int count = 1;
		for (int i = 0; i < movies.size(); i++) {
			cout << count << ". " << movies[i].getTitle() << endl;
			count++;
		}
	}

};

movieMap::movieMap() {
}

movieMap::~movieMap() {
}

