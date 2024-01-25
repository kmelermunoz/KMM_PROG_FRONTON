// Prototips de les funcions
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

// Constants del joc
const std::string title = "Fronton";
const float ballSpeedBase = 7.0f;
const float playerSpeed = 9.0f;
const int x_min = 0, x_max = 800;
const int y_min = 0, y_max = 600;
const int incre_xr = 10, incre_yr = 10;
const int longitut = 100, amplada = 20, radi = 25;
const int numBloques = 10;
const int ampleBloc = 60;
const int alcadaBloc = 20;
const int espaiEntreBloques = 20;
const int numBloquesFilas = 6;

// Estructura del bloc
struct Bloque {
    sf::RectangleShape shape;
    bool activo;

    Bloque(sf::Vector2f size) : shape(size), activo(true) {
    }
};

// Prototips de les funcions
bool Update(float dt, CircleShape& bola, RectangleShape& player, float& ballSpeedX, float& ballSpeedY, std::vector<Bloque>& blocs, int& puntuacio, int& tempsLimit, Clock Rellotjejoc);
void Draw(RenderWindow& finestre, CircleShape& bola, RectangleShape& player, std::vector<Bloque>& blocs, int punt, int tempsLimit);
void crearmon(CircleShape& bola, RectangleShape& player);
void EntradaJugador(RenderWindow& finestre, RectangleShape& jugador, float dt);
void InicialitzarBlocs(std::vector<Bloque>& blocs);
void DibuixarBlocs(RenderWindow& finestra, const std::vector<Bloque>& blocs);
bool ColisioAmbBlocs(CircleShape& pilota, RectangleShape& blocs);
