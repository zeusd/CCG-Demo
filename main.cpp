#include <SFML/Graphics.hpp>

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
    hero1.setOutlineThickness(6);
    hero1.setOutlineColor(sf::Color(150, 100, 50));
    hero1.setPosition(800, -20);

    sf::CircleShape hero2(60, 6);
    hero2.setFillColor(sf::Color(110, 110, 110));
    hero2.setOutlineThickness(6);
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
    bool hit;

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

        hit = sf::Mouse::isButtonPressed(sf::Mouse::Left) ? true : false;

        window.clear(sf::Color(150, 100, 50));

        for (int i=0; i<20; i++)
        {
            window.draw(nest[i]);
        }

        if (hero1.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, float(sf::Mouse::getPosition().y)))
        {
            if (hit)
            {
                hero1.setOutlineColor(sf::Color::Red);
                touchID = 0;
            }

            else
            {
                hero1.setOutlineColor(sf::Color::Blue);
            }
        }

        else
        {
            hero1.setOutlineColor(sf::Color(150, 100, 50));
        }

        if (hero2.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, float(sf::Mouse::getPosition().y)))
        {
            if (hit)
            {
                hero2.setOutlineColor(sf::Color::Red);
                touchID = -1;
            }

            else
            {
                hero2.setOutlineColor(sf::Color::Blue);
            }
        }

        else
        {
            hero2.setOutlineColor(sf::Color(150, 100, 50));
        }

        for (int j=0; j<4; j++)
        {
            for (int i=0; i<5; i++)
            {
                if (nest[i+5*j].getGlobalBounds().contains((float)sf::Mouse::getPosition().x, float(sf::Mouse::getPosition().y))
                    && !(hero1.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, float(sf::Mouse::getPosition().y)) ||
                         hero2.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, float(sf::Mouse::getPosition().y))))
                {
                    {
                        highlight.setPosition(400 + 184*i, 54 + 244*j);

                        //if (...)
                        {
                            if (hit)
                            {
                                highlight.setOutlineColor(sf::Color::Red);
                                touchID = ++i + 5*j;
                            }

                            else
                            {
                                highlight.setOutlineColor(sf::Color::Blue);
                            }

                            window.draw(highlight);
                        }
                    }
                }
            }
        }

        window.draw(hero1);
        window.draw(hero2);

        window.draw(portrait1);
        window.draw(portrait2);

        window.display();

    }

    return 0;
}
