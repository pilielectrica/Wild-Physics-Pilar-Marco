#include "crosshair.h"
#include "enemigos.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
	srand(time(NULL));
	Event evt;
	Crosshair _crosshair;
	Enemigos _enemigo;
	_crosshair.seteartexturacrosshair();
	_enemigo.setearenemigo();
	int score = 0;
	bool disparo = false;
	Text mensajepuntos;
	Font font;
	mensajepuntos.setFont(font);
	mensajepuntos.setCharacterSize(24);
	mensajepuntos.setPosition(10, 10);
	mensajepuntos.setFillColor(sf::Color::White);
	font.loadFromFile("SIXTY.TTF");
	bool ganaste = false;


	sf::RenderWindow App(sf::VideoMode(600, 600, 32),
		"Que ventana horrible");
	App.setMouseCursorVisible(false);

	// Loop principal
	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			Vector2i cursorPosition = Mouse::getPosition(App);
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::MouseMoved:
				_crosshair.actualizarPosicionCursor(evt.mouseMove.x, evt.mouseMove.y);
				break;

			}Vector2f crosshairPosition = _crosshair.mostrarsprite().getPosition();

			if (_enemigo.aparecer().getGlobalBounds().contains(crosshairPosition.x, crosshairPosition.y))
			{
				if (evt.type == Event::MouseButtonReleased)
				{

					score += 1;
					if (score >= 5)
					{
						ganaste = true;
					}
				}
			}


		}_enemigo.moverse();

		if (ganaste)
		{

			App.clear();
			Text textoGanaste("GANASTE", font, 36);
			textoGanaste.setFillColor(Color::White);
			textoGanaste.setPosition(200, 200);
			App.draw(textoGanaste);
			App.display();
		}
		else
		{
			App.clear();

			App.draw(_enemigo.aparecer());
			App.draw(_crosshair.mostrarsprite());
			mensajepuntos.setString("Puntaje: " + to_string(score));
			App.draw(mensajepuntos);
			// Mostramos la ventana
			App.display();

		}


	}

	return 0;
}