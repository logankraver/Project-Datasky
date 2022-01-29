#ifndef TEXTURE_H
#define TEXTURE_H

class texture {
    public:
        //texture reference number
        unsigned int ID;

        //constructor
        texture(const char* imagepath);

        //bind texture
        void bind();
};

#endif