#pragma once

#include <cmath>

class vec2i
{
public:
	float x = 0;
	float y = 0;

	bool operator==(const vec2i& rhs) {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2i& rhs) {
		return !(*this == rhs);
	}

	vec2i operator+(const vec2i& rhs)const {
		return vec2i{ x + rhs.x, y + rhs.y };
	}
	vec2i& operator +=(const vec2i& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	vec2i operator-(const vec2i& rhs)const {
		return vec2i{ x - rhs.x, y - rhs.y };
	}
	vec2i& operator-=(const vec2i& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	vec2i operator*(int rhs)const {
		return vec2i{ x * rhs, y * rhs };
	}
	vec2i& operator*=(int rhs) {
		return *this = *this * rhs;
	}

	vec2i operator/(int rhs)const {
		return vec2i{ x / rhs,y / rhs };
	}
	vec2i& operator/=(int rhs) {
		return *this = *this / rhs;
	}


	void scale(float _x) {
		x *= _x;
		y *= _x;
	}

	float getLength() {
		return std::sqrt((x * x) + (y + y));
	}
};