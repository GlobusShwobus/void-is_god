#pragma once

#include <chrono>

class Timer {
	std::chrono::steady_clock::time_point last;

public:

	Timer() {
		last = std::chrono::steady_clock::now();
	}

	float mark() {
		const auto old = last;
		last = std::chrono::steady_clock::now();
		const std::chrono::duration<float> difference = last - old;
		return difference.count();
	}
};
