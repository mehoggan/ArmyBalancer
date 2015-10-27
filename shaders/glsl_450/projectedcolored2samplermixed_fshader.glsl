#version 450 core

in vec4 oColor;
in vec2 oTexcoord;

out vec4 xColor;

uniform sampler2D uSampler1;
uniform sampler2D uSampler2;

void main()
{
  xColor = oColor * mix(
    texture(uSampler1, oTexcoord),
    texture(uSampler2, oTexcoord), 0.5);
}
