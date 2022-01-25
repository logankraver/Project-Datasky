#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//infrastructure
#include </home/logan/C++ Graphics/game/shader.h>
#include </home/logan/C++ Graphics/game/texture.h>

//tile map
#include </home/logan/C++ Graphics/game/tile.h>
#include </home/logan/C++ Graphics/game/chunk.h>
#include </home/logan/C++ Graphics/game/globalmap.h>

//objects
#include </home/logan/C++ Graphics/game/tree.h>

#include </home/logan/C++ Graphics/game/player.h>

#include <iostream>

//functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, player *playerchar);


//global vars
//-----------
//screen vars
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;
//-----------
//delta vars
float deltatime = 0.0f;
float lastframe = 0.0f;
float movementSpeed = 0.5f; 

int main() {

    //setting up GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //window creation
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //viewport creation
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //initalize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //projection matrix
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT, 0.1f, 100.0f);

    //player
    player playercharacter;
    player *ptrPlayer = &playercharacter;

    //global map
    globalmap worldmap;
    
    //shaders
    shader spriteShader("shaders/sprite.vert", "shaders/sprite.frag");

    //textures
    texture texturemap("textures/texturemap.png");
    texturemap.bind();

    //game loop
    while (!glfwWindowShouldClose(window))
    {
        //delta operations
        float currentframe = glfwGetTime();
        deltatime = currentframe - lastframe;
        lastframe = currentframe;

        //process input
        processInput(window, ptrPlayer);

        //render
        glClearColor(0.7f, 0.7f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        spriteShader.use();
        spriteShader.setMat4("projection", projection);

        worldmap.render(spriteShader, playercharacter);
        playercharacter.render(spriteShader);

        worldmap.passiveGeneration(playercharacter);
        
        //swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;

}

void processInput(GLFWwindow* window, player *playerchar) {
    //exit
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }
    
    //movement
    if (glfwGetKey(window, GLFW_KEY_W))
    {
        float velocity = movementSpeed * deltatime;
        playerchar->move(UP, velocity);
    }
    else if (glfwGetKey(window, GLFW_KEY_A))
    {
        float velocity = movementSpeed * deltatime;
        playerchar->move(LEFT, velocity);
    }
    else if (glfwGetKey(window, GLFW_KEY_S))
    {
        float velocity = movementSpeed * deltatime;
        playerchar->move(DOWN, velocity);
    }
    else if (glfwGetKey(window, GLFW_KEY_D))
    {
        float velocity = movementSpeed * deltatime;
        playerchar->move(RIGHT, velocity);
    }
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

