#ifndef PLAYER_H
#define PLAYER_H

#include "../shaders/shader.h"
#include <tuple>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum movementChoices {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

enum animtexture {
    frontStill,
    frontWalking,
    rightStill,
    rightWalking,
    leftStill,
    leftWalking,
    backStill,
    backWalking
};

class player {
    public:
        //pos vars
        float playerPosX;
        float playerPosY;

        //animation vars
        bool moving;
        bool moveswitch = true;
        int animationcounter = 0;
        enum movementChoices playerdirection = DOWN;
        enum animtexture currentanim = frontStill;

        //rendering vars
        float vertices[20];
        unsigned int vertexBuffer;
        unsigned int elementBuffer;
        unsigned int vertexArray;
        unsigned int indices[6] = {
            0, 1, 2,
            1, 2, 3
        };

        //camera vars
        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, cameraUp);

        player();

        void initialize();
        void changeTexture(animtexture animation);
        void move(movementChoices choice, float velocity);
        void render(shader shader);

        std::tuple<int, int> getBlockCoordinate();
        std::tuple<int, int> getChunkCoordinate();

};

#endif