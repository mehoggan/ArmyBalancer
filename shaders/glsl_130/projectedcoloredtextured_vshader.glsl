attribute vec3 iPosition;
attribute vec3 iColor;
attribute vec2 iTexcoord;

invariant varying vec4 oColor;
invariant varying vec2 oTexcoord;

uniform mat4 uMVP;

void main()
{
  oColor = vec4(iColor, 1.0);
  oTexcoord = iTexcoord;
  gl_Position = uMVP * vec4(iPosition, 1.0);
}
