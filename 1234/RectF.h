#pragma once

#include "vec2.h"

// ONE THING IS FUCKY, IF X2 or Y2 < X1 or Y1 IT WILL STILL DRAW CORRECTLY BUT COLLISION WILL BE BROKEN
class RectF {
public:

	float x1 = 0;
	float y1 = 0;

	float x2 = 0;
	float y2 = 0;

	RectF(float X1, float Y1, float X2, float Y2) :x1(X1), y1(Y1), x2(X2), y2(Y2) {}

	RectF(const vec2f& posStart, float width, float height) :x1(posStart.x), y1(posStart.y), x2(x1 + width), y2(y1 + height) {}

	RectF(const vec2f& topleft, const vec2f& bottomright) :x1(topleft.x), y1(topleft.y), x2(bottomright.x), y2(bottomright.y) {}


	float width()const {
		return x2 - x1;
	}
	float height()const {
		return y2 - y1;
	}

	bool contains(const RectF& other) {
		return x1 < other.x2 && x2 > other.x1 && y1 < other.y2 && y2 > other.y1;
	}


	static RectF boxFromCenter(const vec2f& pos, int radius) {
		return RectF(pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
	}
};