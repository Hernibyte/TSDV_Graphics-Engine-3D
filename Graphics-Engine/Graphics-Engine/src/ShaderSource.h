#ifndef SHADERSOURCE_H
#define SHADERSOURCE_H

#include <iostream>
#include <string>
#include "Export.h"

struct ENGINE_API ShaderSource {
	std::string Vertex;
	std::string Fragment;
};

#endif // !SHADERSOURCE_H
