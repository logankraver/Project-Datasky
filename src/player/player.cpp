#include "player.h"

#include <iostream>

player::player()
{
    
}

void player::initialize()
{
    playerPosX = 0;
    playerPosY = 0;

    changeTexture(frontStill);
}

void player::move(movementChoices choice, float velocity)
{
    moving = true;
    if (choice == UP)
    {
        cameraPos = cameraPos + (glm::vec3(0.0f, 1.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(0.0f, 1.0f, 0.0f))*velocity;
        playerPosY = playerPosY + velocity;
        changeTexture(backWalking);
    }
    if (choice == DOWN)
    {
        cameraPos = cameraPos + (glm::vec3(0.0f, -1.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(0.0f, -1.0f, 0.0f))*velocity;
        playerPosY = playerPosY - velocity;
        changeTexture(frontWalking);
    }
    if (choice == LEFT)
    {
        cameraPos = cameraPos + (glm::vec3(-1.0f, 0.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(-1.0f, 0.0f, 0.0f))*velocity;
        playerPosX = playerPosX - velocity;
        changeTexture(leftWalking);
    }
    if (choice == RIGHT)
    {
        cameraPos = cameraPos + (glm::vec3(1.0f, 0.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(1.0f, 0.0f, 0.0f))*velocity;
        playerPosX = playerPosX + velocity;
        changeTexture(rightWalking);
    }
    view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
}   

void player::render(shader shader)
{
    if (!moving && playerdirection == UP)
    {
        changeTexture(backStill);
    }
    if (!moving && playerdirection == DOWN)
    {
        changeTexture(frontStill);
    }
    else if (!moving && playerdirection == RIGHT)
    {
        changeTexture(rightStill);
    }
    else if (!moving && playerdirection == LEFT)
    {
        changeTexture(leftStill);
    }

    //set view matrix
    shader.setMat4("view", view);
    
    //calculate model matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(playerPosX, playerPosY, 0.0f));
    
    //alternate animations
    if (moveswitch && playerdirection == UP && moving)
    {
        model = glm::scale(model, glm::vec3(-1.0f, 1.0f, 1.0f));
    }
    if (moveswitch && playerdirection == DOWN && moving)
    {
        model = glm::scale(model, glm::vec3(-1.0f, 1.0f, 1.0f));
    }
    if (moveswitch && playerdirection == RIGHT && moving)
    {
        if (currentanim == rightStill)
        {
            changeTexture(rightWalking);
        }
        else if (currentanim == rightWalking)
        {
            changeTexture(rightStill);
        }
    }
    if (moveswitch && playerdirection == LEFT && moving)
    {
        if (currentanim == leftStill)
        {
            changeTexture(leftWalking);
        }
        else if (currentanim == leftWalking)
        {
            changeTexture(leftStill);
        }
    }

    shader.setMat4("model", model);
    
    //draw sprite
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    //animations
    animationcounter = animationcounter + 1;
    if (animationcounter == 5)
    {
        moveswitch = !moveswitch;
        animationcounter = 0;
    }
}

std::tuple<int, int> player::getBlockCoordinate()
{
    int xBlock = int(playerPosX / 0.05f);
    int yBlock = int(playerPosY / 0.05f);
    std::tuple<int, int> blockCoordinate(xBlock, yBlock);
    return blockCoordinate;
}

std::tuple<int, int> player::getChunkCoordinate()
{
    std::tuple<int, int> blockCoordinate = getBlockCoordinate();
    int xChunk = int(std::get<0>(blockCoordinate) / 8.0f);
    int yChunk = int(std::get<1>(blockCoordinate) / 8.0f);
    std::tuple<int, int> chunkCoordinate(xChunk, yChunk);
    return chunkCoordinate;
}

void player::changeTexture(animtexture animation)
{
    //clear buffers and vertex array
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);
    glDeleteVertexArrays(1, &vertexArray);

    if (animation == frontStill)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.00000000f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.05078125f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.00000000f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.05078125f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = frontStill;
    }
    if (animation == frontWalking)
    {
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.05078125f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.10156250f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.05078125f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.10156250f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = frontWalking;
    }
    if (animation == rightStill)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.10156250f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.15234375f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.10156250f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.15234375f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = rightStill;
    }
    if (animation == rightWalking)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.15234375f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.20312500f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.15234375f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.20312500f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = rightWalking;
    }
    if (animation == leftStill)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.15234375f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.10156250f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.15234375f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.10156250f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = leftStill;
    }
    if (animation == leftWalking)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.20312500f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.15234375f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.20312500f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.15234375f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = leftWalking;
    }
    if (animation == backStill)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.20312500f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.25390625f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.20312500f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.25390625f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = backStill;
    }
    if (animation == backWalking)
    {
        //setup new vertices
        float newVertices[20] = {
            //pos                          //texure
            -0.0203125f, -0.0328125f, 0.0f, 0.25390625f, 1.00000000f, //bottom left
             0.0203125f, -0.0328125f, 0.0f, 0.30468750f, 1.00000000f, //bottom right
            -0.0203125f,  0.0328125f, 0.0f, 0.25390625f, 0.91796875f, //top left
             0.0203125f,  0.0328125f, 0.0f, 0.30468750f, 0.91796875f  //top right
        };
        for (int i = 0; i != 20; i++)
        {
            vertices[i] = newVertices[i];
        }
        currentanim = backWalking;
    }
    
    //setup buffers and vertex array
    glGenBuffers(1, &vertexBuffer);
    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &elementBuffer);

    //bind vertex buffer
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //bind element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //vertex attributes
    //-----------------
    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //texture coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
}