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
#include <unordered_map>

#include "glm/vec4.hpp"

class Shader
{
public:
	Shader(const char*, const char*);
	std::tuple<std::string, std::string> LoadShaderSource(const char*, const char*);
	static int CompileShaders(const std::string&, const std::string&);
	
	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform4f(const std::string& name, glm::vec4 value);
private:
	int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	int GetUniformLocation(const std::string& name);
};
