#include "Time.h"

Time::Time() {
	duration = std::chrono::duration<float>(0.0f);
	DeltaTime = 0.0f;
	FPS = 0.0f;
	ElapsedTime = 0.0f;
}

void Time::CalculateFPS() {
	Time::FPS = 1.0f / duration.count();
}

void Time::Reset() {
	Start();
}

void Time::Start() {
	start = std::chrono::high_resolution_clock::now();
}

void Time::Tick() {
	duration = std::chrono::high_resolution_clock::now() - start;
	CalculateFPS();
	DeltaTime = duration.count();
	ElapsedTime += duration.count();
}