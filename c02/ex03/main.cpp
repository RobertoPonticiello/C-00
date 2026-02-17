#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// In questo esercizio la funzione `bsp` (Binary Space Partitioning / point-in-triangle)
// deve dire se un punto `point` è *strettamente* dentro il triangolo (a, b, c).
// Nota importante (in base alla tua implementazione in `bsp.cpp`):
// - Se il punto è su un lato o su un vertice => la funzione deve ritornare `false`.
// - Se il triangolo è degenerato (3 punti allineati, area 0) => `false`.
//
// Qui sotto dichiariamo `bsp` perché nel progetto non esiste un header dedicato.
bool bsp(Point const a, Point const b, Point const c, Point const point);

// Stampa un Point usando i getter `x()` e `y()` che ritornano Fixed.
// L'operatore << di Fixed stampa il valore in float (Fixed::toFloat()).
static void printPoint(Point const &p)
{
	std::cout << "(" << p.x() << ", " << p.y() << ")";
}

// Esegue un singolo caso di test:
// - stampa nome e coordinate
// - chiama `bsp(a,b,c,p)`
// - confronta con l'aspettativa e stampa PASS/FAIL
static void runCase(
		std::string const &name,
		Point const &a,
		Point const &b,
		Point const &c,
		Point const &p,
		bool expected)
{
	bool result = bsp(a, b, c, p);

	std::cout << name << "\n";
	std::cout << "  A=";
	printPoint(a);
	std::cout << "  B=";
	printPoint(b);
	std::cout << "  C=";
	printPoint(c);
	std::cout << "\n";
	std::cout << "  P=";
	printPoint(p);
	std::cout << "\n";
	std::cout << "  expected=" << (expected ? "true" : "false")
			  << "  got=" << (result ? "true" : "false")
			  << "  => " << ((result == expected) ? "PASS" : "FAIL")
			  << "\n\n";
}

int main( void )
{
	// Triangolo "canonico" nel primo quadrante.
	// È un triangolo rettangolo con vertice in origine:
	//   A(0,0), B(10,0), C(0,10)
	// L'interno è la regione con x>0, y>0 e x+y<10.
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	// Punto chiaramente interno.
	runCase("Inside (simple)", a, b, c, Point(1.0f, 1.0f), true);
	// Punto chiaramente esterno (ben oltre l'ipotenusa x+y=10).
	runCase("Outside (far)", a, b, c, Point(10.0f, 10.0f), false);
	// Punto esterno ma "vicino": x+y=11 > 10 quindi fuori.
	runCase("Outside (near)", a, b, c, Point(8.0f, 3.0f), false);

	// Punti sul bordo:
	// nella consegna classica di CPP02/ex03, spesso si richiede "strictly inside".
	// La tua `bsp` inoltre esclude esplicitamente i casi con area/segni = 0,
	// quindi su lati e vertici ci aspettiamo `false`.

	// Sul lato AB: y=0.
	runCase("On edge AB", a, b, c, Point(5.0f, 0.0f), false);
	// Sul lato AC: x=0.
	runCase("On edge AC", a, b, c, Point(0.0f, 5.0f), false);
	// Sul lato BC: qui è l'ipotenusa x+y=10 (es. (5,5)).
	runCase("On edge BC", a, b, c, Point(5.0f, 5.0f), false);

	// Esattamente sui vertici.
	runCase("On vertex A", a, b, c, Point(0.0f, 0.0f), false);
	runCase("On vertex B", a, b, c, Point(10.0f, 0.0f), false);
	runCase("On vertex C", a, b, c, Point(0.0f, 10.0f), false);

	// Triangolo degenerato (punti allineati): area = 0.
	// Qui ci aspettiamo sempre `false` indipendentemente dal punto testato.
	Point d0(0.0f, 0.0f);
	Point d1(5.0f, 5.0f);
	Point d2(10.0f, 10.0f);
	runCase("Degenerate triangle", d0, d1, d2, Point(1.0f, 1.0f), false);

	// Triangolo con coordinate negative:
	// verifica che la logica non dipenda dal "quadrante".
	Point n0(-10.0f, 0.0f);
	Point n1(0.0f, -10.0f);
	Point n2(0.0f, 0.0f);
	// Punto interno (vicino all'origine ma nel triangolo).
	runCase("Inside (negative coords)", n0, n1, n2, Point(-1.0f, -1.0f), true);
	// Punto esterno: x positivo quindi a destra del triangolo.
	runCase("Outside (negative coords)", n0, n1, n2, Point(1.0f, -1.0f), false);
	// Sull'ipotenusa tra n0 e n1 (retta x+y=-10): anche qui bordo => `false`.
	runCase("On hypotenuse (negative coords)", n0, n1, n2, Point(-5.0f, -5.0f), false);

	return 0;
}