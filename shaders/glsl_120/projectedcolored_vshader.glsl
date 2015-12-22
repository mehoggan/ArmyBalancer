#version 150 core

in vec3 iPosition;
in vec4 iColor;

out vec4 oColor;

uniform mat4 uMVP;

void main()
{
  oColor = iColor;
  gl_Position = uMVP * vec4(iPosition, 1.0);
}
