#shader vertex
#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal; //
layout(location = 2) in vec2 inTexCoord;

out vec2 texCoord;
out vec3 FragPos;
out vec3 ourNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	gl_Position = projection * view * model * vec4(inPosition, 1.0);
	texCoord = inTexCoord;

	FragPos = vec3(model * vec4(inPosition, 1.0));
	ourNormal = mat3(transpose(inverse(model))) * inNormal;
}

#shader fragment
#version 330 core
out vec4 FragColor;

struct Material {
	vec4 color;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct LightingMap {
	vec4 color;
	vec3 ambient;
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct DirectionalLight {
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

    int lightIsSet;
};

struct PointLight {
	vec3 position;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

    int lightIsSet;
};

struct SpotLight {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

    int lightIsSet;
};

in vec2 texCoord;
in vec3 ourNormal;
in vec3 FragPos;

uniform int type;

uniform vec3 viewPos;
uniform Material material;
uniform LightingMap lightingMap;
uniform DirectionalLight directionalLight;
uniform PointLight pointLights[4];
uniform SpotLight spotLight;

vec3 CalcShapeDirLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalcShapePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcShapeSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

vec3 CalcDirLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main() {
	if (type == 0) {
        vec3 norm = normalize(ourNormal);
        vec3 viewDir = normalize(viewPos - FragPos);
        
        vec3 result;

        if (directionalLight.lightIsSet == 1)
            result = CalcShapeDirLight(directionalLight, norm, viewDir);

        for(int i = 0; i < 4; i++)
            if (pointLights[i].lightIsSet == 1)
                result += CalcShapePointLight(pointLights[i], norm, FragPos, viewDir);    
        
        if (spotLight.lightIsSet == 1)
            result += CalcShapeSpotLight(spotLight, norm, FragPos, viewDir);    

		FragColor = vec4(result, 1.0) * material.color;
	}
	else if (type == 1) {
        vec3 norm = normalize(ourNormal);
        vec3 viewDir = normalize(viewPos - FragPos);

        vec3 result;

        if (directionalLight.lightIsSet == 1)
            result = CalcDirLight(directionalLight, norm, viewDir);

        for(int i = 0; i < 4; i++)
            if (pointLights[i].lightIsSet == 1)
                result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);
        
        if (spotLight.lightIsSet == 1)
            result += CalcSpotLight(spotLight, norm, FragPos, viewDir);

		FragColor = vec4(result, 1.0) * material.color;
	}
}

vec3 CalcDirLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(lightingMap.specular, texCoord));
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(lightingMap.specular, texCoord));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(lightingMap.diffuse, texCoord));
    vec3 specular = light.specular * spec * vec3(texture(lightingMap.specular, texCoord));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}

vec3 CalcShapeDirLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient = light.ambient * material.diffuse;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    return (ambient + diffuse + specular);
}

vec3 CalcShapePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * material.diffuse;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 CalcShapeSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir) 
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    vec3 ambient = light.ambient * material.diffuse;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}