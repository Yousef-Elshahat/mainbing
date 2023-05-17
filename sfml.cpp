#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "button.h"

using namespace std;

string getCurrentTime();
void displayText(sf::RenderWindow& window, sf::Font& font, const string& str
    , const int char_size, const int ch_Y, const int ch_X);
void displayLoading(sf::RenderWindow& window, const std::string& fileName, float scaleX, float scaleY);

int main()
{
    bool playpressed = false;
    bool diffcult_level = false;
    
    string currentTime = getCurrentTime();
    sf::RenderWindow window(sf::VideoMode(800, 600), "wonder world");

    //define the type font and background
    sf::Texture backgroundTexture;
    sf::Font font;

    //it identify any event happen like pressing a button
    sf::Event event;

    //set the font and the background image
    font.loadFromFile("arial.ttf");
    bool enterPressed = false;
    backgroundTexture.loadFromFile("background.jfif");

    //define and object called backgounrd as a prepare to draw it
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // getting the size of the image and merge it to the window
    sf::Texture loadingTexture;
    loadingTexture.loadFromFile("loading.jfif");
    sf::Vector2u imageSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / imageSize.x;
    float scaleY = static_cast<float>(windowSize.y) / imageSize.y;
    //
    sf::Vector2u imageSize1 = loadingTexture.getSize();
    float scaleX1 = static_cast<float>(windowSize.x) / imageSize1.x;
    float scaleY1 = static_cast<float>(windowSize.y) / imageSize1.y;
    //menu of the buttons
    Button playButton("Play", font, 40, sf::Color::Cyan, sf::Vector2f(100,100));
    Button aboutButton("about", font, 40, sf::Color::Cyan, sf::Vector2f(100, 200));
    Button creditsButton("credits", font, 40, sf::Color::Cyan, sf::Vector2f(100, 300));
    Button exitButton("exit", font, 40, sf::Color::Cyan, sf::Vector2f(100, 400));
    Button hardButton("hard", font, 40, sf::Color::Cyan, sf::Vector2f(100, 200));
    Button easyButton("easy", font, 40, sf::Color::Cyan, sf::Vector2f(100, 100));
    Button forest("forest", font, 40, sf::Color::Cyan, sf::Vector2f(100, 100));
    backgroundSprite.setScale(scaleX, scaleY);

    // a while loop to keep the window open tell we close the app
    while (window.isOpen())
    {
        //if for determine if the mouse in the play button
        if (playButton.isMouseOver(window)) { 
            //set the color to be white once the mouse is over
            playButton.setShapeFillColor(sf::Color::White);
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased||
                    event.key.code == sf::Keyboard::Enter) {
                    //to change the play button and the about button
                    playButton.setPressed(false);
                    aboutButton.setPressed(false);
                    exitButton.setPressed(false);
                    creditsButton.setPressed(false);
                    playpressed = true;
                }
            }


        }
        else {playButton.setShapeFillColor(sf::Color::Transparent);
        }
        if (easyButton.isMouseOver(window)&&playpressed) {
            easyButton.setShapeFillColor(sf::Color::White);
            
        }
        else {
            easyButton.setShapeFillColor(sf::Color::Transparent);
        }
        if (hardButton.isMouseOver(window)) {
            hardButton.setShapeFillColor(sf::Color::White);
        }
        else {
            hardButton.setShapeFillColor(sf::Color::Transparent);
        }
        if (aboutButton.isMouseOver(window)) {
            aboutButton.setShapeFillColor(sf::Color::White);
        }
        else {
            aboutButton.setShapeFillColor(sf::Color::Transparent);
        }
        if (creditsButton.isMouseOver(window)) {
            creditsButton.setShapeFillColor(sf::Color::White);
        }
        else {
            creditsButton.setShapeFillColor(sf::Color::Transparent);
        }
        if (exitButton.isMouseOver(window)) {
            exitButton.setShapeFillColor(sf::Color::White);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
            }
        }
        else {
            exitButton.setShapeFillColor(sf::Color::Transparent);
        }
        
        while (window.pollEvent(event))
        {
            //an if to close the window if I press esc
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            //an if to go to the main window once I click enter
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    enterPressed = true;
                }
            }
            
        }


        if (event.type == sf::Event::KeyPressed ||
            event.key.code == sf::Keyboard::BackSpace) {
            playpressed = false;
            playButton.setPressed(!playpressed);
            aboutButton.setPressed(!playpressed);
            exitButton.setPressed(!playpressed);
            creditsButton.setPressed(!playpressed);
        }

        window.clear(sf::Color::Black);

        if (enterPressed)
        {
            window.draw(backgroundSprite);
            playButton.draw(window);
            displayText(window, font,currentTime,35,10, 650);
            aboutButton.draw(window);
            creditsButton.draw(window);
            exitButton.draw(window);
            forest.setPressed(diffcult_level);
            hardButton.setPressed(playpressed);
            easyButton.setPressed(playpressed);
            forest.draw(window);
            easyButton.draw(window);
            hardButton.draw(window);

        }
        else
        {
            displayLoading(window, "loading.jfif", scaleX1, scaleY1);
            displayText(window, font, "wonder world", 75, 180, 100);
            displayText(window, font, "press Enter", 50, 270, 220);
        }
        //displaying the window after all of that
        window.display();
    }


    return 0;
}
string getCurrentTime()
{
    // now is a variable that store time
    time_t now = time(0);
    tm local;
    // stringstream is a type of data that enaple you to edit more in the data
    stringstream ss;
    //this function is converting now to the local time and assign it to local
    localtime_s(&local, &now);
    // here we assign the time to ss as a stringstream
    ss << local.tm_hour << ":" << local.tm_min ;
    return ss.str();
}
//this function is to display any text you give it the needed information and leave the rest to it
void displayText(sf::RenderWindow& window, sf::Font& font, const string& str
    , const int char_size, const int ch_X, const int ch_Y)
{
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(char_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(ch_X, ch_Y);
    text.setString(str);
    window.draw(text);
}
void displayLoading(sf::RenderWindow& window,
    const std::string& fileName,float scaleX,float scaleY)
{

    sf::Texture loadingTexture;
    loadingTexture.loadFromFile(fileName);
    sf::Sprite loadingSprite;
    loadingSprite.setTexture(loadingTexture);
    loadingSprite.setScale(scaleX, scaleY);
    window.draw(loadingSprite);
}
