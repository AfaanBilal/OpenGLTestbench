#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Clear() const;
	void Draw() const;
};
