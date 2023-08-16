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

#include "ShaderManager.h"

ShaderManager::ShaderManager(const char* vertexShaderFilepath, const char* fragmentShaderFilepath)
{
	auto [vertexShaderSource, fragmentShaderSource] = LoadShaderSource(vertexShaderFilepath, fragmentShaderFilepath);
	m_Program = CompileShaders(vertexShaderSource, fragmentShaderSource);
}

std::tuple<std::string, std::string> ShaderManager::LoadShaderSource(const char* vertexShaderFilepath, const char* fragmentShaderFilepath)
{
	std::fstream vfs(vertexShaderFilepath), ffs(fragmentShaderFilepath);
	std::stringstream vertexSource, fragmentSource;

	vertexSource << vfs.rdbuf();
	fragmentSource << ffs.rdbuf();

	return { vertexSource.str(), fragmentSource.str() };
}

int ShaderManager::CompileShaders(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
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

void ShaderManager::Load()
{
	glUseProgram(m_Program);
}

void ShaderManager::Unload()
{
	glDeleteProgram(m_Program);
}
