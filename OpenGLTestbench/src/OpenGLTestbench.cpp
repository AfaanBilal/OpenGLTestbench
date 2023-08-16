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

int main()
{
	std::cout << "OpenGL Testbench" << std::endl;
	std::cout << "(c) Afaan Bilal - https://afaan.dev" << std::endl;

	GLFWwindow* window = WindowManager::Initialize();
	if (window == nullptr)
		return -1;
	
	UIManager::Initialize(window);

	float vertices[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f,
	};

	GLuint vb;
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();

		// ImGui frame setup
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow(); // Show demo window! :)

		// Rendering
		// (Your code clears your framebuffer, renders your other stuff etc.)

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		// (Your code calls glfwSwapBuffers() etc.)

		glfwSwapBuffers(window);
	}

	UIManager::Terminate();
	WindowManager::Terminate();
	return 0;
}
