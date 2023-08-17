#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoords;

out vec4 v_Color;
out vec2 v_TexCoords;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * position;
	v_Color = color;
	v_TexCoords = texCoords;
}
