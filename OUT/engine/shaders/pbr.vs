#version 460 core
layout (location = 0) in vec3 aPos;

uniform mat4 uView;
uniform mat4 uProjection;

void main()
{
   gl_Position = uProjection * inverse(uView) * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}