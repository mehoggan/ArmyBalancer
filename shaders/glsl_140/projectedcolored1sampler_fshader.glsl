#version 310 es

in highp vec4 oColor;
in highp vec2 oTexcoord;

out highp vec4 xColor;

uniform highp sampler2D uSampler1;
uniform highp vec4 uColor;

void main()
{
  xColor = uColor * oColor * texture(uSampler1, oTexcoord);
}
