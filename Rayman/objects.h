#ifndef OBJECTS_H
#define OBJECTS_H

#include "gameobjects.h"

class Block : public GameObjects {                  //BLOCK
    int size;
public:
    Block(int size, Position* pos);
};

class Brick : public GameObjects {                   //BRICK
public:
    Brick(Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Bush : public GameObjects {                   //BUSH
public:
    enum BushType { Big, Medium, Small };
    Bush(BushType type, Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    BushType type;
};

class Castle : public GameObjects {                  //CASTLE
public:
    Castle(Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Cloud : public GameObjects {                   //CLOUD
public:
    enum CloudType { Big, Medium, Small };
    Cloud(CloudType type, Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    CloudType type;
};

class Enemy : public GameObjects {                  //ENEMY
public:
    Enemy();
    virtual void update(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void moveLeft();
};

class Flag : public GameObjects {                   //FLAG
public:
    Flag(Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Hill : public GameObjects {                   //HILL
public:
    enum HillType { Big, Small };
    Hill(HillType type, Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    HillType type;
};

class Owl : public Enemy {                          //OWL
private:
    Rectangle* walk[2];
    Rectangle* currentFrame;
    enum Direction { Left, Right };
    Direction dir;
    float moveSpeed;
    float frameChangeSpeed = 0.1;
    float currentFrameNumber = 0;
    bool isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;
public:
    Owl(Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Pipe : public GameObjects {                   //PIPE
public:
    enum PipeType { Big, Medium, Small };
    Pipe(PipeType type, Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    PipeType type;
};

class SecretBox : public GameObjects {              //SECRETBOX
private:
    bool isHidden = false;
public:
    enum SecretBoxType { Coin, Mushroom, Brick_Coin, Brick_Star, Hidden };
    SecretBoxType type;
    SecretBox(SecretBoxType type, Position* pos);

    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Turtle : public Enemy {                       //TURTLE
private:
    Rectangle* walk[2];
    Rectangle* currentFrame;
    enum Direction { Left, Right };
    Direction dir;
    float moveSpeed;
    float frameChangeSpeed = 0.1;
    float currentFrameNumber = 0;
    bool isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;
public:
    Turtle(Position* pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

class Wall : public GameObjects {                   //WALL
private:
    std::pair<float, float> xRange;
    float y;
    float width, height;
public:
    Wall(std::pair<int, int> xRange, int y);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // OBJECTS_H