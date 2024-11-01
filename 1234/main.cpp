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




	std::cout << pepega(0, 0)<<'\n'<< pepega(0, 1) << '\n' << pepega(0, 2) << '\n' << pepega(0, 3) << '\n' << pepega(0, 4) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << pepega(0, 0) <<'\n'<<pepega(1, 0) << '\n' << pepega(2, 0) << '\n' << pepega(3, 0) << '\n' << pepega(4, 0) << std::endl;
	pepega.resize2(2, 5);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << pepega(0, 0) << '\n' << pepega(0, 1) << '\n' << pepega(0, 2) << '\n' << pepega(0, 3) << '\n' << pepega(0, 4) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	//assert failed
	//std::cout << pepega(0, 0) << '\n' << pepega(1, 0) << '\n' << pepega(2, 0) << '\n' << pepega(3, 0) << '\n' << pepega(4, 0) << std::endl;
	std::cout << pepega(0, 0) << '\n' << pepega(1, 0) << std::endl;
	return 1;
}

