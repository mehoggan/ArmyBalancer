#version 150 core

in vec3 position;
in vec4 color;

out vec4 Color;

//uniform mat4 mvp;

void main()
{
  Color = color;
  //gl_Position = mvp * vec4(position, 0.0, 1.0);
  gl_Position = vec4(position, 1.0);
}
