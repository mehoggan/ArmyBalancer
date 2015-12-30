﻿#version 310 es

in vec3 iPosition;
in vec3 iColor;
in vec2 iTexcoord;

out vec4 oColor;
out vec2 oTexcoord;

uniform mat4 uMVP;

void main()
{
  oColor = vec4(iColor, 1.0);
  oTexcoord = iTexcoord;
  gl_Position = uMVP * vec4(iPosition, 1.0);
}
