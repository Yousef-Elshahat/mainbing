#include "button.h"


Button::Button(const std::string& text, const sf::Font& font, unsigned int size, const sf::Color& color, const sf::Vector2f& position)
{
    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);
    m_text.setPosition(position);

    m_shape.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10.f, m_text.getGlobalBounds().height + 15.f));
    m_shape.setFillColor(sf::Color::Transparent);
    m_shape.setPosition(position.x - 5.f, position.y - 5.f);

    m_pressed = true;

    m_text.setOrigin(m_text.getGlobalBounds().width / 2 + m_text.getLocalBounds().left, m_text.getGlobalBounds().height / 2 + m_text.getLocalBounds().top);

    m_text.setPosition(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + m_shape.getSize().y / 2);
}

string Button::getText() const
{
    return m_text.getString();
}

void Button::setText(const std::string& text)
{
    m_text.setString(text);
}

sf::RectangleShape Button::getShape() const
{
    return m_shape;
}

void Button::setTextFillcolor(const sf::Color& color)
{
    m_text.setFillColor(color);
}

void Button::setShapeFillColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
    m_shape.setOutlineColor(color);
}

void Button::setShape(const sf::RectangleShape& shape)
{
    m_shape = shape;
}

void Button::draw(sf::RenderTarget& target)
{
    if (m_pressed) {
        target.draw(m_shape);
        target.draw(m_text);
    }
}

bool Button::isMouseOver(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return m_shape.getGlobalBounds().contains(static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y));
}

bool Button::isPressed()
{
    return m_pressed;
}

void Button::setPressed(bool pressed)
{
    m_pressed = pressed;
}
