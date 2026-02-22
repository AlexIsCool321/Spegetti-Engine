#version 460 core
out vec4 FragColor;

in vec2 iUV;

uniform sampler2D color;

void main()
{
    FragColor = texture(color, iUV);
} 