#include "Player.hpp"
#include "Animation.hpp"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

std::string path="./images/Colour2/NoOutline/120x80_PNGSheets/";

void Player::move(int x, int y) {
    m_posX+=x;
    m_posY+=y;
}

void Player::changePos(int pos) {
    if(m_pos != pos) {
        m_pos = pos;
        move(pos*-360, 0);
    }
}

void Player::changeAnimation(Animation &animation) {
    if(m_currentAnimation == animation.getType()) return;
    m_animations[m_currentAnimation].restart();
    m_currentAnimation = animation.getType();
}

void Player::eachFrame(sf::RenderWindow &window) {
    m_animations[m_currentAnimation].play(window, m_posX, m_posY, m_pos);
}

Animation* Player::getAnimations() {
    return m_animations;
}

Animation::Animations Player::getCurrentAnimation() {
    return m_currentAnimation;
}
