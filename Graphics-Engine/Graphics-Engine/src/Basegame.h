#ifndef BASEGAME_H
#define BASEGAME_H

#include "ShapeCube.h"
#include "Sprite.h"
#include "Time.h"
#include "Camera.h"

class Basegame {
public:
	Basegame();
	Basegame(int width, int height, const char* tittle);

	void Run();
protected:
	~Basegame() = default;
	
	Window window { };
	Renderer render { };

	Time time { };
	Input input { window };

	virtual void Start() {}
	virtual void Update() {}
private:

	void Core_Start();
	void Core_Update();
	void Core_Sleep();
};

#endif // !BASEGAME_H
