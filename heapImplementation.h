#include<string>
#include<cmath>
#include "MovieManager.h"
using namespace std;

struct minHeap {
private:
	vector<Movie> minHeap;
public:
	void insertMovie(Movie m);
	Movie extractMin();
	void swap(int x, int y);
}
void minHeap::swap(int x, int y) {
	Movie temp = minHeap[x];
	minHeap[x] = minHeap[y];
	minHeap[y] = temp;
}
void minHeap::insertMovie(Movie m) {
	int i = minHeap.size();
	minHeap.push_back(m);
	if (i > 0) {
		int mParent = (i - 1) / 2;
		while (minHeap[mParent].getPopularity() > minHeap[i].getPopularity()
			&& i != 0) {
			swap(i, mParent);
			if (mParent == 0) {
				break;
			}
			i = mParent;
			mParent = (i - 1) / 2;
		}
	}
}
Movie minHeap::extractMin() {
	Movie top = minHeap[0];
	int i = minHeap.size() - 1;
	minHeap[0] = minHeap[i];
	minHeap.pop_back();
	int m = 0;
	int c1 = (2 * m) + 1;
	int c2 = (2 * m) + 2;
	while (minHeap.size() > c1) {
		if (minHeap[m].getPopularity() > minHeap[c1].getPopularity()) {
			swap(m, c1);
			m = c1;
		}
		else if (minHeap.size() > c2) {
			if (minHeap[m].getPopularity() > minHeap[c2].getPopularity()) {
				swap(m, c2);
				m = c2;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
		c1 = (2 * m) + 1;
		c2 = (2 * m) + 1;
	}

	return top;
}


struct maxHeap {

}
