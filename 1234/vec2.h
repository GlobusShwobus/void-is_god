#pragma once

#include <cmath>

class vec2i
{
public:

	int x = 0;
	int y = 0;

	vec2i(int X, int Y) :x(X), y(Y) {}
	vec2i() = default;

	bool operator==(const vec2i& rhs)const {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2i& rhs)const {
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

	void setLenght(int length) {
		float currentLen = getLengthSqrt();
		if (currentLen != 0.0f) {
			*this = *this / currentLen * length;
		}
	}

	float getLengthSqrt()const {
		return std::sqrt((x * x) + (y + y));
	}
	int getLengthSq()const {
		return (x * x) + (y + y);
	}

	vec2i& normalize() {
		return *this = getNormalized();
	}
	vec2i getNormalized()const {
		const float len = getLengthSqrt();
		if (len != 0.0f) {
			return *this * (1.0f / len);
		}
		return *this;;
	}

};


class vec2f
{
public:

	float x = 0;
	float y = 0;

	vec2f(float X, float Y) :x(X), y(Y) {}
	vec2f() = default;

	bool operator==(const vec2f& rhs) {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	bool operator!=(const vec2f& rhs) {
		return !(*this == rhs);
	}

	vec2f operator+(const vec2f& rhs)const {
		return vec2f(x + rhs.x, y + rhs.y);
	}
	vec2f& operator+=(const vec2f& rhs) {
		return *this = *this + rhs;
	}

	vec2f operator-(const vec2f& rhs)const {
		return vec2f(x - rhs.x, y - rhs.y);
	}
	vec2f& operator-=(const vec2f& rhs) {
		return *this = *this - rhs;
	}

	vec2f operator*(float rhs)const {
		return vec2f(x * rhs, y * rhs);
	}
	vec2f& operator*=(float rhs) {
		return *this = *this * rhs;
	}

	vec2f operator/(float rhs)const {
		return vec2f(x / rhs, y / rhs);
	}
	vec2f& operator/=(float rhs) {
		return *this = *this / rhs;
	}


	void setLenght(float length) {
		float currentLen = getLengthSqrt();

		*this = *this / currentLen * length;
	}

	float getLengthSqrt()const {
		return std::sqrt((x * x) + (y + y));
	}
	float getLengthSq()const {
		return (x * x) + (y + y);
	}
	vec2f& normalize() {
		return *this = getNormalized();
	}
	vec2f getNormalized()const {
		const float len = getLengthSqrt();
		if (len != 0.0f) {
			return *this * (1.0f / len);
		}
		return *this;
	}
};
