#version 450

layout(location = 0) in vec3 normal;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 FragPos;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

void main() {

    vec3 lightColor = vec3(1.0);
    vec4 color = texture(texSampler, fragTexCoord);

    float ambientStrength = 0.1;
    vec3 ambient = vec3(ambientStrength * lightColor);

    vec3 norm = normalize(normal);
    vec3 lightPos = vec3(1.0, 0.0, 0.0); // TODO ADD AS AN UNIFORM
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec4 result = vec4(vec3(ambient + diffuse), 1.0) * color;

    outColor = result;
}
