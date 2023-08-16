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

class Shader
{
private:
	int m_Program;
public:
	Shader(const char*, const char*);
	std::tuple<std::string, std::string> LoadShaderSource(const char*, const char*);
	static int CompileShaders(const std::string&, const std::string&);
	void Bind() const;
	void Unbind() const;
};
