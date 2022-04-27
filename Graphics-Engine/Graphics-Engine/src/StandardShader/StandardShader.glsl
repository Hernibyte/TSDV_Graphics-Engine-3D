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

struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec2 texCoord;
in vec3 ourNormal;
in vec3 FragPos;

uniform int type;

uniform sampler2D ourTexture;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main() {
	if (type == 0) {
		// ambient
		vec3 ambient = light.ambient * material.ambient;
  		
		// diffuse 
		vec3 norm = normalize(ourNormal);
		vec3 lightDir = normalize(light.position - FragPos);
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = light.diffuse * (diff * material.diffuse);
		
		// specular
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);  
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
		vec3 specular = light.specular * (spec * material.specular);  
		    
		vec3 result = ambient + diffuse + specular;

		FragColor = vec4(result, 1.0) * material.color;
	}
	else if (type == 1) {
		// ambient
		vec3 ambient = light.ambient * material.ambient;
  		
		// diffuse 
		vec3 norm = normalize(ourNormal);
		vec3 lightDir = normalize(light.position - FragPos);
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = light.diffuse * (diff * material.diffuse);
		
		// specular
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);  
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
		vec3 specular = light.specular * (spec * material.specular);  
		    
		vec3 result = ambient + diffuse + specular;

		FragColor = texture(ourTexture, texCoord) * vec4(result, 1.0) * material.color;
	}
}