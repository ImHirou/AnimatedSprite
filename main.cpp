#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Animation.hpp"
#include "Player.hpp"

using namespace sf;



int main() {

    RenderWindow window(VideoMode(800, 800), "Animation");

    Player player(200, 200);
    Clock clock;

    while(window.isOpen()) {

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed) {
                if(event.key.code == Keyboard::D) {
                  player.changeAnimation(player.getAnimations()[Animation::RUN]);
                  player.changePos(1);
                  player.move(3, 0);
                  clock.restart();
                }
                if(event.key.code == Keyboard::A) {
                  player.changeAnimation(player.getAnimations()[Animation::RUN]);
                  player.changePos(-1);
                  player.move(-3, 0);
                  clock.restart();
                }
            }
            else if(event.type == Event::KeyReleased) {
                if(event.key.code == Keyboard::D || event.key.code == Keyboard::A) {
                    player.changeAnimation(player.getAnimations()[Animation::IDLE]);
                    clock.restart();
                }
            }
            if(event.type == Event::MouseButtonPressed) {
                if(event.key.code == Mouse::Left) {
                    player.changeAnimation(player.getAnimations()[Animation::ATTACK]);
                    clock.restart();
                }
            }

        }
        Animation currentAnimation = player.getAnimations()[player.getCurrentAnimation()];
        if (clock.getElapsedTime().asSeconds() >= currentAnimation.getDelay()*currentAnimation.getFrames()){
                player.changeAnimation(player.getAnimations()[Animation::IDLE]);
                clock.restart();
            }

        window.clear(Color::Black);
        player.eachFrame(window);
        window.display();

    }

}
