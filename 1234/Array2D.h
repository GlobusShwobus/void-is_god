#pragma once

#include "vec2.h"
#include <assert.h>
#include <utility>

template<typename Object> class Array2D {
	
	unsigned int width = 0;
	unsigned int height = 0;
	Object* arry = nullptr;

public:

	Array2D(unsigned int WIDTH, unsigned int HEIGHT) :width(WIDTH), height(HEIGHT) {

		assert(width > 0);
		assert(height > 0);

		arry = new Object[width * height];
	}
	Array2D(const Array2D& rhs) :width(rhs.width), height(rhs.height) {

		if (arry) { delete[] arry; }
		arry = new Object[width * height];

		for (int i = 0; i < width * height; i++) {
			arry[i] = rhs.arry[i];
		}
	}
	Array2D(Array2D&& rhs)noexcept :width(rhs.width), height(rhs.height) {
		
		if (arry) { delete[] arry; }
		arry = new Object[width * height];

		for (int i = 0; i < width * height; i++) {
			arry[i] = std::move(rhs.arry[i]);
		}

		delete[]rhs.arry;
		rhs.arry = nullptr;
		rhs.width = 0;
		rhs.height = 0;
	}
	Array2D& operator=(const Array2D& rhs) {
		if (this != &rhs) {
			width = rhs.width;
			height = rhs.height;

			if (arry) { delete[]arry; }
			arry = new Object[width * height];

			for (int i = 0; i < width * height; i++) {
				arry[i] = rhs.arry[i];
			}
		}
		return *this;
	}
	Array2D& operator=(Array2D&& rhs)noexcept {
		if (this != &rhs) {
			width = rhs.width;
			height = rhs.height;

			if (arry) { delete[]arry; }
			arry = new Object[width * height];

			for (int i = 0; i < width * height; i++) {
				arry[i] = std::move(rhs.arry[i]);
			}
			delete[] rhs.arry;
			rhs.width = 0;
			rhs.height = 0;
		}
		return *this;
	}

	~Array2D() {
		delete[] arry;
	}


	const Object& operator()(unsigned int x, unsigned int y)const {
		assert(x < width && y < height);
		return arry[y * width + x];
	}

	const Object& operator()(const vec2i& pair)const {	//idk boss, x and y can be -
		assert(pair.x < width && pair.y < height);
		return arry[pair.y * width + pair.x];
	}

	Object& operator()(unsigned int x, unsigned int y) {
		assert(x < width && y < height);
		return arry[y * width + x];
	}

	Object& operator()(const vec2i& pair) {	//idk boss, x and y can be -
		assert(pair.x < width && pair.y < height);
		return arry[pair.y * width + pair.x];
	}

	unsigned int getWidth()const { return width; }
	unsigned int getHeight()const { return height; }
};





/*
//lose offset if newsize is smaller, and does not remap the whole shit
	void resize(unsigned int newWidth, unsigned int newHeight) {
		assert(newWidth > 0);
		assert(newHeight > 0);

		Object* tempcopy = new Object[newWidth * newHeight];

		for (int y = 0; y < newHeight; y++) {
			for (int x = 0; x < newWidth; x++) {
				if (x < width && y < height) {
					tempcopy[y * newWidth + x] = std::move(arry[y * width + x]);
				}
			}
		}

		delete[]arry;

		arry = tempcopy;
		width = newWidth;
		height = newHeight;
	}
	//lose the tail in 1D formm if new size is smaller, and remaps the whole shit
	void resize2(unsigned int newWidth, unsigned int newHeight) {
		assert(newWidth > 0);
		assert(newHeight > 0);

		Object* tempcopy = new Object[newWidth * newHeight];

		unsigned int OldSize = width * height;

		for (int index = 0; index < newWidth * newHeight && index < OldSize; index++) {
			tempcopy[index] = std::move(arry[index]);
		}

		delete[]arry;

		arry = tempcopy;
		width = newWidth;
		height = newHeight;
	}

	static void copy(Array2D<Object>& lhs, const Array2D<Object>& rhs) {
	
		static_assert(std::is_same<lhs.arry, rhs.arry>::value, "Lhs type must == rhs type");
	
		if (lhs.arry) { delete[] lhs.arry; }
		lhs.width = rhs.width;
		lhs.height = rhs.height;
	
	
		lhs.arry = new Object[lhs.width * lhs.height];
	
		for (int i = 0; i < lhs.width * lhs.height; i++) {
			lhs.arry[i] = rhs.arry[i];
		}
	}

*/