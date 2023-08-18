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
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <functional>
#include <memory>
#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "glm/glm.hpp"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "stb_image.h"
