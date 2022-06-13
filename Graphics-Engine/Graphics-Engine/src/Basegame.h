#ifndef BASEGAME_H
#define BASEGAME_H

#include "TimeM.h"
#include "Camera.h"
#include "SpriteCube.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Export.h"

#include "Model.h"

class ENGINE_API Basegame {
public:
	Basegame();
	Basegame(int width, int height, const char* tittle);

	void Run();
protected:
	~Basegame() = default;
	
	Window window { };
	Renderer render { };

	TimeM time { };
	Input input { window };

	virtual void Start() {}
	virtual void Update() {}
private:

	void Core_Start();
	void Core_Update();
	void Core_Sleep();
};

#endif // !BASEGAME_H
