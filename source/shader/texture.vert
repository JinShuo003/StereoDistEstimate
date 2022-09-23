#version 330 core
in vec3 vPos;
in vec2 vTexture;
out vec2 oTexture;
void main()
{
    gl_Position = vec4(vPos, 1.0);
    oTexture = vTexture;
}
