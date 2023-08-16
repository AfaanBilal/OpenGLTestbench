#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "glm/vec4.hpp"

#include "Test.h"
#include "Vertex.h"

namespace test
{
	class TestBasicQuad : public Test
	{
	public:
		TestBasicQuad();
		~TestBasicQuad();

		void OnUpdate(float deltaTime) override;
		void OnRender(Renderer& renderer) override;
		void OnUIRender() override;
	private:
		Vertex m_Verticies[4];
		glm::vec4 m_Color;
	};
}
