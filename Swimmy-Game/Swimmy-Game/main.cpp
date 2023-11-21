#include <SFML/Graphics.hpp>
#include "player.h"
#include "fish.h"
#include "turtle.h"

using namespace sf;

const int WIDTH = 1000; // 화면의 가로 크기
const int HEIGHT = 700; // 화면의 세로 크기

enum GameState {  // 게임 상태를 나타내는 열거형
    StartScreen,  // 게임 시작 화면
    InfoScreen,   // 게임 설명 화면
    GameScreen,   // 게임 진행 화면
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

    // 게임시작화면 이미지 삽입
    Texture startScreenTexture;
    if (!startScreenTexture.loadFromFile("startScreenImage.png")) {
        return 1;
    }
    Sprite startScreenSprite(startScreenTexture);

    // 게임진행화면 이미지 삽입
    Texture gameScreenTexture;
    if (!gameScreenTexture.loadFromFile("gameScreenImage.png")) {
        return 1;
    }
    Sprite gameScreenSprite(gameScreenTexture);

    // 게임설명화면 이미지 삽입
    Texture infoScreenTexture;
    if (!infoScreenTexture.loadFromFile("infoScreenImage.png")) {
        return 1;
    }
    Sprite infoScreenSprite(infoScreenTexture);

    // 게임결과화면 이미지 삽입
    Texture resultScreenTexture;
    if (!resultScreenTexture.loadFromFile("resultScreenImage.png")) {
        return 1;
    }
    Sprite resultScreenSprite(resultScreenTexture);


    Player player(window);
    std::vector<Fish*> fishes;
    std::vector<Turtle*> turtles;

    Clock gameClock;

    // 물고기와 거북이 여러 개 생성
    for (int i = 0; i < 5; ++i) {
        fishes.push_back(new Fish(window));
        turtles.push_back(new Turtle(window));
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) { // 창을 닫으면 종료
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                // 게임시작화면에서 스페이스바를 누름 -> 게임진행화면으로 이동
                if (event.key.code == Keyboard::Space && gameState == StartScreen) {
                    gameState = GameScreen;
                }
                // 게임시작화면에서 A키를 누름 -> 게임설명화면으로 이동
                else if (event.key.code == Keyboard::A && gameState == StartScreen) {
                    gameState = InfoScreen;
                }
                // 게임설명화면에서 스페이스바를 누름 -> 게임진행화면으로 이동
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

            // 거북이와의 충돌 체크
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

            // 게임 시간이 다 되면 게임 종료
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
                return 1;  // 폰트 로딩 실패
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