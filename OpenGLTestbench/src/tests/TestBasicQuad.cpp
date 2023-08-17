/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "TestBasicQuad.h"

namespace test
{
	TestBasicQuad::TestBasicQuad()
	{
		m_Verticies[0] = { { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[1] = { {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[2] = { {  0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };
		m_Verticies[3] = { { -0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } };

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,
		};

		m_VAO = std::make_unique<VertexArray>();
		m_VBO = std::make_unique<VertexBuffer>(m_Verticies, sizeof(m_Verticies));
		m_IB = std::make_unique<IndexBuffer>(indices, 6);
		m_Shader = std::make_unique<Shader>("res/shaders/basic_triangle.vert", "res/shaders/basic_triangle.frag");

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);
		m_VAO->AddBuffer(*m_VBO, layout);
	}

	TestBasicQuad::~TestBasicQuad() {}

	void TestBasicQuad::OnUpdate(float deltaTime) {}

	void TestBasicQuad::OnRender(Renderer& renderer)
	{
		m_VBO->SetData(m_Verticies, sizeof(m_Verticies));
		renderer.Draw(*m_VAO, *m_IB, *m_Shader);
	}

	void TestBasicQuad::OnUIRender()
	{
		ImGui::ColorEdit4("Color 1", &m_Verticies[0].color.r);
		ImGui::ColorEdit4("Color 2", &m_Verticies[1].color.r);
		ImGui::ColorEdit4("Color 3", &m_Verticies[2].color.r);
		ImGui::ColorEdit4("Color 4", &m_Verticies[3].color.r);

		ImGui::SliderFloat2("Point 1", &m_Verticies[0].position.x, -1.0f, 1.0f);
		ImGui::SliderFloat2("Point 2", &m_Verticies[1].position.x, -1.0f, 1.0f);
		ImGui::SliderFloat2("Point 3", &m_Verticies[2].position.x, -1.0f, 1.0f);
		ImGui::SliderFloat2("Point 4", &m_Verticies[3].position.x, -1.0f, 1.0f);
	}
}
