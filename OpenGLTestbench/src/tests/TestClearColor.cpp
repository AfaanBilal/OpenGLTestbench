/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GL/glew.h>

#include "imgui.h"

#include "TestClearColor.h"

namespace test
{
	TestClearColor::TestClearColor()
		: m_ClearColor({ 0.2f, 0.3f, 0.8f, 1.0f })
	{

	}

	TestClearColor::~TestClearColor() {}

	void TestClearColor::OnUpdate(float deltaTime) {}

	void TestClearColor::OnRender() 
	{
		glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void TestClearColor::OnUIRender() 
	{
		ImGui::ColorEdit4("Clear color", &m_ClearColor.r);
	}
}
