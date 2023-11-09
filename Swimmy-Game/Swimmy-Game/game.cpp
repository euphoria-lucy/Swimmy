#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "player.h"

using namespace sf;

const int WIDTH = 1000;
const int HEIGHT = 700;

enum GameState {  // ���� ���¸� ��Ÿ���� ������
    StartScreen,  // ���� ���� ȭ��
    InfoScreen,   // ���� ���� ȭ��
    GameScreen    // ���� ���� ȭ��
};

int main() {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Swimmy");
    GameState gameState = StartScreen;

    // ���ӽ���ȭ�� �̹��� ����
    Texture startScreenTexture;
    if (!startScreenTexture.loadFromFile("startScreenImage.png")) {
        return 1;
    }
    Sprite startScreenSprite(startScreenTexture);

    // ��������ȭ�� �̹��� ����
    Texture gameScreenTexture;
    if (!gameScreenTexture.loadFromFile("gameScreenImage.png")) {
        return 1;
    }
    Sprite gameScreenSprite(gameScreenTexture);

    // ���Ӽ���ȭ�� �̹��� ����
    Texture infoScreenTexture;
    if (!infoScreenTexture.loadFromFile("infoScreenImage.png")) {
        return 1;
    }
    Sprite infoScreenSprite(infoScreenTexture);

    // Player �̹��� ����
    Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png")) {
        return 1;
    }
    Player player(playerTexture, 30, 30); // Player ��ü ����
    player.sprite.setScale(0.4f, 0.4f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) { // â�� ������ ����
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                // ���ӽ���ȭ�鿡�� �����̽��ٸ� ���� -> ��������ȭ������ �̵�
                if (event.key.code == Keyboard::Space && gameState == StartScreen) {
                    gameState = GameScreen;
                }
                // ���ӽ���ȭ�鿡�� AŰ�� ���� -> ���Ӽ���ȭ������ �̵�
                else if (event.key.code == Keyboard::A && gameState == StartScreen) {
                    gameState = InfoScreen;
                }
                // ���Ӽ���ȭ�鿡�� �����̽��ٸ� ���� -> ��������ȭ������ �̵�
                else if (event.key.code == Keyboard::Space && gameState == InfoScreen) {
                    gameState = GameScreen;
                }
            }
        }

        if (gameState == GameScreen) {
            player.update(Vector2u(WIDTH, HEIGHT));
        }

        window.clear();

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
            window.draw(player.sprite);
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);
        }

        window.display();
    }

    return 0;
}