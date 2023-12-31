#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"
#include "WindowManager.h"

#include "Test.h"

typedef uint8_t  u8;
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

		inline size_t GetWidth() { return m_Width; }
		inline size_t GetHeight() { return m_Height; }

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
		glm::vec4 PixelColor(glm::vec2 coord) const;
	private:
		std::unique_ptr<MemoryTexture> m_Texture;
		glm::vec3 m_RayOrigin;
	};
}
