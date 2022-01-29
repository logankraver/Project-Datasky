#define STB_IMAGE_IMPLEMENTATION

#include "texture.h"

#include <glad/glad.h>
#include </home/logan/C++ Graphics/Project Datasky/libraries/stb_image.h>

#include <iostream>

texture::texture(const char* imagepath)
{
    //create and bind texture
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, this->ID);

    //set texture wrapping/filter options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //load image
    int width, height, nrchannels;
    unsigned char *data = stbi_load(imagepath, &width, &height, &nrchannels, STBI_rgb_alpha);

    for (int x = 0; x != width; x++)
    {
        for (int y = 0; y != height; y++)
        {
            unsigned char* pixelOffset = data + (x*width + y)*4;
            if (int(pixelOffset[0]) == 255 && int(pixelOffset[1]) == 255 && int(pixelOffset[2]) == 255)
            {
                unsigned char zero = 0;
                data[(x*width + y)*4+3] = zero;
            }
        }
    }

    //check if data extraction was successful
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture." << std::endl;
    }

    //unload image for memory
    stbi_image_free(data);

    //unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

}

void texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}