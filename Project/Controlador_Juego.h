#pragma once
#include"CAgente.h"
#include"CAliado.h"
#include"CCiudadano.h"
#include"CLider.h"
#include"CBalas.h"

class CControlador
{
private:
	int nivel;
	int puntaje;
	int minutos;
	int segundos;
	int cantHabitantes;
	int cantAliados;
	int cantAgentes;
	int cantVacunas;//level 2
	int contAliadosFallecidos;
	int contAliadosMisionCumplido;
	int contAgentesMuertos;//level 2
	CLider* lider;
	vector<CAliado*>enfermeras;
	vector<CAgente*>virus;
	vector<CCiudadano*>ciudadanos;
	vector<CBala*>vacunas;//level 2

public:
	CControlador(){}
	CControlador(Bitmap^ bmpLider, Bitmap^ bmpCiudadano, int _minutos, int _segundos, int _cantHabitantes, int _cantAliados, int _cantAgentes, int _cantVacunas, int _nivel) {
		nivel = _nivel;
		puntaje = 0;
		minutos = _minutos;
		segundos = _segundos;
		cantAliados = _cantAliados;
		cantHabitantes = _cantHabitantes;
		cantAgentes = _cantAgentes;
		cantVacunas = _cantVacunas;
		contAliadosFallecidos = 0;
		contAliadosMisionCumplido = 0;
		contAgentesMuertos = 0;

		lider = new CLider(bmpLider->Width / 3, bmpLider->Height / 4, nivel);//Width=ancho del sprite//Height=alto del sprite
		for (int i = 0; i < cantHabitantes; i++)
		{
			ciudadanos.push_back(new CCiudadano(bmpCiudadano->Width / 3, bmpCiudadano->Height / 4, i));
		}
	}
	~CControlador() {}

	void addAliado(Bitmap^ bmpAliado) {
		if (cantAliados>0) {
			enfermeras.push_back(new CAliado(bmpAliado->Width / 4, bmpAliado->Height / 4, cantHabitantes));
			cantAliados -= 1;
		}
	}
	void addAgente(Bitmap^ bmpAgente) {
		if(cantAgentes>0){
			virus.push_back(new CAgente(bmpAgente->Width / 4, bmpAgente->Height / 4, virus.size()));
			cantAgentes--;
		}
	}
	void addVacunas(Bitmap^ bmpvacunas) {//level 2
		if (cantVacunas>0) {
			vacunas.push_back(new CBala(bmpvacunas->Width, bmpvacunas->Height, lider->getX(), lider->getY()));
			cantVacunas -= 1;
		}
	}

	void dibujarEnfermeras(Graphics^ g, Bitmap^ bmpAliado) {
		for (int i = 0; i < enfermeras.size(); i++)
		{
			enfermeras[i]->dibujar(g, bmpAliado);
		}
	}
	void dibujarVirus(Graphics^ g, Bitmap^ bmpAgente) {

		for (int i = 0; i < virus.size(); i++)
		{
			virus[i]->dibujar(g, bmpAgente);
		}
	}
	void dibujarCiudadanos(Graphics^ g, Bitmap^ bmpCiudadano) {
		for (int i = 0; i < ciudadanos.size(); i++)
		{
			ciudadanos[i]->dibujar(g, bmpCiudadano);
		}
	}
	void dibujarVacunas(Graphics^ g, Bitmap^ bmpvacunas) {//level2
		for (int i = 0; i < vacunas.size(); i++)
		{
			vacunas[i]->dibujar(g, bmpvacunas);
		}
	}

