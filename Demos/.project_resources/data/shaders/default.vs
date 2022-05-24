#version 330
layout( location = 0 ) in vec3 position;
layout( location = 1 ) in vec3 normal;
layout( location = 2 ) in vec2 texCoords;


out vec2 TexCoords;
out vec4 FragPos;
out vec3 Normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 noRotModelMat;
 
void main() 
{ 
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
    FragPos = modelMatrix * vec4(position,1.0);
    Normal = mat3(modelMatrix) * normal;
    TexCoords = texCoords;
} 