#version 330
 
const int MaxLights = 32;

out vec4 FragColour; 
 
in vec2 TexCoords;
in vec4 FragPos;
in vec3 Normal;

#define LIGHT_POINT 0
#define LIGHT_DIRECTIONAL 1
#define LIGHT_SPOT 2


struct Light{
    int lightType;
    vec3 lightDirection;
    vec3 lightPosition;
    vec4 lightAmbientColor;
    vec4 lightDiffuseColor;
    vec4 lightSpecularColor;

    float lightIntensity;
    float lightLinear;
    float lightQuadratic;
};

// Lighting

uniform int lightCount = 0;
uniform Light lights[MaxLights];

uniform vec4 ambientColor;

// Material
uniform vec4 materialAmbientColor;
uniform vec4 materialDiffuseColor;
uniform vec4 materialSpecularColor;
uniform float materialSpecularPower;

uniform sampler2D materialAlbedoTexture;

// Camera
uniform vec3 cameraPosition;

vec4 calculateDirectionalLight(Light light){

    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(light.lightDirection);
    float lambertTerm = max(0,min(1,dot(normal, -lightDir)));

    vec3 view = normalize(cameraPosition - FragPos.xyz);
    vec3 refl = reflect(lightDir, normal);

    float specularTerm = pow(max(0, dot(refl, view)), light.lightIntensity);

    vec4 ambient = light.lightAmbientColor;
    vec4 diffuse = light.lightDiffuseColor * lambertTerm;
    vec4 specular = light.lightSpecularColor * specularTerm;

    return (ambient + diffuse + specularTerm);
}

vec4 calculatePointLight(Light light){
    return vec4(0);
}
vec4 calculateSpotLight(Light light){
    return vec4(0);
}

void main(){
    vec4 output = vec4(0);
    for(int i = 0; i < min(lightCount, MaxLights); i++)
    {
        if(lights[i].lightType == LIGHT_DIRECTIONAL){
            output += calculateDirectionalLight(lights[i]);
        }
        else if(lights[i].lightType == LIGHT_POINT){
            output += calculatePointLight(lights[i]);
        }
        else if(lights[i].lightType == LIGHT_SPOT){
            output += calculateSpotLight(lights[i]);
        }
    }
    //FragColour = vec4(1,0,0,1);
    FragColour = output * texture(materialAlbedoTexture, TexCoords);
}