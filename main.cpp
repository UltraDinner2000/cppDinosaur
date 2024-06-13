#include <SFML/Graphics.hpp>



int main() {

    enum TexturesDino {
        FIRST_TEXTURE,
        SECOND_TEXTURE
    };

    int curTextureDino = FIRST_TEXTURE;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "window");
    
    sf::Texture dinoTexture;
    dinoTexture.loadFromFile("materials/dinosaur.png");

    sf::Texture dinoTexture1;
    dinoTexture1.loadFromFile("materials/dinoTexture.png");

    sf::Texture kaktuzTexture;
    kaktuzTexture.loadFromFile("materials/koktuz.png");

    sf::Texture cloudTexture;
    cloudTexture.loadFromFile("materials/cloud.png");

    sf::Texture groundTexture;
    groundTexture.loadFromFile("materials/ground.png");

    sf::Texture nloTexture;
    nloTexture.loadFromFile("materials/nlo.png");

    sf::Texture mountainsTexture;
    mountainsTexture.loadFromFile("materials/mountains.png");

    sf::Font font;
    font.loadFromFile("materials/Keleti-Regular.ttf");

    sf::Text scoreText("", font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color(0, 0, 0));

    int score = 0;


    sf::Sprite dinoSprite1;
    dinoSprite1.setTexture(dinoTexture);
    dinoSprite1.setPosition(200, 470);
    dinoSprite1.setScale(1.2f, 1.2f);

    sf::Sprite kaktuzSprite1;
    kaktuzSprite1.setTexture(kaktuzTexture);
    kaktuzSprite1.setTextureRect(sf::IntRect(0, 0, 50, 100));
    kaktuzSprite1.setPosition(1366, 500);
    kaktuzSprite1.setScale(0.9f, 0.9f);

    sf::Sprite kaktuzSprite2;
    kaktuzSprite2.setTexture(kaktuzTexture);
    kaktuzSprite2.setTextureRect(sf::IntRect(227, 0, 80, 100));
    kaktuzSprite2.setPosition(1366, 500);

    sf::Sprite cloudSprite1;
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setTextureRect(sf::IntRect(0, 0, 48, 32));
    cloudSprite1.setPosition(1366, 200);
    cloudSprite1.setScale(2.0f, 2.0f);

    sf::Sprite cloudSprite2;
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setTextureRect(sf::IntRect(99, 0, 96, 32));
    cloudSprite2.setPosition(1366, 100);
    cloudSprite2.setScale(2.0f, 2.0f);

    sf::Sprite mountainsSprite;
    mountainsSprite.setTexture(mountainsTexture);
    mountainsSprite.setPosition(1366, 420);
    mountainsSprite.setScale(2.0f, 2.0f);

    sf::Sprite nloSprite;
    nloSprite.setTexture(nloTexture);
    nloSprite.setPosition(1366, 220);
    nloSprite.setScale(2.0f, 2.0f);

    sf::Sprite groundSprite;
    groundSprite.setTexture(groundTexture);
    groundSprite.setPosition(0, 500);

    sf::Sprite groundSprite2;
    groundSprite2.setTexture(groundTexture);
    groundSprite2.setPosition(1366, 500);

    sf::RectangleShape kaktuzRestart;
    kaktuzRestart.setSize(sf::Vector2f(96, 768));
    kaktuzRestart.setFillColor(sf::Color(255, 255, 255));
    kaktuzRestart.setPosition(-100, 0);

    sf::RectangleShape groundRestart;
    groundRestart.setSize(sf::Vector2f(96, 768));
    groundRestart.setFillColor(sf::Color(255, 255, 255));
    groundRestart.setPosition(-1450, 0);

    sf::RectangleShape bg;
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
    bool isJumping = false;
    bool isMaxSpeed = false;

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
            if (score == 200) {
                nloSpeed = -15.0f;
            }
            if (score == 50) {
                cloudSpeed2 = -6.0f;
            }
            if (score == 20) {
                cloudSpeed = -5.0f;
            }
            if (score >= 200) {
                speed = -10.0f;
                speed2 = -10.0f;
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
            nloSprite.setPosition(2000, 220);
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

        if (isJumping) {
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