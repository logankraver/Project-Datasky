#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//infrastructure
#include </home/logan/C++ Graphics/Project Datasky/src/shaders/shader.h>
#include </home/logan/C++ Graphics/Project Datasky/src/textures/texture.h>

//world gen
#include </home/logan/C++ Graphics/Project Datasky/src/worldgen/tile.h>
#include </home/logan/C++ Graphics/Project Datasky/src/worldgen/chunk.h>
#include </home/logan/C++ Graphics/Project Datasky/src/worldgen/globalmap.h>

//objects
#include </home/logan/C++ Graphics/Project Datasky/src/objects/tree.h>
#include </home/logan/C++ Graphics/Project Datasky/src/objects/objectgenerator.h>


#include </home/logan/C++ Graphics/Project Datasky/src/player/player.h>

#include <iostream>

//functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow* window);
void move_player(player *playerchar);

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

//player
player playercharacter;

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

    //key callback
    glfwSetKeyCallback(window, key_callback);

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
    playercharacter.initialize();

    //object generator
    objectGenerator oGen;

    //global map
    globalmap worldmap(oGen);
    
    //shaders
    shader spriteShader("../src/shaders/sprite.vert", "../src/shaders/sprite.frag");

    //textures
    texture texturemap("../src/textures/texturemap.png");
    texturemap.bind();

    //game loop
    while (!glfwWindowShouldClose(window))
    {
        //delta operations
        float currentframe = glfwGetTime();
        deltatime = currentframe - lastframe;
        lastframe = currentframe;

        //process input
        processInput(window);

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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_RELEASE)
    {
        playercharacter.moving = false;
    }
    else if (key == GLFW_KEY_A && action == GLFW_RELEASE)
    {
        playercharacter.moving = false;
    }
    else if (key == GLFW_KEY_S && action == GLFW_RELEASE)
    {
        playercharacter.moving = false;
    }
    else if (key == GLFW_KEY_D && action == GLFW_RELEASE)
    {
        playercharacter.moving = false;
    }
    
}

void processInput(GLFWwindow* window) 
{
    //exit
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }
    
    //movement
    if (glfwGetKey(window, GLFW_KEY_W))
    {
        float velocity = movementSpeed * deltatime;
        playercharacter.move(UP, velocity);
        playercharacter.playerdirection = UP;
    } 
    else if (glfwGetKey(window, GLFW_KEY_A))
    {
        float velocity = movementSpeed * deltatime;
        playercharacter.move(LEFT, velocity);
        playercharacter.playerdirection = LEFT;
    }
    else if (glfwGetKey(window, GLFW_KEY_S))
    {
        float velocity = movementSpeed * deltatime;
        playercharacter.move(DOWN, velocity);
        playercharacter.playerdirection = DOWN;
    }
    else if (glfwGetKey(window, GLFW_KEY_D))
    {
        float velocity = movementSpeed * deltatime;
        playercharacter.move(RIGHT, velocity);
        playercharacter.playerdirection = RIGHT;
    }
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

