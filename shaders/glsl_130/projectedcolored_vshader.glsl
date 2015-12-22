attribute vec3 iPosition;
attribute vec4 iColor;

varying vec4 oColor;

uniform mat4 uMVP;

void main()
{
  oColor = iColor;
  gl_Position = uMVP * vec4(iPosition, 1.0);
}
