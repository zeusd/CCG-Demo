#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MonsterCard.hpp"

MonsterCard::MonsterCard()
{
    atk = 0;
    hp = 0;
    mana = 0;
    alive = 1;

    font.loadFromFile("Augusta.ttf");
    image.loadFromFile("blackcolor.png");
    image.setSmooth(true);
    sprite.setTexture(image);

    atkNum.setFont(font);
    hpNum.setFont(font);
    manaNum.setFont(font);

    std::stringstream atkText, hpText, manaText;
    atkText << atk;
    hpText << hp;
    manaText << mana;

    atkNum.setString(atkText.str());
    hpNum.setString(hpText.str());
    manaNum.setString(manaText.str());

    atkNum.setCharacterSize(32);
    hpNum.setCharacterSize(32);
    manaNum.setCharacterSize(32);

    atkNum.setFillColor(sf::Color::White);
    hpNum.setFillColor(sf::Color::Red);
    manaNum.setFillColor(sf::Color::Blue);

    atkNum.setOrigin(atkNum.getGlobalBounds().width/2, atkNum.getGlobalBounds().height);
    hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    manaNum.setOrigin(manaNum.getGlobalBounds().width/2, manaNum.getGlobalBounds().height);

    atkNum.setPosition(sprite.getPosition().x + 25, sprite.getPosition().y + 215);
    hpNum.setPosition(sprite.getPosition().x + 155, sprite.getPosition().y + 215);
    manaNum.setPosition(sprite.getPosition().x + 25, sprite.getPosition().y + 25);
}

void MonsterCard::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
    atkNum.setPosition(x + 25, y + 215);
    hpNum.setPosition(x + 155, y + 215);
    manaNum.setPosition(x + 25, y + 25);
}

void MonsterCard::setPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec);
    atkNum.setPosition(sprite.getPosition().x + 25, sprite.getPosition().y + 215);
    hpNum.setPosition(sprite.getPosition().x + 155, sprite.getPosition().y + 215);
    manaNum.setPosition(sprite.getPosition().x + 25, sprite.getPosition().y + 25);
}

sf::Vector2f MonsterCard::getPosition()
{
    return sprite.getPosition();
}

void MonsterCard::setTexture(sf::String name)
{
    image.loadFromFile(name);
    sprite.setTexture(image);
}

bool MonsterCard::contains(sf::Vector2f vec)
{
    return sprite.getGlobalBounds().contains(vec);
}

void MonsterCard::setStats(int _atk, int _hp, int _mana)
{
    atk = _atk;
    hp = _hp;
    mana = _mana;

    std::stringstream atkText, hpText, manaText;
    atkText << atk;
    hpText << hp;
    manaText << mana;

    atkNum.setString(atkText.str());
    hpNum.setString(hpText.str());
    manaNum.setString(manaText.str());

    atkNum.setOrigin(atkNum.getGlobalBounds().width/2, atkNum.getGlobalBounds().height);
    hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    manaNum.setOrigin(manaNum.getGlobalBounds().width/2, manaNum.getGlobalBounds().height);
}

int MonsterCard::getAtk()
{
    return atk;
}

void MonsterCard::damage(int dmg)
{
    hp-=dmg;

    if(hp<1)
    {
        alive=0;
    }

    else
    {
        std::stringstream hpText;
        hpText<<hp;
        hpNum.setString(hpText.str());
        hpNum.setOrigin(hpNum.getGlobalBounds().width/2, hpNum.getGlobalBounds().height);
    }
}

bool MonsterCard::isAlive()
{
    return alive;
}
