/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GL/glew.h>

#include "imgui.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

#include "TestBasicTriangle.h"

namespace test
{
	TestBasicTriangle::TestBasicTriangle()
		: m_Color({ 0.4f, 0.3f, 0.2f, 1.0f }) 
	{
		m_Verticies[0] = { { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 0.0f } };
		m_Verticies[1] = { {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 0.0f } };
		m_Verticies[2] = { {  0.0f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 0.0f } };
	}

	TestBasicTriangle::~TestBasicTriangle() {}

	void TestBasicTriangle::OnUpdate(float deltaTime) {}

	void TestBasicTriangle::OnRender(Renderer& renderer)
	{
		VertexBuffer vb(m_Verticies, sizeof(m_Verticies));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);
		layout.Push<float>(2);

		VertexArray va;
		va.AddBuffer(vb, layout);

		unsigned int indices[] = {0, 1, 2};

		IndexBuffer ib(indices, 3);

		Shader shader("res/shaders/basic.vert", "res/shaders/basic.frag");

		renderer.Draw(va, ib, shader);
	}

	void TestBasicTriangle::OnUIRender()
	{
		ImGui::DragFloat2("Point 1", &m_Verticies[0].position.x, 1.0f, -1.0f, 1.0f);
		ImGui::DragFloat2("Point 2", &m_Verticies[1].position.x, 1.0f, -1.0f, 1.0f);
		ImGui::DragFloat2("Point 3", &m_Verticies[2].position.x, 1.0f, -1.0f, 1.0f);
	}
}
