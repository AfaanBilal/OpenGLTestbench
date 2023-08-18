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

#include "Vertex.h"
#include "Texture.h"

#include "Test.h"

namespace test
{
	class TestTexture2D : public Test
	{
	public:
		TestTexture2D();
		~TestTexture2D();

		void OnUpdate(float deltaTime) override;
		void OnRender(Renderer& renderer) override;
		void OnUIRender() override;
	private:
		std::unique_ptr<Texture> m_Texture;

		glm::mat4 m_Proj, m_View;
		glm::vec3 m_Translation;
	};
}
