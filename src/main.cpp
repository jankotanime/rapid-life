#include <SFML/Graphics.hpp>
#include <iostream>

void paint(sf::RenderWindow& window) {
    // Tworzymy kształt - np. okrąg
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color(100, 250, 50));  // Ustawiamy kolor wypełnienia

    // Rysowanie obiektu na ekranie
    window.draw(shape);
}

int main() {
    // Tworzymy okno o rozmiarze 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rapid Life");

    // Ustawiamy limit klatek na sekundę
    window.setFramerateLimit(60);

    // Pętla główna, która działa dopóki okno jest otwarte
    while (window.isOpen()) {
        sf::Event event;
        
        // Przechodzimy przez wszystkie zdarzenia
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Zamykamy okno, gdy zdarzenie "Closed" następuje
        }

        // Czyszczenie okna przed narysowaniem nowego klatki
        window.clear();

        // Wywołanie funkcji paint, która rysuje obiekt
        paint(window);

        // Pokazujemy zawartość okna
        window.display();
    }

    return 0;
}
