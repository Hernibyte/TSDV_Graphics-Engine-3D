#include "TimeM.h"

TimeM::TimeM() {
	duration = std::chrono::duration<float>(0.0f);
	DeltaTime = 0.0f;
	FPS = 0.0f;
	ElapsedTime = 0.0f;
}

void TimeM::CalculateFPS() {
	TimeM::FPS = 1.0f / duration.count();
}

void TimeM::Reset() {
	Start();
}

void TimeM::Start() {
	start = std::chrono::high_resolution_clock::now();
}

void TimeM::Tick() {
	duration = std::chrono::high_resolution_clock::now() - start;
	CalculateFPS();
	DeltaTime = duration.count();
	ElapsedTime += duration.count();
}