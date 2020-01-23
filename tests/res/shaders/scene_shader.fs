#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;

void main(){

    if (gl_FragCoord.x < (sin(gl_FragCoord.y / 10) + 1) * 10 + 1920 / 3.55 || gl_FragCoord.x > (sin(gl_FragCoord.y / 10) + 1) * 10 + 1920 - 1920 / 3.55){

        if (gl_FragCoord.y > (sin(gl_FragCoord.x / 10) + 1) * 10 + 1080 / 2){

            FragColor = vec4(1.0, 1.0, 0.0, 1.0);

        } else {

            FragColor = vec4(1.0, 0.0, 0.0, 1.0);

        }

    } else {

        if (gl_FragCoord.y > sin(gl_FragCoord.x / 10) * 10 + 1 * 1080 / 2){

            FragColor = vec4(0.0, 1.0, 0.0, 1.0);

        } else {

            FragColor = vec4(0.0, 0.0, 1.0, 1.0);

        }
    }

    FragColor = mix(texture(texture1, TexCoord), FragColor, 0.5);

}