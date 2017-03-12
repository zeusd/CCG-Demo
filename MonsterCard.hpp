#include <SFML/Graphics.hpp>

#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP

class MonsterCard : public sf::Drawable, public sf::Transformable
{
    int atk;
    int hp;
    int mana;
    bool alive;

    sf::Texture image;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text atkNum;
    sf::Text hpNum;
    sf::Text manaNum;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(alive)
    {
        states.transform *= getTransform();

        target.draw(sprite, states);
        target.draw(atkNum, states);
        target.draw(hpNum, states);
        target.draw(manaNum, states);
    }
}

public:

    MonsterCard();

    void setPosition(float, float);

    void setPosition(sf::Vector2f);

    sf::Vector2f getPosition();

    void setTexture(sf::String);

    bool contains(sf::Vector2f);

    void setStats(int, int, int);

    int getAtk();

    void damage(int);

    bool isAlive();
};

#endif //MONSTERCARD_HPP
