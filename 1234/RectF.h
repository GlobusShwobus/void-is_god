#pragma once

#include "vec2.h"

class RectF {
public:

	float top = 0;
	float bottom = 0;
	float left = 0;
	float right = 0;


	RectF() = default;
	RectF(float topin, float botin, float leftin, float rightin) :top(topin), bottom(botin), left(leftin), right(rightin) {}
	RectF(const vec2f& topleft, const vec2f& bottomRight) :RectF(topleft.y, bottomRight.y, topleft.x, bottomRight.x) {}
	RectF(const vec2f& topleft, float width, float height) :RectF(topleft, topleft + vec2f(width, height)) {}


	bool isOverLappingWith(const RectF& other)const {
		return right > other.left && left<other.right
			&& bottom>other.top && top < other.bottom;
	}

};