#version 330
// Input
// TODO(student): Get vertex attributes from each location
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texCoord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float time;

// Output
// TODO(student): Output values to fragment shader
out vec3 color;
out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

vec4 computeClipsSpacePosition(vec3 objectSpaceposition)
{
	return Projection * View * Model * vec4(objectSpaceposition * vec3(1.0f,1,1), 1.0);
}

void main()
{
    color = v_color;
    texCoord = v_texCoord;
    normal = v_normal;
    fragPos = vec3(Model * vec4(1.0,sin(time),1.0, 1.0));


    // TODO(student): Compute gl_Position
gl_Position = computeClipsSpacePosition(v_position);

}