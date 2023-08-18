/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "Test.h"

namespace test
{
	Menu::Menu(Test*& currentTest) : current(currentTest) {}

	void Menu::OnUIRender()
	{
		for (auto& test : m_Tests)
		{
			if (ImGui::Button(test.first.c_str()))
				current = test.second();
		}
	}
}
