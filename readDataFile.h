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
             getline(inFile, title,',');
             getline(inFile, releaseDate,',');
             getline(inFile, popularity,',');
             getline(inFile, directorID,',');
             getline(inFile, directorName,',');
     }
     
//      for(int i = 0; i < 6; i++){
//              movieData.push_back()
//      }
}
