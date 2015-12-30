#version 310 es

in highp vec4 oColor;
in highp vec2 oTexcoord;

out highp vec4 xColor;

uniform highp sampler2D uSampler1;
uniform highp sampler2D uSampler2;

void main()
{
  xColor = oColor * mix(
    texture(uSampler1, oTexcoord),
    texture(uSampler2, oTexcoord), 0.5);
}
