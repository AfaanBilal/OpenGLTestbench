#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GL/glew.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Clear() const;
	void Draw(const unsigned int* indices) const;
};