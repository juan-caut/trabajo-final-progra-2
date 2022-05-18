#pragma once
#include"Entidad.h"
#include"CAliado.h"
class CAgente : public Entidad
{
private:
	int posInicialX;
	int posInicialY;
	bool visible;
public:
	CAgente(int ancho, int alto, int i) :Entidad(ancho, alto) {
		idx = 0;
		idy = 0;
		dx = dy = 7;
		visible = true;
		
		if (i%2 == 0) {
			posInicialX = x = 210;
			posInicialY = y = 610;
		}
		else if (i%2 != 0) {
			posInicialX = x = 750;
			posInicialY = y = 410;
		}
	}
	~CAgente(){}

	void dibujar(Graphics^ g, Bitmap^ bmp)override {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.8, alto * 0.8);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(char i) {
		switch (i)
		{
		case 'S':
			if (y + alto * 1.0 < 560) {
				y += dy;
				idy = 0;
			}
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void PerseguirAliado(CAliado* aliado) {

		//ir a la posición del aliado elegido
		if (x == aliado->getX()) {
			x += 0;
		}
		else if (x > aliado->getX()) {
			x -= dx;
			idy = 1;
		}
		else if (x < aliado->getX()) {
			x += dx;
			idy = 2;
		}

		if (y == aliado->getY()) {
			y += 0;
		}
		else if (y > aliado->getY()) {
			y -= dy;
			idy = 3;
		}
		else if (y < aliado->getY()) {
			y += dy;
			idy = 0;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
	void posInicial() {
		x = posInicialX;
		y = posInicialY;
	}

	void setVisible(bool b) { visible = b; }
	int getVisible() { return visible; }
	int getAncho() { return ancho*0.8; }
	int getAlto() { return alto*0.8; }
};
