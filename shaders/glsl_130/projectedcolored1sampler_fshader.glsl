invariant varying vec4 oColor;
invariant varying vec2 oTexcoord;

uniform sampler2D uSampler1;
uniform vec4 uColor;

void main()
{
  gl_FragColor = uColor * oColor * texture2D(uSampler1, oTexcoord);
}
