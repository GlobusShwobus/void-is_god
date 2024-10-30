#pragma once

#include "vec2.h"

// ONE THING IS FUCKY, IF X2 or Y2 < X1 or Y1 IT WILL STILL DRAW CORRECTLY BUT COLLISION WILL BE BROKEN
class RectF {
public:

	float x1 = 0;
	float y1 = 0;

	float x2 = 0;
	float y2 = 0;

	RectF() = default;

	RectF(float X1, float Y1, float X2, float Y2) :x1(X1), y1(Y1), x2(X2), y2(Y2) {}

	RectF(const Vec2& posStart, float width, float height) :x1(posStart.x), y1(posStart.y), x2(x1 + width), y2(y1 + height) {}

	RectF(const Vec2& topleft, const Vec2& bottomright) :x1(topleft.x), y1(topleft.y), x2(bottomright.x), y2(bottomright.y) {}

	RectF(const Vec2& center, float radius) :x1(center.x - radius), y1(center.y - radius), x2(center.x + radius), y2(center.y + radius) {}

	float width()const {
		return x2 - x1;
	}
	float height()const {
		return y2 - y1;
	}

	bool contains(const RectF& other)const {
		return x1 < other.x2 && x2 > other.x1 && y1 < other.y2 && y2 > other.y1;
	}

};