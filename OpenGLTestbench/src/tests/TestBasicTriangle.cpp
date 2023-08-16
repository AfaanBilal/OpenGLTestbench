/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GL/glew.h>

#include "imgui.h"

#include "TestBasicTriangle.h"

namespace test
{
	TestBasicTriangle::TestBasicTriangle()
		: m_Color({ 0.4f, 0.3f, 0.2f, 1.0f }) 
	{
		m_Verticies[0] = { { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[1] = { {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[2] = { {  0.0f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
	}

	TestBasicTriangle::~TestBasicTriangle() {}

	void TestBasicTriangle::OnUpdate(float deltaTime) {}

	void TestBasicTriangle::OnRender()
	{
		
	}

	void TestBasicTriangle::OnUIRender()
	{
		ImGui::ColorEdit4("Color", &m_Color.r);
	}
}
