#include <SFML/Graphics.hpp>
#include "card.hpp"

MonsterCard::MonsterCard (int _atk = 0, int _hp = 0, int _mana = 0)
{
    atk = (char)_atk + 48;
    hp = (_hp + 48);
    mana = (_mana + 48);

    font.loadFromFile("Augusta.tff");
    image.loadFromFile("blackcolor.png");
    image.setSmooth(true);
    sprite.setTexture(image);

    atkNum.setFont(font);
    hpNum.setFont(font);
    manaNum.setFont(font);

    atkNum.setString(sf::String(atk);
    hpNum.setString((char)hp+48);
    manaNum.setString((char)mana+48);

    atkNum.setCharacterSize(30);
    hpNum.setCharacterSize(30);
    manaNum.setCharacterSize(30);

    atkNum.setFillColor(sf::Color::White);
    hpNum.setFillColor(sf::Color::Red);
    manaNum.setFillColor(sf::Color::Blue);

    atkNum.setPosition(sprite.getPosition().x + 10, sprite.getPosition().y + 260);
    hpNum.setPosition(sprite.getPosition().x + 160, sprite.getPosition().y + 260);
    manaNum.setPosition(sprite.getColor().x + 10, sprite.getColor().y + 10);

}

MonsterCard::~MonsterCard(){}

void draw ()
{
    window.draw(sprite);
    window.draw(atkNum);
    window.draw(hpNum);
    window.draw(manaNum);
}

void setTexture (char name[])
{
    image.loadFromFile(name);
    sprite.setTexture (texture);
}

void setPosition (sf:: Vector2f pos)
{
    sprite.setPosition(pos);
}
