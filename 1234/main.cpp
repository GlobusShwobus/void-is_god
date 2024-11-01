//1. Start and finish chilis beginner course
//2. introduce a graphics class which uses windows API to open a basic as fuck window
//3. intorduce keyboard


#include "Array2D.h"
#include <iostream>
int main() {


	Array2D<int> pepega(5,5);

	int index = 0;
	for (unsigned int y = 0; y < pepega.getHeight(); y++) {
		for (unsigned int x = 0; x < pepega.getWidth(); x++) {
			pepega(x, y) = index;
			index++;
		}
	}

	return 1;
}

