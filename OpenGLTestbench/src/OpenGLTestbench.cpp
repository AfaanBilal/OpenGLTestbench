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

#include "OpenGLTestbench.h"
#include "WindowManager.h"
#include "UIManager.h"
#include "ShaderManager.h"

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
		{ {  0.0f,  0.5f }, { 0.1f, 0.8f, 0.8f, 1.0f } },		 
	};

	GLuint vb;
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		UIManager::SetupFrame();

		ImGui::ShowDemoWindow();

		glClear(GL_COLOR_BUFFER_BIT);

		shaderManager.Load();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		UIManager::RenderFrame();
		glfwSwapBuffers(window);
	}

	shaderManager.Unload();
	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
