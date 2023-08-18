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
	struct VertexBasicTriangle
	{
		glm::vec2 position;
		glm::vec4 color;
	};

	class TestBasicTriangle: public Test
	{
	public:
		TestBasicTriangle();
		~TestBasicTriangle();

		void OnUpdate(float deltaTime) override;
		void OnRender(Renderer& renderer) override;
		void OnUIRender() override;
	private:
		VertexBasicTriangle m_Verticies[3];
	};
}
