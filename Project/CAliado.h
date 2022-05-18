#pragma once
#include"CCiudadano.h"
#include"Entidad.h"
class CAliado : public Entidad
{
private:
	int posCiudadanoElegido;
	bool visible;
public:
	CAliado(int ancho, int alto, int cantHabitantes) :Entidad(ancho, alto) {
		idx = idy = 0;
		dx = dy = 8;
		x = 275;
		y = 260;
		visible = true;
		posCiudadanoElegido = rand() % cantHabitantes + 0;
	}
	~CAliado(){}

	void dibujar(Graphics^ g, Bitmap^ bmp)override {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 110) {
				x -= dx;
				idy = 1;
			}
			break;
		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width - 50) {
				x += dx;
				idy = 2;
			}
			break;
		case 'W':
			if (y > 100) {
				y -= dy;
				idy = 3;
			}
			break;
		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height - 110) {
				y += dy;
				idy = 0;
			}
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void cumplirMision(CCiudadano* Ciudadano) {
		
		//ir a la posición del ciudadano elegido
		if (x == Ciudadano->getX()) {
			x += 0;
		}
		else if (x > Ciudadano->getX()) {
			x -= dx;
			idy = 1;
		}
		else if (x < Ciudadano->getX()) {
			x += dx;
			idy = 2;
		}
		if (y == Ciudadano->getY()) {
			y += 0;
		}
		else if (y > Ciudadano->getY()) {
			y -= dy;
			idy = 3;
		}
		else if (y < Ciudadano->getY()) {
			y += dy;
			idy = 0;
		}

		idx++;
		if (idx > 3)idx = 0;
	}

	int getposCiudadanoElegido() { return posCiudadanoElegido; }
	void setVisible(bool b) { visible = b; }
	int getVisible() { return visible; }

	int getAncho() { return ancho * 1.0; }
	int getAlto() { return alto * 1.0; }
};

