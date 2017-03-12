#include <SFML/Graphics.hpp>
#include "MonsterCard.hpp"

int main()
{
    int const width = 1920;
    int const height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "", sf::Style::Fullscreen);

    sf::RectangleShape nest[20];

    for (int j=0; j<4; j++)
    {
        for (int i=0; i<5; i++)
        {
            nest[i+5*j].setSize(sf::Vector2f(180, 240));
            nest[i+5*j].setFillColor(sf::Color(115, 77, 38));
            nest[i+5*j].setPosition(400 + 184*i, 54 + 244*j);
        }
    }

    sf::RectangleShape highlight(sf::Vector2f(180, 240));
    highlight.setFillColor(sf::Color::Transparent);
    highlight.setOutlineThickness(4);
    highlight.setOutlineColor(sf::Color::Blue);

    sf::CircleShape hero1(60, 6);
    hero1.setFillColor(sf::Color(110, 110, 110));
    hero1.setOutlineThickness(4);
    hero1.setOutlineColor(sf::Color(150, 100, 50));
    hero1.setPosition(800, -20);

    sf::CircleShape hero2(60, 6);
    hero2.setFillColor(sf::Color(110, 110, 110));
    hero2.setOutlineThickness(4);
    hero2.setOutlineColor(sf::Color(150, 102, 50));
    hero2.setPosition(800, 980);

    sf::CircleShape portrait1(130);
    portrait1.setFillColor(sf::Color(110, 110, 110));
    portrait1.setOutlineThickness(10);
    portrait1.setOutlineColor(sf::Color::Transparent);
    portrait1.setPosition(40, 166);

    sf::CircleShape portrait2(130);
    portrait2.setFillColor(sf::Color(110, 110, 110));
    portrait2.setOutlineThickness(10);
    portrait2.setOutlineColor(sf::Color::Yellow);
    portrait2.setPosition(40, 654);

    int touchID;
    int chosenCard;
    bool click = 0;
    bool drag = 0;
    bool pickingCard = 1;
    bool choice = 0;
    bool attack = 0;
    bool hit = 0;

    bool full[20] = {0};
    bool choosable[20] = {0};

    MonsterCard *dragCard;
    sf::Vector2f dragOrig;

    MonsterCard deck[2];
    MonsterCard *board[20];

    deck[0].setStats(70, 20, 10);
    deck[1].setStats(10, 1, 2);

    deck[0].setPosition(1500, 200);
    deck[1].setPosition(1500, 500);

    while (window.isOpen())
    {
       sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }

        click = sf::Mouse::isButtonPressed(sf::Mouse::Left) ? true : false;

        window.clear(sf::Color(150, 100, 50));

        for (int i=0; i<20; i++)
        {
            window.draw(nest[i]);
        }

        window.draw(portrait1);
        window.draw(portrait2);

        for (int i=0; i<2; i++)
        {
            window.draw(deck[i]);
        }

        for (int j=0; j<4; j++)
        {
            for (int i=0; i<5; i++)
            {
                if (nest[i + 5*j].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition())
                    && !(hero1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition()) || hero2.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition())))
                {
                    {
                        highlight.setPosition(400 + 184*i, 54 + 244*j);
                        touchID = i + 5*j;

                        if (attack && !choice && full[touchID] && touchID != chosenCard)
                        {
                            highlight.setFillColor(sf::Color(255, 0, 0, 100));
                            highlight.setOutlineColor(sf::Color::Transparent);
                            window.draw(highlight);
                        }

                        else
                        {
                            highlight.setFillColor(sf::Color::Transparent);
                            highlight.setOutlineColor(sf::Color::Blue);
                        }

                        if (pickingCard && full[i + 5*j])
                        {
                            window.draw(highlight);
                        }
                    }
                }
            }
        }

        for (int i = 0; i<2; i++)
        {
            if (!drag && click && deck[i].contains(((sf::Vector2f)sf::Mouse::getPosition())) && sf::Mouse::getPosition().x > 1500)
            {
                drag = 1;
                dragCard = &deck[i];
                dragOrig = deck[i].getPosition();
            }
        }

        for (int i=0; i<20; i++)
        {
            if (pickingCard && full[i] && board[i]->contains((sf::Vector2f)sf::Mouse::getPosition()) && click)
            {
                pickingCard = 0;
                chosenCard = i;
                choice = 1;
                attack = 1;
                hit=0;
            }
        }

        if (choice)
        {
            hit = 0;

            for (int j = chosenCard/5 - 1; j<=chosenCard/5 + 1; j++)
            {
                for (int i = chosenCard%5 - 1; i<=chosenCard/5 + 1; i++)
                {
                    if (chosenCard != i+5*j && full[i+5*j] && attack && board[i+5*j]->isAlive())
                    {
                        choosable[i+5*j] = 1;
                        nest[i+5*j].setOutlineThickness(4);
                        nest[i+5*j].setOutlineColor(sf::Color::Red);
                        choice = 0;
                    }

                    else
                    {
                        choosable[i+5*j]=0;
                        nest[i+5*j].setOutlineThickness(0);
                    }
                }
            }

            if (choice)
            {
                hit=1;
            }
        }

        if (attack && !choice && !hit)
        {
            if (click)
            {
                for (int j = chosenCard/5 - 1; j<=chosenCard/5 + 1; j++)
                {
                    for (int i = chosenCard%5 - 1; i<=chosenCard/5 + 1; i++)
                    {
                        if (choosable[i+5*j] && (nest[i+5*j].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition())))
                        {
                            board[i+5*j]->damage(board[chosenCard]->getAtk());
                            nest[i+5*j].setOutlineThickness(0);
                            highlight.setOutlineColor(sf::Color::Blue);
                            attack = 0;

                            if (!board[i+5*j]->isAlive())
                            {
                                full[i+5*j] = 0;
                            }
                        }
                    }
                }
            }
        }

        if (!attack && !choice && !hit && !click)
        {
            pickingCard = 1;
        }

        if (drag)
        {
            dragCard->setPosition((float)sf::Mouse::getPosition().x - 90, float(sf::Mouse::getPosition().y) - 120);
        }

        if (drag && !click)
        {
            if(touchID>=0)
            {
                int x = touchID%5;
                int y = touchID/5;

                dragCard->setPosition(400 + 184*x, 54 + 244*y);
                board[touchID] = dragCard;
                full[touchID] = 1;

                drag = 0;
            }

            else
            {
                dragCard->setPosition(dragOrig);
                drag = 0;
            }
        }

        touchID = -3;

        window.draw(hero1);
        window.draw(hero2);

        window.display();

    }

    return 0;
}
