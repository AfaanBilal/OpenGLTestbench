/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "TestBasicTriangle.h"

namespace test
{
	TestBasicTriangle::TestBasicTriangle()
	{
		m_Verticies[0] = { { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[1] = { {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[2] = { {  0.0f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };

		unsigned int indices[] = {
			0, 1, 2,
		};

		m_VAO = std::make_unique<VertexArray>();
		m_VBO = std::make_unique<VertexBuffer>(m_Verticies, sizeof(m_Verticies));
		m_IB = std::make_unique<IndexBuffer>(indices, 3);
		m_Shader = std::make_unique<Shader>("res/shaders/basic_triangle.vert", "res/shaders/basic_triangle.frag");

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);
		m_VAO->AddBuffer(*m_VBO, layout);
	}

	TestBasicTriangle::~TestBasicTriangle() {}

	void TestBasicTriangle::OnUpdate(float deltaTime) {}

	void TestBasicTriangle::OnRender(Renderer& renderer)
	{
		m_VBO->SetData(m_Verticies, sizeof(m_Verticies));
		renderer.Draw(*m_VAO, *m_IB, *m_Shader);
	}

	void TestBasicTriangle::OnUIRender()
	{
		ImGui::ColorEdit4("Color 1", &m_Verticies[0].color.r);
		ImGui::ColorEdit4("Color 2", &m_Verticies[1].color.r);
		ImGui::ColorEdit4("Color 3", &m_Verticies[2].color.r);

		ImGui::SliderFloat2("Point 1", &m_Verticies[0].position.x, -1.0f, 1.0f);
		ImGui::SliderFloat2("Point 2", &m_Verticies[1].position.x, -1.0f, 1.0f);
		ImGui::SliderFloat2("Point 3", &m_Verticies[2].position.x, -1.0f, 1.0f);
	}
}
