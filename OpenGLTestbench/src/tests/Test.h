#pragma once
/**
 * OpenGL Testbench
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @link   https://github.com/AfaanBilal/OpenGLTestbench
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "Renderer.h"

namespace test
{

	class Test
	{
	public:
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate(float deltaTime) {}
		virtual void OnRender(Renderer& renderer) {}
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
