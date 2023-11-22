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
    ResultScreen  // 게임 결과 화면
};

// 템플릿 사용하여 std::vector의 포인터 타입을 가진 요소 삭제, 벡터 비우는 함수 정의
// 동적으로 할당된 메모리를 관리하는 데 사용
template<typename T>
void clearVector(std::vector<T*>& vec) { // 포인터 타입을 가진 요소들을 담고 있는 벡터를 전달받음
    for (auto& elem : vec) { // 벡터의 각 요소에 대해 반복문 실행
        delete elem; // 각 요소가 가리키는 동적으로 할당된 메모리 해제
    }
    vec.clear(); // 벡터를 비워서 원소들이 삭제된 메모리를 가지지 않도록 함
}

int main() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Swimmy");
    GameState gameState = StartScreen;

    // 게임시작화면 이미지 삽입
    Texture startScreenTexture;
    // 이미지 파일을 로드하고, 로드에 실패하면 1을 반환
    if (!startScreenTexture.loadFromFile("startScreenImage.png")) {
        return 1;
    }
    Sprite startScreenSprite(startScreenTexture); // 로드된 텍스처를 이용하여 스프라이트 생성

    // 게임진행화면 이미지 삽입
    Texture gameScreenTexture;
    // 이미지 파일을 로드하고, 로드에 실패하면 1을 반환
    if (!gameScreenTexture.loadFromFile("gameScreenImage.png")) {
        return 1;
    }
    Sprite gameScreenSprite(gameScreenTexture); // 로드된 텍스처를 이용하여 스프라이트 생성

    // 게임설명화면 이미지 삽입
    Texture infoScreenTexture;
    // 이미지 파일을 로드하고, 로드에 실패하면 1을 반환
    if (!infoScreenTexture.loadFromFile("infoScreenImage.png")) {
        return 1;
    }
    Sprite infoScreenSprite(infoScreenTexture); // 로드된 텍스처를 이용하여 스프라이트 생성

    // 게임결화화면 이미지 삽입
    Texture resultScreenTexture;
    // 이미지 파일을 로드하고, 로드에 실패하면 1을 반환
    if (!resultScreenTexture.loadFromFile("resultScreenImage.png")) { 
        return 1;
    }
    Sprite resultScreenSprite(resultScreenTexture); // 로드된 텍스처를 이용하여 스프라이트 생성


    Player player(window); // 플레이어 객체 생성
    std::vector<Fish*> fishes; // 클래스의 포인터를 담는 벡터 생성
    std::vector<Turtle*> turtles; // 클래스의 포인터를 담는 벡터 생성

    Clock gameClock; // 시간 측정하고 관리

    // 물고기와 거북이 여러 개 생성
    for (int i = 0; i < 5; ++i) {
        fishes.push_back(new Fish(window));     // 5개의 객체 추가
        turtles.push_back(new Turtle(window));  // 5개의 객체 추가
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
                // 게임결과화면에서 R키를 누름 -> 게임진행화면으로 이동
                else if (event.key.code == Keyboard::R && gameState == ResultScreen) {
                    // 게임 상태 초기화
                    gameState = GameScreen;
                    player.resetScore();

                    // 게임 객체 초기화
                    for (auto& fish : fishes) {
                        fish->resetPosition();
                    }
                    for (auto& turtle : turtles) {
                        turtle->resetPosition();
                    }

                    // 게임 시간 초기화
                    gameClock.restart();
                }
            }
        }

        if (gameState == GameScreen) {
            player.move(); // 플레이어 객체 이동 처리 함수

            // 물고기 객체들에 대한 이동 및 충돌 체크
            for (auto& fish : fishes) { // 물고기 객체들에 대해서 이동 처리
                fish->move(); // 물고기 객체 이동, move() 함수 호출
                if (player.getGlobalBounds().intersects(fish->getGlobalBounds())) { // 두 객체 간의 충돌 확인 -> 플레이어의 바운딩 박스와 물고기 객체의 바운딩 박스가 서로 교체하는지 확인
                    player.increaseScore(); // 플레이어 점수 증가
                    fish->resetPosition(); // 충돌이 발생한 물고기 재배치
                }
            }

            // 거북이와의 충돌 체크
            for (auto& turtle : turtles) {
                turtle->move(); // 거북이 객체 이동, move() 함수 호출
                if (player.getGlobalBounds().intersects(turtle->getGlobalBounds())) { // 두 객체 간의 충돌 확인 -> 플레이어의 바운딩 박스와 거북이 객체의 바운딩 박스가 서로 교체하는지 확인
                    player.decreaseScore(); // 플레이어 점수 감소
                    turtle->resetPosition(); // 충돌이 발생한 거북이 재배치
                }
            }
        }

        window.clear(); // 매 프레임마다 창을 지우고 새로운 프레임을 그리기 전에 호출되는 함수

        if (gameState == StartScreen) {
            window.draw(startScreenSprite);
        }
        else if (gameState == GameScreen) {
            window.draw(gameScreenSprite);
            player.draw(); // 플레이어 그림

            // 물고기 그림
            // auto& fish : 벡터 fishes에 있는 물고기 객체에 대한 참조 나타냄
            for (auto& fish : fishes) {
                fish->draw();
            }

            // 거북이 그림
            // auto& turtle : 벡터 turtles에 있는 물고기 객체에 대한 참조 나타냄
            for (auto& turtle : turtles) {
                turtle->draw();
            }

            // 게임 시간이 다 되면 게임 종료
            if (gameClock.getElapsedTime().asSeconds() >= 60) {
                gameState = ResultScreen; // 60초 지나면 결과화면으로 넘어가게
            }

            Font font;
            if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
                return 1;  // 폰트 로딩 실패
            }

            Text scoreText;
            scoreText.setFont(font); // 폰트 설정
            scoreText.setCharacterSize(30); // 텍스트 문자 크기 30으로 설정
            scoreText.setFillColor(Color::Black);   // 텍스트의 색상 컴은색 설정
            scoreText.setPosition(10, 10);  // 텍스트 위치 설정

            scoreText.setString("Score : " + std::to_string(player.getScore())); // 플레이어 점수를 문자열로 변환하고 결합하여 전체 문자열 만듬
            window.draw(scoreText); // 화면에 표시
        }
        else if (gameState == InfoScreen) {
            window.draw(infoScreenSprite);  // 게임설명화면 그림
        }
        else if (gameState == ResultScreen) {
            window.draw(resultScreenSprite);    // 결과화면 그림

            Font font;
            if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
                return 1;  // 폰트 로딩 실패
            }

            Text scoreText;
            scoreText.setFont(font); // 폰트 설정
            scoreText.setCharacterSize(100); // 텍스트 문자 크기 100으로 설정
            scoreText.setFillColor(Color::Blue); // 텍스트 색상 파랑색으로 설정
            scoreText.setPosition(WIDTH / 2 - 50, HEIGHT / 3); // 텍스트 위치 설정

            scoreText.setString(std::to_string(player.getScore())); // 플레이어 점수를 문자열로 변환하고 결합하여 전체 문자열 만듬
            window.draw(scoreText); // 화면에 표시
        }

        window.display(); // 그려진 모든 그래픽을 실제로 보여주는 역할
    }

    return 0;
}