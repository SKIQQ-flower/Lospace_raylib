#pragma once
#include "raylib.h"
#include <map>
#include <vector>

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player
{
public:
    /*
    Player(const Vector2 &pos)
        : speed_(900),
          sprite("./assets/characters/soun.png", frame_width, frame_height,
                 animations, (speed / 200.0) / 0.1f)
    {
    }
    */

   /*
    Player(const Vector2 &pos, int speed)
        : speed_(speed),
          sprite("./assets/characters/soun.png", frame_width, frame_height,
                 animations, (speed / 200.0) / 0.1f)
    {
    }
    */
    
    Player(const Vector2 &pos) : speed_(100) {}

    void Update();
    //void Update(std::vector<Rectangle> recs);
    Vector2 position = Vector2{0.0f, 0.0f};
    // For collision
    // const Rectangle &GetCollision() const { return collision_rec; }
    /** Vector2 GetPreviousPosition() const
    {
      return previous_position_;
    }
    */

private:
    Vector2 velocity = Vector2{0.0f, 0.0f};
    //int frame_width = 0;
    //int frame_height = 0; // dummy values
    //add a "animations" variable for all player animations to be played in animatedsprite
    //AnimatedSprite sprite;
    int speed_;
    Direction direction = Direction::DOWN;
    Vector2 input_vector = Vector2{0, 0};
    // For collision
    // Vector2 previous_position_ = Vector2(0, 0);
    // Rectangle collision_rec = Rectangle(24, 13, 43, 3);
};