#include <SFML/Graphics.hpp>
#include "player.h"
#include "fish.h"
#include "turtle.h"

using namespace sf;

const int WIDTH = 1000; // ȭ���� ���� ũ��
const int HEIGHT = 700; // ȭ���� ���� ũ��

enum GameState {  // ���� ���¸� ��Ÿ���� ������
    StartScreen,  // ���� ���� ȭ��
    InfoScreen,   // ���� ���� ȭ��
    GameScreen,   // ���� ���� ȭ��
    ResultScreen
};

template<typename T>
void clearVector(std::vector<T*>& vec) {
    for (auto& elem : vec) {
        delete elem;
    }
    vec.clear();
}

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

    // ���Ӱ��ȭ�� �̹��� ����
    Texture resultScreenTexture;
    if (!resultScreenTexture.loadFromFile("resultScreenImage.png")) {
        return 1;
    }
    Sprite resultScreenSprite(resultScreenTexture);


    Player player(window);
    std::vector<Fish*> fishes;
    std::vector<Turtle*> turtles;

    Clock gameClock;

    // ������ �ź��� ���� �� ����
    for (int i = 0; i < 5; ++i) {
        fishes.push_back(new Fish(window));
        turtles.push_back(new Turtle(window));
    }

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
            player.move();

            for (auto& fish : fishes) {
                fish->move();
                if (player.getGlobalBounds().intersects(fish->getGlobalBounds())) {
                    player.increaseScore();
                    fish->resetPosition();
                }
            }

            // �ź��̿��� �浹 üũ
            for (auto& turtle : turtles) {
                turtle->move();
                if (player.getGlobalBounds().intersects(turtle->getGlobalBounds())) {
                    player.decreaseScore();
                    turtle->resetPosition();
                }
            }
        }

        window.clear();

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
            player.draw();

            for (auto& fish : fishes) {
                fish->draw();
            }

            for (auto& turtle : turtles) {
                turtle->draw();
            }

            // ���� �ð��� �� �Ǹ� ���� ����
            if (gameClock.getElapsedTime().asSeconds() >= 60) {
                gameState = ResultScreen;
            }
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);
        }
        else if (gameState == ResultScreen) {
            window.draw(resultScreenSprite);

            Font font;
            if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
                return 1;  // ��Ʈ �ε� ����
            }

            Text scoreText;
            scoreText.setFont(font);
            scoreText.setCharacterSize(100);
            scoreText.setFillColor(Color::Blue);
            scoreText.setPosition(WIDTH / 2 - 50, HEIGHT / 3);

            scoreText.setString(std::to_string(player.getScore()));
            window.draw(scoreText);
        }

        window.display();
    }

    return 0;
}