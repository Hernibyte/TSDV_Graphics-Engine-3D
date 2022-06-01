#ifndef GAME_H
#define GAME_H

#include "Basegame.h"

class Game : public Basegame {
public:
	Game(int width, int height, const char* tittle);

	void Start();
	void Update();

private:
	Camera camera{ render };
	Light light1{ render };
	SpriteCube spriteCube1{ render };
	ShapeCube shapeCube1{ render };
	ShapeCube shapeCube2{ render };
};

#endif // !GAME_H
