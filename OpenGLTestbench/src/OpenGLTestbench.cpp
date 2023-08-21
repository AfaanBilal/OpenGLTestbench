/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"

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
#include "tests/TestRaytracing.h"

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;

	UIManager::Initialize(window);	
	
	test::Test* current = nullptr;
	test::Menu* menu = new test::Menu(current);
	current = menu;

	menu->AddTest<test::TestClearColor>("Clear color");
	menu->AddTest<test::TestBasicTriangle>("Basic Triangle");
	menu->AddTest<test::TestBasicQuad>("Basic Quad");
	menu->AddTest<test::TestTexture2D>("Basic Texture 2D");
	menu->AddTest<test::TestRaytracing>("Raytracing");

	while (!glfwWindowShouldClose(window))
	{
		Renderer::Clear();

		UIManager::SetupFrame();

		if (current)
		{
			current->OnUpdate(0.0f);
			current->OnRender();

			ImGui::Begin("OpenGL Testbench");
			ImGui::Text("Author: Afaan Bilal");
			ImGui::Text("https://afaan.dev");
			ImGui::Separator();
			ImGui::Text("%.1f FPS %.3f ms per frame", ImGui::GetIO().Framerate, 1000.0f / ImGui::GetIO().Framerate);
			ImGui::End();

			ImGui::Begin("Test");

			if (current != menu && ImGui::Button("Close", { 100, 40 }))
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
