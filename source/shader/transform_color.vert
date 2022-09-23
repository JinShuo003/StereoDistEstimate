#version 330 core
in vec3 vPos;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
in vec3 vColor;
out vec3 color;
void main()
{
    gl_Position = projection * view * model * vec4(vPos, 1.0);
    color = vColor;
}
