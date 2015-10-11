#version 150 core

in vec3 Color;
in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D die1;
uniform sampler2D die2;

void main()
{
  outColor = vec4(Color, 1.0) *
    mix(texture(die1, Texcoord), texture(die2, Texcoord), 0.5);
}
