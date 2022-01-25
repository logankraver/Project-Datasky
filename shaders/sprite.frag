#version 330 core
out vec4 FragColor;

in vec2 texCoords;

//texture samplers
uniform sampler2D spriteTexture;

void main()
{
    FragColor = texture(spriteTexture, texCoords);
}