#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"
#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "Test.h"

typedef uint32_t u32;

namespace test
{
	class MemoryTexture
	{
	private:
		unsigned int m_RendererID;
		size_t m_Width, m_Height;
	public:
		MemoryTexture();
		~MemoryTexture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
		void Reset() const;

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		u32* m_LocalBuffer;
	};

	class TestRaytracing: public Test
	{
	public:
		TestRaytracing();
		~TestRaytracing();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnUIRender() override;
	private:
		std::unique_ptr<MemoryTexture> m_Texture;

		glm::mat4 m_Proj, m_View;
		glm::vec3 m_Translation;
	};
}
