#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"

#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT 1200
#define WINDOW_TITLE  "OpenGL Testbench by Afaan Bilal"

class WindowManager
{
public:
	static GLFWwindow* Initialize();
	static void Terminate();
};
