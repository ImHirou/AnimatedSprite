#ifndef ANIMATIONHPP
#define ANIMATIONHPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class Animation {
public:
    enum Animations {
        RUN,
        ATTACK,
        IDLE,
        TOTAL_ANIMATIONS

    };

private:
    std::string m_path;
    const int m_frames;
    const float m_delay;
    const int m_xSize;
    const int m_ySize;
    const Animations m_type;
    sf::Clock m_clock;
    sf::Texture m_texture;
    int m_currentPicture;
public:
    Animation(std::string path="", Animations type=Animation::IDLE, int frames = 1, float delay = 0.1, int xSize=120, int ySize=42) :
        m_path(path), m_type(type), m_frames(frames), m_delay(delay), m_xSize(xSize), m_ySize(ySize), m_currentPicture(0) {
            m_texture.loadFromFile(m_path);
        }

    bool operator==(const Animation& other) const {
        return m_path == other.m_path && m_frames == other.m_frames &&
               m_delay == other.m_delay && m_xSize == other.m_xSize &&
               m_ySize == other.m_ySize;
    }

    void play(sf::RenderWindow &window, int x, int y, int pos);
    void restart();
    int getFrames();
    float getDelay();
    Animations getType();

};

#endif // ANIMATIONHPP
