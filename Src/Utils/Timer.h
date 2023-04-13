#pragma once
#include <chrono>

/// Time measuring helper class
/** Utility class that allows to measure time in a form of ticks. */
class Timer
{
public:
	/// Timer constructor
	/**
	* Initalizes time measuring clock using steady_clock
	*/
	Timer() noexcept;
	/// Marking point in time function
	/**
	* Marks how much time it took since previously calling this function.
	* \return Time past since last Mark() in seconds
	*/
	float Mark() noexcept;
private:
	std::chrono::steady_clock::time_point last;
};