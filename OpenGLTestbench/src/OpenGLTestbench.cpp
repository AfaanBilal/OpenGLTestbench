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

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;

	UIManager::Initialize(window);

	/*Vertex vertices[] = {
		{ { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ {  0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ { -0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
	};

	VertexBuffer vb(vertices, sizeof(vertices));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(4);

	VertexArray va;
	va.AddBuffer(vb, layout);

	unsigned int indices[] = { 
		0, 1, 2, 
		2, 3, 0, 
	};

	IndexBuffer ib(indices, 6);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");*/
	
	Renderer renderer;

	test::Test* current = nullptr;
	test::Menu* menu = new test::Menu(current);
	current = menu;

	menu->AddTest<test::TestClearColor>("Clear color");
	menu->AddTest<test::TestBasicTriangle>("Basic Triangle");

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

	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
