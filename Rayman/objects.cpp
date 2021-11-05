#include "objects.h"

Block::Block(int size, Position* pos) : size(size) {                            //BLOCK
    image = al_load_bitmap("res/images/block.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Block;
}

Brick::Brick(Position* pos) {                                                   //BRICK
    image = al_load_bitmap("res/images/brick.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Brick;
}

void Brick::update(ALLEGRO_EVENT event) {

}

void Brick::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Brick::moveLeft() {
    box->update(box->left - 5, box->top);
}

Bush::Bush(BushType type, Position* pos) : type(type) {                         //BUSH
    switch (type) {
    case Bush::Big:
        image = al_load_bitmap("res/images/bush-big.png");
        break;
    case Bush::Medium:
        image = al_load_bitmap("res/images/bush-medium.png");
        break;
    case Bush::Small:
        image = al_load_bitmap("res/images/bush-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Bush;
}

void Bush::update(ALLEGRO_EVENT event) {

}

void Bush::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Bush::moveLeft() {
    box->update(box->left - 5, box->top);
}

Castle::Castle(Position* pos) {                                                 //CASTLE
    image = al_load_bitmap("res/images/castle.png");
    position = pos;
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Castle;
}

void Castle::update(ALLEGRO_EVENT event) {

}

void Castle::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Castle::moveLeft() {
    box->update(box->left - 5, box->top);
}

Cloud::Cloud(CloudType type, Position* pos) : type(type) {                  //CLOUD
    switch (type) {
    case Cloud::Big:
        image = al_load_bitmap("res/images/cloud-big.png");
        break;
    case Cloud::Medium:
        image = al_load_bitmap("res/images/cloud-medium.png");
        break;
    case Cloud::Small:
        image = al_load_bitmap("res/images/cloud-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Cloud;
}

void Cloud::update(ALLEGRO_EVENT event) {

}

void Cloud::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Cloud::moveLeft() {
    box->update(box->left - 5, box->top);
}

Enemy::Enemy()                                                      //ENEMY
{
}

void Enemy::update(ALLEGRO_EVENT event) {

}

void Enemy::draw() {

}

void Enemy::moveLeft() {

}

Flag::Flag(Position* pos) {                                         //FLAG
    image = al_load_bitmap("res/images/flag.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Bush;
}

void Flag::update(ALLEGRO_EVENT event) {

}

void Flag::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Flag::moveLeft() {
    box->update(box->left - 5, box->top);
}

Hill::Hill(HillType type, Position* pos) : type(type) {             //HILL
    switch (type) {
    case Hill::Big:
        image = al_load_bitmap("res/images/hill-big.png");
        break;
    case Hill::Small:
        image = al_load_bitmap("res/images/hill-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Hill;
}

void Hill::update(ALLEGRO_EVENT event) {

}

void Hill::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Hill::moveLeft() {
    box->update(box->left - 5, box->top);
}

Owl::Owl(Position* pos) {                                           //OWL
    image = al_load_bitmap("res/images/owl.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth / 2 * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(imageWidth / 2 * i, 0, imageWidth / 2, imageHeight);

    currentFrameNumber = 1;
    dir = Left;
    currentFrame = walk[1];
    moveSpeed = 1;
    gravity = 0.5;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    isCollidable = true;
}

void Owl::update(ALLEGRO_EVENT event) {
    if (dir == Left) {
        if (!isObstacleOnLeft)
            velocity.first = -moveSpeed;
    }
    else {
        if (!isObstacleOnRight)
            velocity.first = moveSpeed;
    }
    currentFrameNumber += frameChangeSpeed;
    if (currentFrameNumber >= 4)
        currentFrameNumber = 0;
    currentFrame = walk[(int)currentFrameNumber / 2];
}

void Owl::draw() {
    al_draw_scaled_bitmap(image, currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height
        , box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Owl::moveLeft() {
    box->update(box->left - 5, box->top);
}

Pipe::Pipe(PipeType type, Position* pos) : type(type) {             //PIPE
    switch (type) {
    case Pipe::Big:
        image = al_load_bitmap("res/images/pipe-big.png");
        break;
    case Pipe::Medium:
        image = al_load_bitmap("res/images/pipe-medium.png");
        break;
    case Pipe::Small:
        image = al_load_bitmap("res/images/pipe-small.png");
        break;
    }
    position = pos;
    isCollidable = true;
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Pipe;
}

void Pipe::update(ALLEGRO_EVENT event) {

}

void Pipe::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Pipe::moveLeft() {
    box->update(box->left - 5, box->top);
}

SecretBox::SecretBox(SecretBoxType type, Position* pos) : type(type) {      //SECRETBOX
    switch (type) {
    case SecretBox::Coin:
    case SecretBox::Mushroom:
        image = al_load_bitmap("res/images/secret-box.png");
        break;
    case SecretBox::Brick_Coin:
    case SecretBox::Brick_Star:
        image = al_load_bitmap("res/images/brick.png");
        break;
    case SecretBox::Hidden:
        image = al_load_bitmap("res/images/solid.png");
        isHidden = true;
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::SecretBox;
}

void SecretBox::update(ALLEGRO_EVENT event) {

}

void SecretBox::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void SecretBox::moveLeft() {
    box->update(box->left - 5, box->top);
}

Turtle::Turtle(Position* pos) {                                 //TURTLE
    image = al_load_bitmap("res/images/turtle.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth / 2 * SCALE;
    scaledHeight = imageHeight / 3 * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObjects::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(imageWidth / 2 * i, imageHeight / 3 * 2, imageWidth / 2, imageHeight / 3);

    currentFrameNumber = 0;
    dir = Left;
    currentFrame = walk[0];
    moveSpeed = 1;
    gravity = 0.5;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    isCollidable = true;
}

void Turtle::update(ALLEGRO_EVENT event) {
    if (dir == Left) {
        if (!isObstacleOnLeft)
            velocity.first = -moveSpeed;
    }
    else {
        if (!isObstacleOnRight)
            velocity.first = moveSpeed;
    }
    currentFrameNumber += frameChangeSpeed;
    if (currentFrameNumber >= 4)
        currentFrameNumber = 0;
    currentFrame = walk[(int)currentFrameNumber / 2];
}

void Turtle::draw() {
    al_draw_scaled_bitmap(image, currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height
        , box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Turtle::moveLeft() {
    box->update(box->left - 5, box->top);
}

Wall::Wall(std::pair<int, int> xRange, int y) : xRange(xRange), y(y) {      //WALL
    image = al_load_bitmap("res/images/wall.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    isCollidable = true;
    width = xRange.second - xRange.first;
    height = 100;

    box = new Rectangle(xRange.first, y, width, height);
    objectType = GameObjects::Wall;
}

void Wall::update(ALLEGRO_EVENT event) {

}

void Wall::draw() {
    for (int i = box->left; i < box->right; i += scaledWidth) {
        for (int j = y; j < y + height; j += scaledHeight) {
            al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, i, j, scaledWidth, scaledHeight, 0);
        }
    }
}

void Wall::moveLeft() {
    box->update(box->left - 5, box->top);
}
