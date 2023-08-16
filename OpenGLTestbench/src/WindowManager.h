#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GLFW/glfw3.h>

#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE  "OpenGL Testbench"

class WindowManager
{
public:
	static GLFWwindow* Initialize();
	static void Terminate();
};