#version 450 core

in vec3 iColor;
in vec2 iTexcoord;

out vec4 oColor;

uniform sampler2D uSampler1;
uniform sampler2D uSampler2;

void main()
{
  oColor = vec4(iColor, 1.0) * mix(
    texture(uSampler1, iTexcoord),
    texture(uSampler2, iTexcoord), 0.5);
}
