#version 330 core
in vec2 oTexture;
uniform sampler2D uTexture;
void main()
{
    gl_FragColor = texture(uTexture, oTexture);
} 
