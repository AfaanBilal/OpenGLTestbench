#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 o_color;

void main()
{
	gl_Position = position;
	o_color = color;
}
