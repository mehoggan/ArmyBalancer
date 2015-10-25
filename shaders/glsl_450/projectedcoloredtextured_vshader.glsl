#version 450 core

in vec2 iPosition;
in vec3 iColor;
in vec2 iTexcoord;

out vec3 oColor;
out vec2 oTexcoord;

uniform mat4 uMVP;

void main()
{
  oColor = iColor;
  oTexcoord = iTexcoord;
  gl_Position = uMVP * vec4(iPosition, 0.0, 1.0);
}
