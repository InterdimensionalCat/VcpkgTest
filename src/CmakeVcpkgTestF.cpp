// CmakeVcpkgTestF.cpp : Defines the entry point for the application.
//

#include "CmakeVcpkgTestF.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"
#include "boost/uuid/uuid.hpp"
#include "tmxlite/Map.hpp"

using namespace std;

int main()
{
    //json testing////////////////////////////////////////////
    nlohmann::json jsontest;

    //boost testing///////////////////////////////////////////
    boost::uuids::uuid uuidtest;

    //tmxlite testing/////////////////////////////////////////
    tmx::Map map;

    //sfml testing////////////////////////////////////////////
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
