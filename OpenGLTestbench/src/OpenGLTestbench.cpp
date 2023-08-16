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
#include "ShaderManager.h"
#include "Renderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include "tests/TestClearColor.h"

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;

	UIManager::Initialize(window);

	Vertex vertices[] = {
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

	ShaderManager shaderManager("src/shaders/basic.vert", "src/shaders/basic.frag");
	shaderManager.Bind();

	Renderer renderer;
	test::TestClearColor test;

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		test.OnUpdate(0.0f);
		test.OnRender();

		UIManager::SetupFrame();

		test.OnUIRender();

		ImGui::ShowDemoWindow();

		vb.Bind();
		va.Bind();
		ib.Bind();
		renderer.Draw(indices);

		UIManager::RenderFrame();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderManager.Unbind();
	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
