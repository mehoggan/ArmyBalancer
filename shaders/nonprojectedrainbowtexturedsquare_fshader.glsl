#version 150 core

in vec3 Color;
in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D die1;

void main()
{
  outColor = texture(die1, Texcoord) * vec4(Color, 1.0);
}
