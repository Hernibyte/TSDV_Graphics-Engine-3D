#ifndef EXPORT_H
#define EXPORT_H

#ifdef ENGINE_EXPORT
#define ENGINE_API __declspec(dllexport) // Especifica clase para exportacion
#else
#define ENGINE_API __declspec(dllexport) // Especifica clase para importacion
#endif // ENGINE_EXPORT

#endif