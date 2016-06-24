attribute vec3 a_position;

uniform mat4 u_MVP;

void main() {

    vec4 position = vec4(a_position, 1.0);

    gl_Position = u_MVP * position;
}