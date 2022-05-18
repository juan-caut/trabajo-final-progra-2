#pragma once
#include"Entidad.h"
class CLider : public Entidad
{
private:
	int nivel;
public:
	CLider(int ancho, int alto, int _nivel) :Entidad(ancho, alto) {
		nivel = _nivel;
		idx = idy = 0;
		dx = dy = 10;
		x = 292;
		y = 105;
	}
	~CLider(){}

	void dibujar(Graphics^ g, Bitmap^ bmp)override {

		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, char i) {
		if (nivel == 1) {
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
			}
			idx++;
			if (idx > 2)idx = 0;
		}
		else if (nivel == 2) {
			switch (i)
			{
			case 'A':
				if (x > 110) {
					x -= dx;
					idy = 0;
				}
				break;
			case 'D':
				if (x + ancho * 1.0 < g->VisibleClipBounds.Width - 50) {
					x += dx;
					idy = 0;
				}
				break;
			}
			idx++;
			if (idx > 2)idx = 0;
		}
	}
	
	int getAncho() { return ancho * 1.0; }
	int getAlto() { return alto * 1.0; }

};
