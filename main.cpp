#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


sf::Texture dinoTexture;
sf::Texture dinoTexture1;
sf::Texture kaktuzTexture;
sf::Texture cloudTexture;
sf::Texture groundTexture;
sf::Texture nloTexture;
sf::Texture mountainsTexture;   
sf::Texture sunTexture;   

sf::Font font;

sf::Sprite dinoSprite1;
sf::Sprite kaktuzSprite1;
sf::Sprite kaktuzSprite2;
sf::Sprite cloudSprite1;
sf::Sprite cloudSprite2;
sf::Sprite mountainsSprite;
sf::Sprite nloSprite;
sf::Sprite groundSprite;
sf::Sprite groundSprite2;
sf::Sprite sunSprite;

sf::RectangleShape kaktuzRestart;
sf::RectangleShape groundRestart;
sf::RectangleShape ground2;
sf::RectangleShape bg;

sf::SoundBuffer buffer0;
sf::SoundBuffer buffer1;
sf::Sound sound0;
sf::Sound sound1;

int main() {

    enum TexturesDino {
        FIRST_TEXTURE,
        SECOND_TEXTURE
    };

    int curTextureDino = FIRST_TEXTURE;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Dinosaur");

    dinoTexture.loadFromFile("materials/dinosaur.png");

    dinoTexture1.loadFromFile("materials/dinoTexture.png");

    kaktuzTexture.loadFromFile("materials/koktuz.png");

    cloudTexture.loadFromFile("materials/cloud.png");

    groundTexture.loadFromFile("materials/ground.png");

    nloTexture.loadFromFile("materials/nlo.png");

    mountainsTexture.loadFromFile("materials/mountains.png");

    sunTexture.loadFromFile("materials/sun.png");

    font.loadFromFile("materials/Keleti-Regular.ttf");

    sf::Text scoreText("", font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color(0, 0, 0));

    int score = 0;



    dinoSprite1.setTexture(dinoTexture);
    dinoSprite1.setPosition(200, 470);
    dinoSprite1.setScale(1.2f, 1.2f);


    kaktuzSprite1.setTexture(kaktuzTexture);
    kaktuzSprite1.setTextureRect(sf::IntRect(0, 0, 50, 100));
    kaktuzSprite1.setPosition(1366, 500);
    kaktuzSprite1.setScale(0.9f, 0.9f);

    kaktuzSprite2.setTexture(kaktuzTexture);
    kaktuzSprite2.setTextureRect(sf::IntRect(227, 0, 80, 100));
    kaktuzSprite2.setPosition(1366, 500);

    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setTextureRect(sf::IntRect(0, 0, 48, 32));
    cloudSprite1.setPosition(1366, 200);
    cloudSprite1.setScale(2.0f, 2.0f);

    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setTextureRect(sf::IntRect(99, 0, 96, 32));
    cloudSprite2.setPosition(1366, 100);
    cloudSprite2.setScale(2.0f, 2.0f);

    mountainsSprite.setTexture(mountainsTexture);
    mountainsSprite.setPosition(1366, 420);
    mountainsSprite.setScale(2.0f, 2.0f);

    nloSprite.setTexture(nloTexture);
    nloSprite.setPosition(1366, 200);
    nloSprite.setScale(2.0f, 2.0f);

    groundSprite.setTexture(groundTexture);
    groundSprite.setPosition(0, 500);

    groundSprite2.setTexture(groundTexture);
    groundSprite2.setPosition(1366, 500);

    sunSprite.setTexture(sunTexture);
    sunSprite.setPosition(1366, 300);
    sunSprite.setScale(6.0f, 6.0f);


    kaktuzRestart.setSize(sf::Vector2f(96, 768));
    kaktuzRestart.setFillColor(sf::Color(255, 255, 255));
    kaktuzRestart.setPosition(-100, 0);

    groundRestart.setSize(sf::Vector2f(96, 768));
    groundRestart.setFillColor(sf::Color(255, 255, 255));
    groundRestart.setPosition(-1450, 0);

    ground2.setSize(sf::Vector2f(1366, 500));
    ground2.setFillColor(sf::Color(255, 255, 255));
    ground2.setPosition(0, 580);

    bg.setSize(sf::Vector2f(1366, 768));
    bg.setFillColor(sf::Color(255, 255, 255));

    window.setFramerateLimit(60);

    int UltraTime = 0;

    float speed = -8.0f;
    float speed2 = 0.0f;
    float cloudSpeed = 0.0f;
    float cloudSpeed2 = 0.0f;
    float nloSpeed = 0.0f;
    float jumpSpeed = 0.0f;
    float mountainsSpeed = 0.0f;
    float groundSpeed = -2.0f;
    float sunSpeed = 0.0f;
    bool isJumping = false;
    bool isMaxSpeed = false;

    buffer0.loadFromFile("materials/jg-032316-sfx-8-bit-pong-sound.mp3");
    buffer1.loadFromFile("materials/lox.mp3");

    sound0.setBuffer(buffer0);
    sound1.setBuffer(buffer1);

    sound1.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::W) {
                if (!isJumping) {
                    isJumping = true;
                    jumpSpeed = -10.5f;
                }
            }


            if (event.key.code == sf::Keyboard::Equal) {
                score += 10;
            }
            if (event.key.code == sf::Keyboard::RControl) {
                jumpSpeed -= 20;
            }

            if (score == 120) {
                speed2 = -9.2f;
            }
            if (score == 150) {
               mountainsSpeed = -3.0f;
            }
            if (score == 170) {
                sunSpeed = -1.0f;
            }
            if (score == 200) {
                nloSpeed = -17.0f;
            }
            if (score == 50) {
                cloudSpeed2 = -6.0f;
            }
            if (score == 20) {
                cloudSpeed = -5.0f;
            }
            if (score >= 170) {
                speed = -9.7f;
                speed2 = -9.7f;
            }
 
        }

        if (dinoSprite1.getGlobalBounds().intersects(kaktuzSprite1.getGlobalBounds())) {
            window.close();
        }
        if (dinoSprite1.getGlobalBounds().intersects(kaktuzSprite2.getGlobalBounds())) {
            window.close();
        }
        if (dinoSprite1.getGlobalBounds().intersects(nloSprite.getGlobalBounds())) {
            window.close();
        }
        if (kaktuzSprite1.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            kaktuzSprite1.setPosition(1366, 500);
            sound0.play();
            speed -= 0.1;
            score += 10;
        }
        if (kaktuzSprite2.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            kaktuzSprite2.setPosition(1366, 500);
            speed2 -= 0.1;
        }
        if (cloudSprite1.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            cloudSprite1.setPosition(1366, 200);
            cloudSpeed -= 0.1;
        }
        if (cloudSprite2.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            cloudSprite2.setPosition(1366, 100);
            cloudSpeed2 -= 0.1;
        }
        if (nloSprite.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            nloSprite.setPosition(3500, 220);
            nloSpeed -= 1;
        }
        if (mountainsSprite.getGlobalBounds().intersects(kaktuzRestart.getGlobalBounds())) {
            mountainsSprite.setPosition(1700, 420);
            mountainsSpeed -= 0.1;
        }
        if (groundSprite.getGlobalBounds().intersects(groundRestart.getGlobalBounds())) {
            groundSprite.setPosition(1366, 500);
        }
        if (groundSprite2.getGlobalBounds().intersects(groundRestart.getGlobalBounds())) {
            groundSprite2.setPosition(1366, 500);
        }

        UltraTime++;
        if (UltraTime == 20) {
            UltraTime = 0;
            if (curTextureDino == FIRST_TEXTURE) {
                curTextureDino = SECOND_TEXTURE;
            }
            else if (curTextureDino == SECOND_TEXTURE) {
                curTextureDino = FIRST_TEXTURE;
            }
        }

        if (curTextureDino == FIRST_TEXTURE) {
            dinoSprite1.setTexture(dinoTexture);
        }
        else if (curTextureDino == SECOND_TEXTURE) {
            dinoSprite1.setTexture(dinoTexture1);
        }

        kaktuzSprite1.move(sf::Vector2f(speed, 0));
        kaktuzSprite2.move(sf::Vector2f(speed2, 0));
        cloudSprite1.move(sf::Vector2f(cloudSpeed, 0));
        cloudSprite2.move(sf::Vector2f(cloudSpeed2, 0));
        nloSprite.move(sf::Vector2f(nloSpeed, 0));
        mountainsSprite.move(sf::Vector2f(mountainsSpeed, 0));
        groundSprite.move(sf::Vector2f(groundSpeed, 0));
        groundSprite2.move(sf::Vector2f(groundSpeed, 0));
        sunSprite.move(sf::Vector2f(sunSpeed, 0));

        if (isJumping) {
            dinoSprite1.setTexture(dinoTexture1);
            dinoSprite1.move(0, jumpSpeed);
            jumpSpeed += 0.3f;

            if (dinoSprite1.getPosition().y >= 480) {
                dinoSprite1.setPosition(dinoSprite1.getPosition().x, 480);
                isJumping = false;
            }
        }

        scoreText.setString("Score: " + std::to_string(score));


        window.clear();
        window.draw(bg);
        window.draw(sunSprite);
        window.draw(ground2);
        window.draw(mountainsSprite);
        window.draw(groundSprite);
        window.draw(groundSprite2);
        window.draw(dinoSprite1);
        window.draw(kaktuzSprite1);
        window.draw(kaktuzSprite2);
        window.draw(kaktuzRestart);
        window.draw(cloudSprite1);
        window.draw(cloudSprite2);
        window.draw(nloSprite);
        window.draw(scoreText);
        window.display();
    }
}