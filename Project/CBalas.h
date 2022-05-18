#pragma once
#include"Entidad.h"

class CBala: public Entidad {
private:
	bool visible;
public:
	CBala(int ancho,int alto, int x,int y):Entidad(ancho, alto) {
		this->x = x + 10;
		this->y = y + 10;
		dx = dy = 25;
		visible = true;
	}
	~CBala(){}

	void dibujar(Graphics^ g, Bitmap^ bmp)override {
		g->DrawImage(bmp, x, y, ancho * 0.3, alto * 0.3);
	}
	void mover(Graphics^ g, char direccion) {
		if (direccion == 'S' && y + alto * 0.3 <= g->VisibleClipBounds.Height) {
			y += dy;
		}
	}
	
	int getAncho() { return ancho * 0.3; }
	int getAlto() { return alto * 0.3; }

	void setVisible(bool b) { visible = b; }
	int getVisible() { return visible; }
};