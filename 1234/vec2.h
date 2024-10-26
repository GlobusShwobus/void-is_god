#pragma once

#include <cmath>

class vec2
{
public:
	float x = 0;
	float y = 0;

	bool operator==(const vec2& rhs) {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2& rhs) {
		return !(*this == rhs);
	}

	vec2 operator+(const vec2& rhs) {
		return vec2{ x + rhs.x, y + rhs.y };
	}
	vec2 operator-(const vec2& rhs) {
		return vec2{ x - rhs.x, y - rhs.y };
	}

	vec2& operator +=(const vec2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	vec2 & operator-=(const vec2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}


	void scale(float _x) {
		x *= _x;
		y *= _x;
	}

	float getLength() {
		return std::sqrt((x * x) + (y + y));
	}
};