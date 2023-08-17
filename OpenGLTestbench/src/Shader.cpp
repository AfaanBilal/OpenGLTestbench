/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

#include "Shader.h"

Shader::Shader(const char* vertexShaderFilepath, const char* fragmentShaderFilepath)
{
	auto [vertexShaderSource, fragmentShaderSource] = LoadShaderSource(vertexShaderFilepath, fragmentShaderFilepath);
	m_RendererID = CompileShaders(vertexShaderSource, fragmentShaderSource);
}

std::tuple<std::string, std::string> Shader::LoadShaderSource(const char* vertexShaderFilepath, const char* fragmentShaderFilepath)
{
	std::fstream vfs(vertexShaderFilepath), ffs(fragmentShaderFilepath);
	std::stringstream vertexSource, fragmentSource;

	vertexSource << vfs.rdbuf();
	fragmentSource << ffs.rdbuf();

	return { vertexSource.str(), fragmentSource.str() };
}

int Shader::CompileShaders(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
	const char* vSource = vertexShaderSource.c_str();
	const char* fSource = fragmentShaderSource.c_str();

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

void Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
	glDeleteProgram(m_RendererID);
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string& name, glm::vec4 value)
{
	glUniform4f(GetUniformLocation(name), value.r, value.g, value.b, value.a);
}

void Shader::SetUniformMat4f(const std::string& name, glm::mat4& value)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	int location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location == -1)
		std::cout << "[WARN]: Uniform " << name << " doesn't exist." << std::endl;

	m_UniformLocationCache[name] = location;
	return location;
}
