#version 460 core
out vec4 FragColor;

in vec2 iUV;

void main()
{
    FragColor = vec4(iUV, 0.2, 1);
} 