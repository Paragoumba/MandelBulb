#define STB_IMAGE_IMPLEMENTATION

#include <cstdlib>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <chrono>
#include <thread>

#include "Shader.hpp"

int winWidth = 800;
int winHeight = 600;

void windowResizeCallback(GLFWwindow*, int width, int height){

    winWidth = width;
    winHeight = height;

    glViewport(0, 0, width, height);

}

void input(GLFWwindow *window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){

        glfwSetWindowShouldClose(window, true);

    }
}

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwSwapInterval(1);

    GLFWwindow* window = glfwCreateWindow(winWidth, winHeight, "Obamium", nullptr, nullptr);

    if (window == nullptr){

        std::cout << "Failed to create window." << std::endl;
        glfwTerminate();
        return 1;

    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){

        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return 1;

    }

    glViewport(0, 0, winWidth, winHeight);

    glfwSetFramebufferSizeCallback(window, windowResizeCallback);

    glClearColor(0.4f, 0.3f, 0.5f, 1.0f);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float vertices[] = {
             0.5f,   0.55f, 0.0f, 1.0f, 1.0f, // top
             0.0f,   0.05f, 0.0f, 0.5f, 0.5f,
            -0.5f,   0.55f, 0.0f, 0.0f, 1.0f,

             0.5f,  -0.55f, 0.0f, 1.0f, 0.0f, // bottom
            -0.5f,  -0.55f, 0.0f, 0.0f, 0.0f,
            -0.0f,  -0.05f, 0.0f, 0.5f, 0.5f,

             0.55f, -0.5f,  0.0f, 1.0f, 0.0f, // right
             0.55f,  0.5f,  0.0f, 1.0f, 1.0f,
             0.05f,  0.0f,  0.0f, 0.5f, 0.5f,

            -0.55f,  0.5f,  0.0f, 0.0f, 1.0f,  // left
            -0.55f, -0.5f,  0.0f, 0.0f, 0.0f,
            -0.05f,  0.0f,  0.0f, 0.5f, 0.5f
    };

    unsigned int indices[] = {
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            9, 10, 11
    };

    float texCoords[] = {
             // lower-left corner
             // lower-right corner
             // top-center corner
             // lower-left corner
             // lower-right corner
             // top-center corner
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    Shader ourShader("../res/shader.vs", "../res/shader.fs");

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);

    // Texture attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int texture1, texture2;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("../res/container.jpg", &width, &height, &nrChannels, 0);

    if (data){

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {

        std::cout << "Failed to load texture" << std::endl;

    }

    stbi_image_free(data);

    // texture 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    data = stbi_load("../res/awesomeface2.png", &width, &height, &nrChannels, 0);

    if (data){

        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {

        std::cout << "Failed to load texture" << std::endl;

    }

    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);

    glm::mat4 model = glm::rotate(glm::mat4(1.0), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection = glm::perspective(glm::radians(60.0f), (float) winWidth / (float) winWidth, 0.1f, 100.0f);

    int stats[width];
    int i = 0;

    if (data){

        /*for (int x = 0; x < width; ++x){
            for (int y = 0; y < height; ++y){

                std::cout << data[width * y + x];

            }

            std::cout << std::endl;

        }*/
    }

    srand(time(nullptr));

    while(!glfwWindowShouldClose(window)){

        if (i >= width){

            i =0;

        }

        stats[i] = rand() % height;

        if (data != nullptr) for (int j = 0; j < i; j += nrChannels){

            data[(height - stats[j]) * 3 + j] = 0;
            data[(height - stats[j]) * 3 + j + 1] = 0;
            data[(height - stats[j]) * 3 + j + 2] = 255;

        }

        glBindTexture(GL_TEXTURE_2D, texture2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        ++i;

        input(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        glm::mat4 transform = glm::mat4(1.0);

        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float) glfwGetTime(), glm::vec3(0.0f, 1.0f, 1.0f));

        ourShader.use();
        ourShader.setMat4f("model", model);
        ourShader.setMat4f("view", view);
        ourShader.setMat4f("projection", projection);
        ourShader.setMat4f("transform", transform);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

        transform = glm::mat4(1.0);
        transform = glm::translate(transform, glm::vec3(-0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float) sin(glfwGetTime()), glm::vec3(0.0f, 1.0f, 1.0f));
        ourShader.setMat4f("transform", transform);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

        transform = glm::mat4(1.0);
        transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
        float scale = (sin((float) glfwGetTime()) + 3) / 2.5f;
        transform = glm::scale(transform, glm::vec3(scale, scale, scale));

        ourShader.setMat4f("transform", transform);

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

        transform = glm::mat4(1.0);
        transform = glm::translate(transform, glm::vec3(0.5f, 0.5f, 0.0f));
        transform = glm::scale(transform, glm::vec3(1 / scale, 1 / scale, 1 / scale));

        ourShader.setMat4f("transform", transform);

        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
        glUseProgram(0);

        glfwSwapBuffers(window);
        glfwPollEvents();

        std::this_thread::sleep_for(std::chrono::milliseconds(7));

    }

    stbi_image_free(data);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();

    return EXIT_SUCCESS;

}