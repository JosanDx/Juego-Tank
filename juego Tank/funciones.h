#pragma once
#include <stdio.h>  
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//enumeraciones
enum colores
{
	Negro,
	Azul,
	Verde,
	Aguamarina,
	Rojo,
	Purpura,
	Amarillo,
	Blanco,
	Gris,
	Azul_claro,
	Verde_claro,
	Aguamarina_claro,
	Rojo_claro,
	Purpura_claro,
	Amarillo_claro,
	Blanco_brillante
};
enum tipoTank
{
	J1,
	J2,
	E1,
	E2
};

enum tipoMuro
{
	Ladrillo,
	bloque
};
enum direccion
{
	arriba,
	abajo,
	izquierda,
	derecha
};


struct Tanque
{
	tipoTank Tipo;
	int x;
	int y;
	direccion dir;
};


void gotoxy(int x, int y);
void color(colores X);
void PintarTank(tipoTank Tipo, int CoordX, int CoordY, direccion Dir);
