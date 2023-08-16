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

namespace test
{
	class TestClearColor: public Test
	{
	public:
		TestClearColor();
		~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnUIRender() override;
	private:
		glm::vec4 m_ClearColor;
	};
}
