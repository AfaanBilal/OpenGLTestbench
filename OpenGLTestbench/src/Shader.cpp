/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <string>
#include <tuple>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

#include "Shader.h"

Shader::Shader(const char* vertexShaderFilepath, const char* fragmentShaderFilepath)
{
	auto [vertexShaderSource, fragmentShaderSource] = LoadShaderSource(vertexShaderFilepath, fragmentShaderFilepath);
	m_Program = CompileShaders(vertexShaderSource, fragmentShaderSource);
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
	glUseProgram(m_Program);
}

void Shader::Unbind() const
{
	glDeleteProgram(m_Program);
}
