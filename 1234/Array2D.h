#pragma once

#include "vec2.h"
#include <assert.h>

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
	
	void resize(unsigned int newWidth, unsigned int newHeight) {
		assert(newWidth > 0);
		assert(newHeight > 0);

		Object* tempcopy = new Object[newWidth * newHeight];

		for (int y = 0; y < newHeight; y++) {
			for (int x = 0; x < newWidth; x++) {
				if (x < width && y < height) {
					tempcopy[y * newWidth + x] = arry[y * width + x];
				}
			}
		}

		delete[]arry;

		arry = tempcopy;
		width = newWidth;
		height = newHeight;
	}
	void resizeDirty(unsigned int newWidth, unsigned int newHeight) {
		assert(newWidth > 0);
		assert(newHeight > 0);

		Object* tempcopy = new Object[newWidth * newHeight];

		unsigned int OldSize = width * height;

		for (int index = 0; index < newWidth * newHeight && index < OldSize; index++) {
			tempcopy[index] = arry[index];
		}

		delete[]arry;

		arry = tempcopy;
		width = newWidth;
		height = newHeight;
	}


	~Array2D() {
		delete[] arry;
	}
private:
	Array2D(const Array2D<Object>&) = delete;
	Array2D& operator=(const Array2D<Object>&) = delete;
};