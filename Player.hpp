#ifndef PLAYERHPP
#define PLAYERHPP

#include "Animation.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

extern std::string path;

class Animation;

class Player {
private:
    Animation m_animations[Animation::TOTAL_ANIMATIONS];
    Animation::Animations m_currentAnimation;
    int m_posX;
    int m_posY;
    int m_pos;

public:
    Player(int posX=0, int posY=0, int pos=1) : m_posX(posX), m_posY(posY), m_pos(pos), m_currentAnimation(Animation::IDLE),
    m_animations{Animation(path + "_Attack.png", Animation::ATTACK, 4),
                 Animation(path + "_Run.png", Animation::RUN, 10),
                 Animation(path + "_Idle.png", Animation::IDLE, 10)}{
    }

    void move(int x, int y);
    void changePos(int pos);
    void changeAnimation(Animation &animation);
    void eachFrame(sf::RenderWindow &window);
    Animation* getAnimations();
    Animation::Animations getCurrentAnimation();

};

#endif // PLAYERHPP
