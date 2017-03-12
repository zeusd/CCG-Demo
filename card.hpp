#include <SFML/Graphics.hpp>

#ifndef CARD_HPP
#define CARD_HPP

class MonsterCard
{
    int atk;
    int hp;
    int mana;

    sf::Texture image;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text atkNum;
    sf::Text hpNum;
    sf::Text manaNum;

    sf::Vector2f position;


public:

    MonsterCard (int, int, int);

    void draw ();

    void setTexture (char);

    void setPosition (sf:: Vector2f);
};

#endif //CARD_HPP
