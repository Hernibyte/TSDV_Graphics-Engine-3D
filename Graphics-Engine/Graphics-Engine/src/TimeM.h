#ifndef TIMEM_H
#define TIMEM_H

#include <chrono>
#include "Export.h"

class ENGINE_API TimeM {
public:
	TimeM();

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
