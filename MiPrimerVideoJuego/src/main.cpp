#include <SFML/Graphics.hpp>
#include <iostream>

#include "matematicas/Matematicas.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mi primer video juego");
	//window.setFramerateLimit(60.f);
	window.setVerticalSyncEnabled(true);

	sf::RectangleShape jugador(sf::Vector2f(50.f, 50.f));
	jugador.setFillColor(sf::Color::Green);

	jugador.setOrigin(jugador.getSize().x / 2.f, jugador.getSize().y / 2.f);

	jugador.setPosition(800.f / 2.f, 600.f / 2.f);
	jugador.setRotation(58.f);

	sf::Clock reloj;
	float DeltaTime = 0.f;

	sf::Vector2f direccion;
	float velocidad = 90.f;

	sf::Mouse mouse;
	sf::Vector2f mousePosicion = sf::Vector2f(mouse.getPosition(window));

	while (window.isOpen())
	{
		DeltaTime = reloj.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		sf::Event eventos;
		while ( window.pollEvent( eventos ) )
		{
			if (eventos.type == sf::Event::Closed)
				window.close();
		}
		
		mousePosicion = sf::Vector2f(mouse.getPosition(window));

		//std::cout << DeltaTime << std::endl;

		direccion = sf::Vector2f(sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A), 
					sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		direccion = normalizar(direccion);

		jugador.setRotation(miraA(jugador.getPosition(), mousePosicion));
		jugador.move(direccion * velocidad * DeltaTime);

		window.clear(sf::Color(35, 35, 35, 255));
		
		window.draw(jugador);

		window.display();
	}

	return 0;
}