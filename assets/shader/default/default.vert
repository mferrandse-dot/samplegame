#version 450

layout(binding = 0) uniform UniformBufferObject {
    mat4 view;
    mat4 proj;
} ubo;

layout(push_constant) uniform PushConstant {
    mat4 model;
} pc;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 normal;
layout(location = 1) out vec2 fragTexCoord;
layout(location = 2) out vec3 FragPos;

void main() {
    vec4 pos = ubo.proj * ubo.view * pc.model * vec4(inPosition, 1.0);
    gl_Position = pos;
    fragTexCoord = inTexCoord;
    normal = inNormal;
    FragPos = vec3(pc.model * vec4(inPosition, 1.0));
}
