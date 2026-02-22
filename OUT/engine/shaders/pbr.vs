#version 460 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aUV;

uniform mat4 uView;
uniform mat4 uProjection;

out vec2 iUV;

void main()
{
   gl_Position = uProjection * inverse(uView) * vec4(aPosition.x, aPosition.y, aPosition.z, 1.0);
   iUV = aUV;
}