#include <iostream>
#include <readDataFile.h>
#include <MovieManager.h>
#include <heapImplementation.h>
#include <mapImplementation.h>
#include <iostream>


using namespace std;

int main() {
      string fileName;
      cin>> fileName;
      vector<string> movieData;
      
      movieData = readFile(fileName);
      
      cout << "Hello, World";
      
      return 0;
}
