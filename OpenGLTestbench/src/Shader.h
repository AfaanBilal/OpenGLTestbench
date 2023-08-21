#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"

class Shader
{
public:
	Shader(const char*, const char*);
	std::tuple<std::string, std::string> LoadShaderSource(const char*, const char*);
	static int CompileShaders(const std::string&, const std::string&);
	
	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value) const;
	void SetUniform3f(const std::string& name, glm::vec3 value) const;
	void SetUniform4f(const std::string& name, glm::vec4 value) const;
	void SetUniformMat4f(const std::string& name, glm::mat4& value) const;
private:
	int m_RendererID;
	mutable std::unordered_map<std::string, int> m_UniformLocationCache;

	int GetUniformLocation(const std::string& name) const;
};
