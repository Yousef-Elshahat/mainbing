#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
using namespace std;

class Button
{
private:
	sf::Text m_text;
	sf::RectangleShape m_shape;
	bool m_pressed;
public:
	Button(const std::string& text, const sf::Font& font,
		unsigned int size, const sf::Color& color,
		const sf::Vector2f& position);

	string getText() const;
	void setText(const std::string& text);
	sf::RectangleShape getShape() const;
	void setTextFillcolor(const sf::Color& color);
	void setShapeFillColor(const sf::Color& color);
	void setShape(const sf::RectangleShape& shape);
	void draw(sf::RenderTarget& target);
	bool isMouseOver(const sf::RenderWindow& window);
	bool isPressed();
	void setPressed(bool pressed);
};

