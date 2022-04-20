#pragma once
#include <unordered_map>
#include "MovieManager.h"
using namespace std;


class movieMap{
public:
	unordered_map<string, Movie> mMap;
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
private:

};

movieMap::movieMap(){
}

movieMap::~movieMap(){
}

