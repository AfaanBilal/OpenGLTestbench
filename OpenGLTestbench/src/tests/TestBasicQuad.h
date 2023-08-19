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

#include "Test.h"

namespace test
{
	struct VertexBasicQuad
	{
		glm::vec2 position;
		glm::vec4 color;
	};

	class TestBasicQuad: public Test
	{
	public:
		TestBasicQuad();
		~TestBasicQuad();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnUIRender() override;
	private:
		VertexBasicQuad m_Verticies[4];
	};
}
