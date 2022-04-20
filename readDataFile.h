#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

vector<string> readFile (string fileName) {
     string movieID;
     string title;
     string releaseDate;
     string popularity;
     string directorID;
     string directorName;
        
     vector<string> movieData;
     
     ifStream inFile;
     inFile.open(fileName);
     if(!inFile.is_open()){
             cout<<"Warning: File failed to open"<<endl;
     }
     
     while(!inFile.eof()){
             movieData.push_back(getline(inFile, movieID,','));
             movieData.push_back(getline(inFile, title,','));
             movieData.push_back(getline((inFile, releaseDate,','));
             movieData.push_back(getline(inFile, popularity,','));
             movieData.push_back(getline(inFile, directorID,','));
             movieData.push_back(getline(inFile, directorName,','));
     }
     
//      for(int i = 0; i < 6; i++){
//              movieData.push_back()
//      }
}
