varying vec4 oColor;
varying vec2 oTexcoord;

uniform sampler2D uSampler1;
uniform sampler2D uSampler2;

void main()
{
  gl_FragColor = oColor * mix(
    texture2D(uSampler1, oTexcoord),
    texture2D(uSampler2, oTexcoord), 0.5);
}
