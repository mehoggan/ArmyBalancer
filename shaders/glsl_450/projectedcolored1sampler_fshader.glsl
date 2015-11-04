#version 450 core

in vec4 oColor;
in vec2 oTexcoord;

out vec4 xColor;

uniform sampler2D uSampler1;

void main()
{
  xColor = oColor * texture(uSampler1, oTexcoord);
}
