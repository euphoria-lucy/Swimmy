#include <SFML/Graphics.hpp>
#include "gameObject.h"

using namespace sf;

const int WIDTH = 1000;
const int HEIGHT = 700;

enum GameState {  // 게임 상태를 나타내는 열거형
    StartScreen,  // 게임 시작 화면
    InfoScreen,   // 게임 설명 화면
    GameScreen    // 게임 진행 화면
};

int main() {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Swimmy");
    GameState gameState = StartScreen;

    Texture startScreenTexture;
    if (!startScreenTexture.loadFromFile("startScreenImage.png")) {
        return 1;
    }
    Sprite startScreenSprite(startScreenTexture);

    Texture gameScreenTexture;
    if (!gameScreenTexture.loadFromFile("gameScreenImage.png")) {
        return 1;
    }
    Sprite gameScreenSprite(gameScreenTexture);

    Texture infoScreenTexture;
    if (!infoScreenTexture.loadFromFile("infoScreenImage.png")) {
        return 1;
    }
    Sprite infoScreenSprite(infoScreenTexture);

    /* Texture playerTexture;  // player.png 이미지를 로드하기 위한 텍스처
    if (!playerTexture.loadFromFile("player.png")) {
        return 1;
    }
    GameObject player(playerTexture, 100, 100); */

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space && gameState == StartScreen) {
                    gameState = GameScreen;
                }
                else if (event.key.code == Keyboard::A && gameState == StartScreen) {
                    gameState = InfoScreen;
                }
                else if (event.key.code == Keyboard::Space && gameState == InfoScreen) {
                    gameState = GameScreen;
                }
            }
        }

        window.clear();

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
            // window.draw(player.sprite);
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);
        }

        window.display();
    }

    return 0;
}