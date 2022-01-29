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

class player {
    public:
        //pos vars
        float playerPosX;
        float playerPosY;

        //rendering vars
        unsigned int vertexBuffer;
        unsigned int elementBuffer;
        unsigned int vertexArray;

        //camera vars
        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, cameraUp);

        player();

        void move(movementChoices choice, float velocity);
        void render(shader shader);

        std::tuple<int, int> getBlockCoordinate();
        std::tuple<int, int> getChunkCoordinate();

};

#endif