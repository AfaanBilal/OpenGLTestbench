/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Vertex.h"
#include "WindowManager.h"
#include "UIManager.h"
#include "Shader.h"
#include "Renderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include "tests/Test.h"
#include "tests/TestClearColor.h"
#include "tests/TestBasicTriangle.h"
#include "tests/TestBasicQuad.h"
#include "tests/TestTexture2D.h"

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;

	UIManager::Initialize(window);	
	Renderer renderer;

	test::Test* current = nullptr;
	test::Menu* menu = new test::Menu(current);
	current = menu;

	menu->AddTest<test::TestClearColor>("Clear color");
	menu->AddTest<test::TestBasicTriangle>("Basic Triangle");
	menu->AddTest<test::TestBasicQuad>("Basic Quad");
	menu->AddTest<test::TestTexture2D>("Basic Texture 2D");

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		UIManager::SetupFrame();

		if (current)
		{
			current->OnUpdate(0.0f);
			current->OnRender(renderer);

			ImGui::Begin("Test");
			
			if (current != menu && ImGui::Button("<-"))
			{
				delete current;
				current = menu;
			}

			current->OnUIRender();
			ImGui::End();
		}

		//ImGui::ShowDemoWindow();

		UIManager::RenderFrame();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	if (current != menu)
		delete menu;
	delete current;

	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
