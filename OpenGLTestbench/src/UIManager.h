#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"

class UIManager
{
public:
	static void Initialize(GLFWwindow* window);
	static void Terminate();
	static void SetupFrame();
	static void RenderFrame();
};
