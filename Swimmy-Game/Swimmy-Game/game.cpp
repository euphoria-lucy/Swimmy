#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "player.h"
#include "fish.h"
#include <ctime>

using namespace sf;

const int WIDTH = 1000; // ȭ���� ���� ũ��
const int HEIGHT = 700; // ȭ���� ���� ũ��

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
    player.sprite.setScale(0.3f, 0.3f);


    Texture fishTexture;
    if (!fishTexture.loadFromFile("fish.png")) {
        return 1;
    }
    Fish fish(fishTexture, 600, HEIGHT);
    fish.sprite.setScale(0.4f, 0.4f);

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

            // �÷��̾� ��ü ������Ʈ
            player.update(Vector2u(WIDTH, HEIGHT));

            // �÷��̾�� ������� �浹 Ȯ��
            if (fish.checkCollisionWithPlayer(player)) {
                // �浹 �� �÷��̾��� ������ ������Ű�� �ڵ� �߰�
                err() << "Player scored!\n";
            }

            // ����� ������Ʈ
            fish.update();
        }

        window.clear();

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
            window.draw(player.sprite);
            window.draw(fish.sprite);
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);
        }

        window.display();
    }

    return 0;
}