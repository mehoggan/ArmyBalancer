#version 100

attribute vec3 position;
attribute vec4 color;

varying vec4 Color;

uniform mat4 mvp;

void main()
{
  Color = color;
  gl_Position = mvp * vec4(position, 1.0);
}
