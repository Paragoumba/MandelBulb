#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;

void main(){

    if (gl_FragCoord.x < 1920 / 3.25 || gl_FragCoord.x > 1920 - 1920 / 3.25){

        if (gl_FragCoord.y > 1080 / 2){

            FragColor = vec4(1.0, 1.0, 0.0, 1.0);

        } else {

            FragColor = vec4(1.0, 0.0, 0.0, 1.0);

        }

    } else {

        if (gl_FragCoord.y > 1080 / 2){

            FragColor = vec4(0.0, 1.0, 0.0, 1.0);

        } else {

            FragColor = vec4(0.0, 0.0, 1.0, 1.0);

        }
    }

    FragColor = mix(texture(texture1, TexCoord), FragColor, 0.5);

}