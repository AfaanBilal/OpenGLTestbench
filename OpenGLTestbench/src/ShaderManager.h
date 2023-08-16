#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <string>
#include <tuple>

class ShaderManager
{
private:
	int m_Program;
public:
	ShaderManager(const char*, const char*);
	std::tuple<std::string, std::string> LoadShaderSource(const char*, const char*);
	static int CompileShaders(const std::string&, const std::string&);
	void Bind();
	void Unbind();
};