	void moverCiudadanos(Graphics^ g) {
		for (int i = 0; i < ciudadanos.size(); i++)
		{
			ciudadanos[i]->mover(g, i);
		}
	}
	void moverAliados(Graphics^ g) {
		for (int i = 0; i < enfermeras.size(); i++)
		{
			if (enfermeras[i]->getY() >= 260 && enfermeras[i]->getY() < 300 && enfermeras[i]->getX() == 275) {
				enfermeras[i]->mover(g, 'S');
			}
			else if (enfermeras[i]->getY() >= 300 && enfermeras[i]->getX() > 135 && enfermeras[i]->getX() <= 275) {
				enfermeras[i]->mover(g, 'A');
			}
			else if (enfermeras[i]->getX() <= 135 && enfermeras[i]->getY() > 150 && enfermeras[i]->getY() <= 310) {
				enfermeras[i]->mover(g, 'W');
			}
			else if (enfermeras[i]->getY() <= 150 && enfermeras[i]->getX() < 400) {
				enfermeras[i]->mover(g, 'D');
			}
			else if (enfermeras[i]->getX() >= 400) {
				colisionAliadoCiudadano(i);
				if (colisionAliadoCiudadano(i) == false) {
					enfermeras[i]->cumplirMision(ciudadanos[enfermeras[i]->getposCiudadanoElegido()]);
				}
			}
		}
		for (int i = 0; i < enfermeras.size(); i++)
		{
			if (colisionAliadoCiudadano(i) == true) {//colisión de aliado con ciudadano
				puntaje += 10;
				enfermeras.erase(enfermeras.begin() + i);
				contAliadosMisionCumplido++;
			}
		}
	}
	void moverVirus(Graphics^ g) {

		for (int i = 0; i < virus.size(); i++)
		{
			if (virus[i]->getY() <= 550 && enfermeras.size() == 0) {
				virus[i]->mover('S');
			}
		}
		if (enfermeras.size() >= virus.size()) {
			for (int i = 0; i < virus.size(); i++)
			{
				virus[i]->PerseguirAliado(enfermeras[i]);

				if (colisionAgenteAliado(i)) { enfermeras[i]->setVisible(false); }//colision del aliado y agente
			}
		}
		if (enfermeras.size() < virus.size()) {
			for (int i = 0; i < enfermeras.size(); i++)
			{
				virus[i]->PerseguirAliado(enfermeras[i]);
				if (colisionAgenteAliado(i)) { enfermeras[i]->setVisible(false); }//colision del aliado y agente
			}
		}

		for (int i = 0; i < enfermeras.size(); i++)
		{
			if (!enfermeras[i]->getVisible()) {  //COLISIÓN del aliado y agente
				if (puntaje > 0) { puntaje -= 5; }//disminuye puntaje
				enfermeras.erase(enfermeras.begin() + i); //eliminar aliado
				contAliadosFallecidos++;
			}
		}
		for (int i = 0; i < virus.size(); i++)
		{
			if (colisionLiderAgente(i)) {//colision de lider y agente
				virus[i]->posInicial();//devuelve al agente a la posición inicial
			}
		}
	}
	void moverVacunas(Graphics^ g){//level 2

		for (int i = 0; i < vacunas.size(); i++)
		{
			vacunas[i]->mover(g, 'S');
		}

		//evaluar colisiones de la bala y agente
		for (int i = 0; i < vacunas.size(); i++)
		{
			for (int j = 0; j < virus.size(); j++)
			{
				if (colisionVacunaAgente(i, j)) {
					vacunas[i]->setVisible(false);
					virus[j]->setVisible(false);
				}
			}
		}
		//eliminar bala
		for (int i = 0; i < vacunas.size(); i++)
		{
			if (!vacunas[i]->getVisible() || vacunas[i]->getY()>=g->VisibleClipBounds.Height-120) {
				vacunas.erase(vacunas.begin() + i);
			}
		}
		//eliminar agente
		for (int i = 0; i < virus.size(); i++)
		{
			if (!virus[i]->getVisible()) {
				virus.erase(virus.begin() + i);
				contAgentesMuertos++;
			}
		}
	}
	
	bool colisionAliadoCiudadano(int i) {
		Rectangle rectObj1 = Rectangle(ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getX(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getY(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getAncho(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getAlto());
		Rectangle rectObj2 = Rectangle(enfermeras[i]->getX(), enfermeras[i]->getY(), enfermeras[i]->getAncho(), enfermeras[i]->getAlto());
		return rectObj1.IntersectsWith(rectObj2);
	}
	bool colisionAgenteAliado(int i) {
		Rectangle rectObj1 = Rectangle(virus[i]->getX(), virus[i]->getY(), virus[i]->getAncho(), virus[i]->getAlto());
		Rectangle rectObj2 = Rectangle(enfermeras[i]->getX(), enfermeras[i]->getY(), enfermeras[i]->getAncho(), enfermeras[i]->getAlto());
		return rectObj1.IntersectsWith(rectObj2);
	}
	bool colisionLiderAgente(int i) {
		Rectangle rectObj1 = Rectangle(virus[i]->getX(), virus[i]->getY(), virus[i]->getAncho(), virus[i]->getAlto());
		Rectangle rectObj2 = Rectangle(lider->getX(), lider->getY(), lider->getAncho(), lider->getAlto());
		return rectObj1.IntersectsWith(rectObj2);
	}
	bool colisionVacunaAgente(int i, int j) {//level2
		Rectangle rectObj2 = Rectangle(vacunas[i]->getX(), vacunas[i]->getY(), vacunas[i]->getAncho(), vacunas[i]->getAlto()-10);
		Rectangle rectObj1 = Rectangle(virus[j]->getX(), virus[j]->getY(), virus[j]->getAncho(), virus[j]->getAlto());
		return rectObj1.IntersectsWith(rectObj2);
	}

	CLider* getLider() { return lider; }

	void disminuirMinutos() { minutos -= 1; }
	void disminuirSegundos() { segundos -= 1; }
	void restaurarSegundos() { segundos += 60; }
	void disminuirCantAliados() { cantAliados -= 1; }

	int getMinutos() { return minutos; }
	int getSegundos() { return segundos; }
	int getPuntaje() { return puntaje; }
	int getcantAliados() { return cantAliados; }
	int getcantVacunas() { return cantVacunas; }//level 2
	int getAliadosFallecidos() { return contAliadosFallecidos; }
	int getAliadosMisionCumplido() { return contAliadosMisionCumplido; }
	int getAgentesMuertos() { return contAgentesMuertos; }//level 2
};


