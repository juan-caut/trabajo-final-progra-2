#pragma once
#include"Entidad.h"
class CCiudadano : public Entidad
{
public:
	CCiudadano(int ancho, int alto, int i) :Entidad(ancho, alto) {
		idx = 1;
		idy = 0;
		dx = dy = 3;

		if      (i == 0) { x = 590; y = 425; }// posicion de habitante 0
		else if (i == 1) { x = 600; y = 210; }// posicion de habitante 1
		else if (i == 2) { x = 650; y = 100; }// posicion de habitante 2
		else if (i == 3) { x = 500; y = 320; }// posicion de habitante 3
		else if (i == 4) { x = 490; y = 445; }// posicion de habitante 4
	}
	~CCiudadano(){}

	void dibujar(Graphics^ g, Bitmap^ bmp)override {

		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.9, alto * 0.9);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);

	}
	void mover(Graphics^ g, int i) {
		switch (i)
		{
		case 2:                     //ciudadano 0
			//movimiento horizontal
			if (x + ancho * 0.9 > 710 || x < 630)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		case 1:	                    //ciudadano 1	
			//movimiento horizontal
			if (x + ancho * 0.9 > 650 || x < 580)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		case 3:		                //ciudadano 2
			//movimiento horizontal
			if (x + ancho * 0.9 > 540 || x < 460)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		case 4:		                //ciudadano 3
		    //movimiento vertical
			if (y + alto * 0.9 > 490 || y < 425)dy *= -1;

			if (dy > 0)idy = 0;
			else idy = 3;
			y += dy;

			break;
		case 0:		                //ciudadano 4
	        //movimiento vertical
			if (y + alto * 0.9 > 490 || y < 425)dy *= -1;

			if (dy > 0)idy = 0;
			else idy = 3;
			y += dy;

			break;
		}

		idx++;			
		if (idx > 2)idx = 0;
	}

	int getAncho() { return ancho*0.9; }
	int getAlto() { return alto*0.9; }
};
