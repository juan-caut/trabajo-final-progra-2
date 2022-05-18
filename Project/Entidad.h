#pragma once
#include"Dependencias.h"
class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
public:
	Entidad(int _ancho, int _alto) {
		ancho = _ancho;
		alto = _alto;
	}
	~Entidad(){}

	virtual void dibujar(Graphics^ g, Bitmap^ bmp){}
	virtual void mover(){}
	
	int getX() { return x; }
	int getY() { return y; }
	void setX(int value) { x = value; }
	void setY(int value) { y = value; }
};