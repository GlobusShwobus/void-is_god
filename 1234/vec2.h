#pragma once

#include <cmath>

class vec2i
{
	int x = 0;
	int y = 0;
public:
	vec2i(int X, int Y) :x(X), y(Y) {}
	vec2i() = default;

	bool operator==(const vec2i& rhs) {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2i& rhs) {
		return !(*this == rhs);
	}

	vec2i operator+(const vec2i& rhs)const {
		return vec2i( x + rhs.x, y + rhs.y );
	}
	vec2i& operator+=(const vec2i& rhs) {
		return *this = *this + rhs;
	}

	vec2i operator-(const vec2i& rhs)const {
		return vec2i( x - rhs.x, y - rhs.y );
	}
	vec2i& operator-=(const vec2i& rhs) {
		return *this = *this - rhs;
	}

	vec2i operator*(int rhs)const {
		return vec2i( x * rhs, y * rhs );
	}
	vec2i& operator*=(int rhs) {
		return *this = *this * rhs;
	}

	vec2i operator/(int rhs)const {
		return vec2i( x / rhs,y / rhs );
	}
	vec2i& operator/=(int rhs) {
		return *this = *this / rhs;
	}


	void scale(int _x) {
		x *= _x;
		y *= _x;
	}

	float getLengthSqrt() {
		return std::sqrt((x * x) + (y + y));
	}
	float getLengthSq() {
		return (x * x) + (y + y);
	}
};