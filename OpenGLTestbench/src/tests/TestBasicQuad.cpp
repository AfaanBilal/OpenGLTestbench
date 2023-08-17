/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <GL/glew.h>

#include "imgui.h"

#include "TestBasicQuad.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace test
{
	TestBasicQuad::TestBasicQuad()
		: m_Color({ 0.4f, 0.3f, 0.2f, 1.0f })
	{
		m_Verticies[0] = { { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 0.0f } };
		m_Verticies[1] = { {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 1.0f, 0.0f } };
		m_Verticies[2] = { {  0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 1.0f, 1.0f } };
		m_Verticies[3] = { { -0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 1.0f } };
	}

	TestBasicQuad::~TestBasicQuad() {}

	void TestBasicQuad::OnUpdate(float deltaTime) {}

	void TestBasicQuad::OnRender(Renderer& renderer)
	{
		VertexBuffer vb(m_Verticies, sizeof(m_Verticies));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);
		layout.Push<float>(2);

		VertexArray va;
		va.AddBuffer(vb, layout);

		unsigned int indices[] = { 
			0, 1, 2, 
			2, 3, 0,
		};

		IndexBuffer ib(indices, 6);

		Shader shader("res/shaders/basic.vert", "res/shaders/basic.frag");

		Texture texture("res/textures/bubble.png");
		texture.Bind(0);
		shader.SetUniform1i("u_Texture", 0);

		renderer.Draw(va, ib, shader);
	}

	void TestBasicQuad::OnUIRender()
	{
		ImGui::DragFloat2("Point 1", &m_Verticies[0].position.x, 1.0f, -1.0f, 1.0f);
		ImGui::DragFloat2("Point 2", &m_Verticies[1].position.x, 1.0f, -1.0f, 1.0f);
		ImGui::DragFloat2("Point 3", &m_Verticies[2].position.x, 1.0f, -1.0f, 1.0f);
		ImGui::DragFloat2("Point 4", &m_Verticies[3].position.x, 1.0f, -1.0f, 1.0f);
	}
}
