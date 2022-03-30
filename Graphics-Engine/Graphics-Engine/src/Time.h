#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time {
public:
	Time();

	void CalculateFPS();
	void Reset();
	void Start();
	void Tick();


	float DeltaTime;
	float FPS;
	float ElapsedTime;
private:
	std::chrono::duration<float> duration;
	std::chrono::time_point<std::chrono::steady_clock> start;
};

#endif // !TIME_H
