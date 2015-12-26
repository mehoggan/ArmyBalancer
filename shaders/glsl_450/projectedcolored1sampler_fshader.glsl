#version 450 core

in vec4 oColor;
in vec2 oTexcoord;

out vec4 xColor;

uniform sampler2D uSampler1;
uniform vec4 uColor;

void main()
{
  xColor = uColor * oColor * texture2D(uSampler1, oTexcoord);
}
