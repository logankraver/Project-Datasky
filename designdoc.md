The Design Document for the Game

INFRASTRUCTURE
Shader Class
- Stores shader program/ID
- Initializes shader program based on file path for vertex/fragment shaders
- Uniform helper functions to input values

Texture Class
- Creates texture object utilizing STB_IMAGE
- Stores texture object to bind for use

WORLD GENERATION
Tile Class
- Just a single tile for the background floor
- Dimensions = 0.05 x 0.05 (0.01 = 1 unit)
- Classed with different tile types
- Where all of the actual rendering/drawing is done with OpenGL

Chunk Class
- 8x8 set of tiles
- Classified with different biome types

Global Map Class
- Map of all chunks (coordinate tuple : chunk object)
- Supposed to represent the world map
- Generated with equidistant surroundings (start 1x1, 3x3, 5x5, etc.)
- Needs to perform all biome generation/blending

Biome Generation
- Min of # of chunks for all biomes
- Random selection of biomes (once a biome is generated bias towards it)

THE PLAYER
Player Class

THE OBJECT-GENERATOR
Object Generator Class
- The class that procedurally generates all static objects in the game world
- Stores all game objects to access via rendering
- Takes objects that are specifically of object class

Object Class
- Parent class for static objects in the game world
- Contains all rendering information and functions

Tree Class
- Subclass of object
- Literally a tree

- Tree Generation:
* Map of all trees generated with a tuple with chunk and block coordinate

THE TO-DO LIST
- Generate 9 chunks using the global map class (DONE)
- Create player class
1. fix bugs with movement (DONE)
2. add movement with player sprite (DONE)
- add infinite world gen (DONE)
- render only spec chunks to help performance (DONE)
- Procedurally generated trees (DONE)