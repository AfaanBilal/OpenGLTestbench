#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include "pch.h"
#include "Renderer.h"

namespace test
{

	class Test
	{
	public:
		Test() {}
		virtual ~Test() {}

		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr<IndexBuffer> m_IB;
		std::unique_ptr<Shader> m_Shader;

		virtual void OnUpdate(float deltaTime) {}
		virtual void OnRender() {}
		virtual void OnUIRender() {}
	};

	class Menu : public Test
	{
	public:
		Menu(Test*& currentTest);

		void OnUIRender();

		template<typename T>
		void AddTest(const std::string& name)
		{
			std::cout << "Adding test: " << name << std::endl;
			m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
		}
	private:
		Test*& current;
		std::vector<std::pair<std::string, std::function<Test* ()>>> m_Tests;
	};

}
