#include <iostream>
#include <SFML/Graphics.hpp>
#include "KMM_PROG_FRONTON.h"

using namespace sf;

int main() {

    // Configuració de la finestra
    Vector2f viewSize(x_max, y_max);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow window(vm, title, Style::Default);
    window.setFramerateLimit(60);

    // Creació de la pilota, el jugador i els blocs
    CircleShape bola(radi);
    RectangleShape player;
    std::vector<Bloque> bloques;

    // Inicialització de les variables de puntuació i temps
    int puntuacio = 0;
    int tempsLimit = 3600;  // Temps límit inicial
    Clock Rellotjejoc;

    // Definim com és la pilota
    crearmon(bola, player);
    InicialitzarBlocs(bloques);

    // Velocitat inicial de la pilota
    float ballSpeedX = 3.0f;
    float ballSpeedY = -3.0f;

    // Inicialització del rellotge per al temps transcorregut
    Clock cronometre;

    // Variable que indica si el joc continua
    bool fijoc = false;

    // Bucle principal del joc
    while (window.isOpen() && !fijoc) {

        // Actualitzem l'entrada
        Event event;
        while (window.pollEvent(event)) {
            // Comprovem si es tanca la finestra
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Actualitzem l'entrada del jugador  
        float dt = cronometre.restart().asSeconds();
        EntradaJugador(window, player, dt);

        // Actualitzem l'estat del joc
        fijoc = Update(dt, bola, player, ballSpeedX, ballSpeedY, bloques, puntuacio, tempsLimit, Rellotjejoc);

        // Dibuixem l'estat actual del joc
        Draw(window, bola, player, bloques, puntuacio, tempsLimit);
    }

    return 0;
}
