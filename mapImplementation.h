#pragma once
#include <unordered_map>
#include <set>
#include <queue>
#include "MovieManager.h"
using namespace std;


class movieMap{
public:
	unordered_map<string, Movie> mMap;
	set<Movie> popularMovies;
	set<Movie> worstMovies;
	movieMap();
	~movieMap();
	void addMovie(Movie m) {
		string title = m.getTitle();
		mMap.insert({ title, m });
	}
	void addCollection(vector<Movie> collection) {
		for (int i = 0; i < collection.size(); i++){
			string title = collection[i].getTitle();
			mMap.insert({ title, collection[i] });
		}
	}
	void getInfo(string title) {
		for (auto it = mMap.find(title); it != mMap.end(); it++) {
			int pop = it->second.getPopularity();
			string dirName = it->second.getDirectorName();
			string mYear = it->second.getYear();
			cout << pop << " " << dirName << " " << mYear << endl;
		}
	}
	void printAll(unordered_map<string,Movie> mMap) {
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			cout << it->first << " : " << it->second.getPopularity() << endl;
		}
	}
	set<Movie> getPopularMovies(unordered_map<string, Movie> mMap) {
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			if (it->second.getPopularity() > it++->second.getPopularity() && it->second.getPopularity() != 0)
			{
				popularMovies.insert(it->second);
			}
		}
		return popularMovies;
	}
	set<Movie> getWorstMovies(unordered_map<string, Movie> mMap) {
		for (auto it = mMap.begin(); it != mMap.end(); it++) {
			if (it->second.getPopularity() < it++->second.getPopularity() && it->second.getPopularity() == 0)
			{
				worstMovies.insert(it->second);
			}
		}
		return worstMovies;
	}
	vector<Movie> getMovieYear(unordered_map<string, Movie> mMap, string year) {
		vector<Movie> moviesFromYear;
		for (auto it = mMap.begin(); it != mMap.end(); it++){
			if (it->second.getYear() == year) {
				moviesFromYear.push_back(it->second);
			}
		}
		return moviesFromYear;
	}
	void printMovie(vector<Movie> movies) {
		cout << "Movies based on your search:" << endl;
		int count = 1;
		for (int i = 0; i < movies.size(); i++){
			cout << count << ". " << movies[i].title << endl;
			count++;
		}	
	}
private:

};

movieMap::movieMap(){
}

movieMap::~movieMap(){
}

