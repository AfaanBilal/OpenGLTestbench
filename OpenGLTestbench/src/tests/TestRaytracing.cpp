/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "TestRaytracing.h"

static u32 g_seed = 20394792385;
inline u32 fastrand() {
	g_seed = (214013 * g_seed + 2531011);
	return (g_seed >> 16) & 0x7FFF;
}

namespace test
{
	MemoryTexture::MemoryTexture()
		: m_RendererID(0), m_LocalBuffer(nullptr), m_Width(1200), m_Height(800)
	{
		m_LocalBuffer = new u32[m_Width * m_Height];

		memset(m_LocalBuffer, 0xff0000ff, m_Width * m_Height);

		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const char*)m_LocalBuffer);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	MemoryTexture::~MemoryTexture()
	{
		delete[] m_LocalBuffer;
		glDeleteTextures(1, &m_RendererID);
	}

	void MemoryTexture::Bind(unsigned int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void MemoryTexture::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void MemoryTexture::Reset() const
	{
		Bind();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const char*)m_LocalBuffer);
	}

	//
	// ---
	//

	TestRaytracing::TestRaytracing()
	{
		float viewportVerticies[] = {
			-1.0f, -1.0f, 0.0f, 0.0f,
			 1.0f, -1.0f, 1.0f, 0.0f,
			 1.0f,  1.0f, 1.0f, 1.0f,
			-1.0f,  1.0f, 0.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,
		};

		m_VAO = std::make_unique<VertexArray>();
		m_VBO = std::make_unique<VertexBuffer>(viewportVerticies, sizeof(viewportVerticies));
		m_IB = std::make_unique<IndexBuffer>(indices, 6);
		m_Shader = std::make_unique<Shader>("res/shaders/raytracing.vert", "res/shaders/raytracing.frag");

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);

		m_Texture = std::make_unique<MemoryTexture>();
		m_Texture->Bind(0);

		m_Shader->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);
	}

	TestRaytracing::~TestRaytracing() {}

	void TestRaytracing::OnUpdate(float deltaTime) {}

	void TestRaytracing::OnRender()
	{
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (int y = 0; y < m_Texture->GetHeight(); y++) {
			for (int x = 0; x < m_Texture->GetWidth(); x++) {
				glm::vec2 coord = { (float)x / (float)m_Texture->GetWidth(), (float)y / (float)m_Texture->GetHeight() };
				m_Texture->m_LocalBuffer[y * m_Texture->GetWidth() + x] = PixelColor(coord);
			}
		}
		
		m_Texture->Reset();
		m_Shader->Bind();

		Renderer::Draw(*m_VAO, *m_IB, *m_Shader);
	}

	u32 TestRaytracing::PixelColor(glm::vec2 coord) const
	{
		u8 r = (u8)(coord.x * 255.0f);
		u8 g = (u8)(coord.y * 255.0f);

		// ABGR
		return 0xff000000 | (g << 8) | r;
	}

	void TestRaytracing::OnUIRender() {}
}
