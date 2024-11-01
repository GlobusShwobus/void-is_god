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

	//Array2D<float> kekw = pepega;

	Array2D<int> huh = pepega;

	std::cout << huh(0, 1) << " " << huh(0, 2) << std::endl;

	std::cout << "\n\n\n" << pepega(0, 1) << " " << pepega(0, 2) << std::endl;

	Array2D<int> pidor = std::move(pepega);

	std::cout << pidor(0, 1) << " " << pidor(0, 2) << std::endl;

	//std::cout << "\n\n\n" << pepega(0, 1) << " " << pepega(0, 2) << std::endl;

	return 1;
}

