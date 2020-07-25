#include "funciones.h"
#include <process.h>
#include "RedNeuronal.h"

using namespace std;


int ordenimprimir = 0;


void pintarbala(int dispx, int dispy, direccion dir,colores colorele)
{
	color(colorele);
	switch (dir)
	{
	case arriba:
		gotoxy(dispx, dispy);
		printf("%c", 223);
		gotoxy(dispx, dispy+1);
		printf(" ");
		break;
	case abajo:
		gotoxy(dispx, dispy);
		printf("%c", 223);
		gotoxy(dispx, dispy - 1);
		printf(" ");
		break;
	case izquierda:
		gotoxy(dispx, dispy);
		printf("%c ", 223);
		break;
	case derecha:
		gotoxy(dispx-1, dispy);
		printf(" %c", 223);
		break;
	default:
		break;
	}
	
}

int disparox, disparoy;
direccion dispdir;
bool destruir = true;


int disparoj2x, disparoj2y;
direccion dispj2dir;
bool destruirj2 = true;


void disparo(void* jug)
{
	destruir = false;
	while (!destruir)
	{

		switch (dispdir)
		{
		case arriba:
			Sleep(10);
			break;
		case abajo:
			Sleep(10);
			break;
		case izquierda:
			Sleep(5);
			break;
		case derecha:
			Sleep(5);
			break;
		default:
			break;
		}
		//colision
		if (disparox < 3 || disparoy < 0 || disparox > 100 || disparoy > 20)
		{
			switch (dispdir)
			{
			case arriba:
				disparoy++;
				break;
			case abajo:
				disparoy--;
				break;
			case izquierda:
				disparox++;
				break;
			case derecha:
				disparox--;
				break;
			default:
				break;
			}
			gotoxy(disparox, disparoy);
			cout << " ";
			destruir = true;
			break;
		}
		while (ordenimprimir != 2);
		pintarbala(disparox, disparoy, dispdir,Amarillo);
		if (destruirj2 == true)
		{
			ordenimprimir = 0;
		}
		else
		{
			ordenimprimir++;
		}
		switch (dispdir)
		{
		case arriba:
			disparoy--;
			break;
		case abajo:
			disparoy++;
			break;
		case izquierda:
			disparox--;
			break;
		case derecha:
			disparox++;
			break;
		default:
			break;
		}

	}

}

void disparoj2(void* jug)
{
	destruirj2 = false;
	while (!destruirj2)
	{

		switch (dispj2dir)
		{
		case arriba:
			Sleep(10);
			break;
		case abajo:
			Sleep(10);
			break;
		case izquierda:
			Sleep(5);
			break;
		case derecha:
			Sleep(5);
			break;
		default:
			break;
		}
		//colision
		if (disparoj2x < 3 || disparoj2y < 0 || disparoj2x > 100 || disparoj2y > 20)
		{
			switch (dispj2dir)
			{
			case arriba:
				disparoj2y++;
				break;
			case abajo:
				disparoj2y--;
				break;
			case izquierda:
				disparoj2x++;
				break;
			case derecha:
				disparoj2x--;
				break;
			default:
				break;
			}
			gotoxy(disparoj2x, disparoj2y);
			cout << " ";
			destruirj2 = true;
			break;
		}
		while (ordenimprimir != 3);
		pintarbala(disparoj2x, disparoj2y, dispj2dir,Verde);
		ordenimprimir = 0;
		switch (dispj2dir)
		{
		case arriba:
			disparoj2y--;
			break;
		case abajo:
			disparoj2y++;
			break;
		case izquierda:
			disparoj2x--;
			break;
		case derecha:
			disparoj2x++;
			break;
		default:
			break;
		}

	}

}


void hilo(void* j)
{
	Tanque jugador;
	jugador.dir = derecha;
	jugador.Tipo = J2;
	jugador.x = 60;
	jugador.y = 10;
	PintarTank(jugador.Tipo, jugador.x, jugador.y, jugador.dir);
	decision Tecla;
	decision dir[5] = { arr,abb,der,izq,disp };
	while (true)
	{
		Sleep(50);
		int numero = rand() % (5);
		Tecla = dir[numero];
		switch (Tecla)
		{
		case arr:
			if (jugador.dir == arriba)
			{
				if (jugador.y > 1)
				{
					jugador.y--;
				}


			}
			else
			{
				jugador.dir = arriba;
			}

			break;
		case izq:
			if (jugador.dir == izquierda)
			{
				if (jugador.x > 5)
				{
					jugador.x -= 2;
				}

			}
			else
			{
				jugador.dir = izquierda;
			}

			break;
		case abb:
			if (jugador.dir == abajo)
			{
				if (jugador.y < 20)
				{
					jugador.y++;
				}
			}
			else
			{
				jugador.dir = abajo;
			}

			break;
		case der:
			if (jugador.dir == derecha)
			{
				if (jugador.x < 100)
				{
					jugador.x += 2;
				}
			}
			else
			{
				jugador.dir = derecha;
			}

			break;
		case disp:
			if (destruirj2 == true)
			{
				dispj2dir = jugador.dir;
				disparoj2x = jugador.x;
				disparoj2y = jugador.y;
				_beginthread(disparoj2, 0, NULL);
			}
			break;

		}
		while (ordenimprimir != 1);
		PintarTank(jugador.Tipo, jugador.x, jugador.y, jugador.dir);
		if (destruir == true && destruirj2 == true)
		{
			ordenimprimir = 0;
		}
		else if (destruir == false && destruirj2 == true)
		{
			ordenimprimir++;
		}
		else if (destruir == false && destruirj2 == false)
		{
			ordenimprimir++;
		}
		else if (destruir == true && destruirj2 == false)
		{
			ordenimprimir+=2;
		}
		
	}
	_endthread();
}


int main(int argc, char* argv[])
{

	srand(time(NULL));
	_beginthread(hilo, 0, NULL);


	char tecla;
	Tanque jugador;
	jugador.dir = izquierda;
	jugador.Tipo = J1;
	jugador.x = 10;
	jugador.y = 10;
	PintarTank(jugador.Tipo, jugador.x, jugador.y, jugador.dir);
	while (true)
	{
		if (_kbhit())
		{
			tecla = _getch();
			switch (tecla)
			{
			case 'w':
				if (jugador.dir == arriba)
				{
					jugador.y--;

				}
				else
				{
					jugador.dir = arriba;
				}

				break;
			case 'a':
				if (jugador.dir == izquierda)
				{
					jugador.x -= 2;
				}
				else
				{
					jugador.dir = izquierda;
				}

				break;
			case 's':
				if (jugador.dir == abajo)
				{
					jugador.y++;
				}
				else
				{
					jugador.dir = abajo;
				}

				break;
			case 'd':
				if (jugador.dir == derecha)
				{
					jugador.x += 2;
				}
				else
				{
					jugador.dir = derecha;
				}

				break;
			case 'g':
				if (destruir == true)
				{
					dispdir = jugador.dir;
					disparox = jugador.x;
					disparoy = jugador.y;
					_beginthread(disparo, 0, NULL);
				}
				break;

			}
		}
		
		
		while (ordenimprimir != 0);
		PintarTank(jugador.Tipo, jugador.x, jugador.y, jugador.dir);
		ordenimprimir++;
	}
	
	_getch();
	return 0;
}