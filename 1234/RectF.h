#pragma once

#include "vec2.h"

class RectF {
public:
	float left = 0;	   //is the smallest x-value within the rectangle.
	float top = 0;	   //is the smallest y-value within the rectangle.
	float right = 0;   //is the largest x-value within the rectangle.
	float bottom = 0;  //is the largest y-value within the rectangle.



	RectF(float LEFT, float TOP, float RIGHT, float BOTTOM) :left(LEFT), top(TOP), right(RIGHT), bottom(BOTTOM) {}

	RectF(const vec2f& pos, float width, float height) :left(pos.x), top(pos.y), right(pos.x + width), bottom(pos.y + height) {}

	RectF(const vec2f& pos, const vec2f& size) :left(pos.x), top(pos.y), right(pos.x + size.x), bottom(pos.y + size.y) {}


	float width()const {
		return right - left;
	}
	float height()const {
		return bottom - top;
	}


	bool contains(const RectF& other) {
		return !(other.right <= left ||
			other.left >= right ||
			other.bottom <= top ||
			other.top >= bottom);
	}
};