#pragma once

#include <chrono>

class Timer {
	std::chrono::steady_clock::time_point time;

public:
	Timer() {
		time = std::chrono::steady_clock::now();
	}
	float getTime() {
		return std::chrono::duration<float>(std::chrono::steady_clock::now() - time).count();
	}
	void reset() {
		time = std::chrono::steady_clock::now();
	}
};
