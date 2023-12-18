#include "Enemigos.h"#include "Enemigos.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

void Enemigos::setearenemigo()
{
    enemigotexture.loadFromFile("et.png");
    enemigo.setTexture(enemigotexture);
    enemigo.setScale(0.05, 0.05);
}
Sprite Enemigos::aparecer()
{
    return enemigo;
}
void Enemigos::mostrarPosicion()
{
    enemigo.getPosition();
}
void Enemigos::moverse()
{
    float deltaTime = clock.restart().asSeconds();
    tiempoactual += deltaTime;

    if (tiempoactual >= tiempodeaparicion) {
        tiempoactual = 0;
        randomnumber3 = rand() % 500;
        randomnumber4 = rand() % 500;
        enemigo.setPosition(randomnumber3, randomnumber4);
    }

    float velocidad = 200.0f;
    float distancia = velocidad * deltaTime;

    sf::Vector2f posicionActual = enemigo.getPosition();
    enemigo.setPosition(posicionActual.x + distancia, posicionActual.y);

}
Clock Enemigos::getClock()
{
    return clock;
}
Enemigos::Enemigos()
{
    tiempodeaparicion = 0.7f;
    tiempoactual = 0;
}