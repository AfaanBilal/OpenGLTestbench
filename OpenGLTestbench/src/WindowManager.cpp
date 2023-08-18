/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "WindowManager.h"

GLFWwindow* WindowManager::Initialize()
{
	GLFWwindow* window;

	if (!glfwInit())
		return nullptr;

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "GLEW Error: " << glewGetErrorString(err) << std::endl;
	}
	std::cout << "GLEW: " << glewGetString(GLEW_VERSION) << std::endl;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return window;
}

void WindowManager::Terminate()
{
	glfwTerminate();
}
