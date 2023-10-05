#include <SFML/Graphics.hpp>

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

    Texture startScreenTexture;
    if (!startScreenTexture.loadFromFile("startScreenImage.png")) {
        // �̹����� �ε��ϴ� �� ������ ��� ���� ó���� �߰��ϼ���.
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
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);
        }

        window.display();
    }

    return 0;
}