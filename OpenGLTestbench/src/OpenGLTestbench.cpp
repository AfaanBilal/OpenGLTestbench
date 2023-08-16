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

#include "tests/TestClearColor.h"

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;

	UIManager::Initialize(window);

	ShaderManager shaderManager("src/shaders/basic.vert", "src/shaders/basic.frag");

	Vertex vertices[] = {
		{ { -0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ {  0.5f, -0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ {  0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
		{ { -0.5f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },
	};

	VertexBuffer vb(vertices, sizeof(vertices));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));

	unsigned int indices[] = { 
		0, 1, 2, 
		2, 3, 0, 
	};

	IndexBuffer ib(indices, 6);

	shaderManager.Load();

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
		ib.Bind();
		renderer.Draw(indices);

		UIManager::RenderFrame();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderManager.Unload();
	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
