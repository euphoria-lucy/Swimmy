#include <SFML/Graphics.hpp>

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
        // 이미지를 로드하는 데 실패한 경우 예외 처리를 추가하세요.
        return 1;
    }
    Sprite startScreenSprite(startScreenTexture);

    Texture gameScreenTexture;
    if (!gameScreenTexture.loadFromFile("gameScreenImage.png")) {
        // 게임 진행 화면 이미지를 로드하는 데 실패한 경우 예외 처리를 추가하세요.
        return 1;
    }
    Sprite gameScreenSprite(gameScreenTexture);

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
            }
        }

        window.clear();

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
        }

        window.display();
    }
}