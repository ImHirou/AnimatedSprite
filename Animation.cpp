#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void Animation::play(sf::RenderWindow &window, int x=0, int y=0, int pos=1) {
    sf::Sprite sprite(m_texture);
    if(m_clock.getElapsedTime().asSeconds() >= m_delay) {
        if(m_currentPicture == m_frames) {
            m_currentPicture = 0;
            return;
        }
        m_currentPicture++;
        m_clock.restart();
    }
    sprite.setTextureRect(sf::IntRect(m_xSize*(m_currentPicture-1), m_texture.getSize().y-m_ySize, m_xSize, m_ySize));
    sprite.setScale(3*pos, 3);
    sprite.setPosition(x,y);
    window.draw(sprite);
}

int Animation::getFrames() {
    return m_frames;
}

float Animation::getDelay() {
    return m_delay;
}

void Animation::restart() {
    m_clock.restart();
    m_currentPicture = 0;
}

Animation::Animations Animation::getType() {
    return m_type;
}
