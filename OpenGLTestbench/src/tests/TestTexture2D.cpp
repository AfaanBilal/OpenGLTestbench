/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "TestTexture2D.h"

namespace test
{
	TestTexture2D::TestTexture2D()
		: m_Proj(glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		m_Translation(0.0f, 0.0f, 0.0f)
	{
		Vertex verticies[] = {
			{ { -0.7f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 0.0f } },
			{ {  0.7f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 1.0f, 0.0f } },
			{ {  0.7f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 1.0f, 1.0f } },
			{ { -0.7f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f }, { 0.0f, 1.0f } },
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,
		};

		m_VAO = std::make_unique<VertexArray>();
		m_VBO = std::make_unique<VertexBuffer>(verticies, sizeof(verticies));
		m_IB = std::make_unique<IndexBuffer>(indices, 6);
		m_Shader = std::make_unique<Shader>("res/shaders/basic.vert", "res/shaders/basic.frag");
				
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);

		m_Texture = std::make_unique<Texture>("res/textures/bubble.png");
		m_Texture->Bind(0);

		m_Shader->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);
	}

	TestTexture2D::~TestTexture2D() {}

	void TestTexture2D::OnUpdate(float deltaTime) {}

	void TestTexture2D::OnRender()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		m_Texture->Bind(0);

		glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Translation);
		glm::mat4 mvp = m_Proj * m_View * model;

		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_MVP", mvp);

		Renderer::Draw(*m_VAO, *m_IB, *m_Shader);
	}

	void TestTexture2D::OnUIRender()
	{
		ImGui::SliderFloat3("Translation", &m_Translation.x, -1.0f, 1.0f);
	}
}
