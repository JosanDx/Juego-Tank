#include "funciones.h"

void gotoxy(int x, int y) 
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void color(colores X)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}

void PintarTank(tipoTank Tipo, int CoordX, int CoordY, direccion Dir)
{
	
	switch (Dir)
	{
	case arriba:
		switch (Tipo)
		{
		case J1:
			color(Amarillo);
			gotoxy(CoordX-1, CoordY-1);
			printf("  %c  ", 220);
			gotoxy(CoordX-1, CoordY);
			printf(" %c%c%c ", 219,219,219);
			gotoxy(CoordX - 1, CoordY + 1);
			printf("     ");

			break;
		case J2:
			color(Verde);
			gotoxy(CoordX - 1, CoordY - 1);
			printf("  %c  ", 220);
			gotoxy(CoordX - 1, CoordY);
			printf(" %c%c%c ", 219, 219, 219);
			gotoxy(CoordX - 1, CoordY + 1);
			printf("     ");
			break;
		case E1:
			color(Gris);
			gotoxy(CoordX, CoordY-1);
			printf(" %c ", 220);
			gotoxy(CoordX-1, CoordY );
			printf(" %c%c%c ", 219, 219, 219);
			gotoxy(CoordX-1, CoordY + 1);
			printf(" %c%c%c ", 223, 223, 223);
			gotoxy(CoordX - 1, CoordY + 2);
			printf("     ");
			break;
		case E2:
			color(Purpura);
			gotoxy(CoordX, CoordY - 1);   
			printf(" %c ", 220);
			gotoxy(CoordX - 1, CoordY);
			printf(" %c%c%c ", 219, 219, 219);
			gotoxy(CoordX - 1, CoordY + 1);
			printf(" %c%c%c ", 223, 223, 223);
			gotoxy(CoordX - 1, CoordY + 2);
			printf("     ");
			break;
		default:
			break;
		}
		break;
	case abajo:
		switch (Tipo)
		{
		case J1:
			color(Amarillo);
			gotoxy(CoordX, CoordY+1);
			printf(" %c ", 223);
			gotoxy(CoordX-1, CoordY);
			printf(" %c%c%c ", 219, 219, 219);
			gotoxy(CoordX - 1, CoordY-1);
			printf("     ");
			break;
		case J2:
			color(Verde);
			gotoxy(CoordX, CoordY + 1);
			printf(" %c ", 223);
			gotoxy(CoordX - 1, CoordY);
			printf(" %c%c%c ", 219, 219, 219);
			gotoxy(CoordX - 1, CoordY - 1);
			printf("     ");
			break;
		case E1:
			color(Gris);
			gotoxy(CoordX, CoordY + 1);
			printf("%c%c%c", 223, 219, 223);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c", 219, 219, 219);
			break;
		case E2:
			color(Purpura);
			gotoxy(CoordX, CoordY + 1);
			printf("%c%c%c", 223, 219, 223);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c", 219, 219, 219);
			break;
		default:
			break;
		}
		break;
	case izquierda:
		switch (Tipo)
		{
		case J1:
			color(Amarillo);
			gotoxy(CoordX, CoordY-1);
			printf("      ");
			gotoxy(CoordX-1, CoordY);
			printf(" %c%c%c  ", 220,219,219);
			gotoxy(CoordX-1, CoordY+1);
			printf("  %c%c  ", 223, 223);
			gotoxy(CoordX, CoordY +2);
			printf("      ");
			break;
		case J2:
			color(Verde);
			gotoxy(CoordX, CoordY - 1);
			printf("      ");
			gotoxy(CoordX - 1, CoordY);
			printf(" %c%c%c  ", 220, 219, 219);
			gotoxy(CoordX - 1, CoordY + 1);
			printf("  %c%c  ", 223, 223);
			gotoxy(CoordX, CoordY + 2);
			printf("      ");
			break;
		case E1:
			color(Gris);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c%c", 220, 219, 219,219);
			gotoxy(CoordX, CoordY + 1);
			printf(" %c%c%c", 223, 223,223);
			break;
		case E2:
			color(Purpura);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c%c", 220, 219, 219, 219);
			gotoxy(CoordX, CoordY + 1);
			printf(" %c%c%c", 223, 223, 223);
			break;
		default:
			break;
		}
		break;
	case derecha:
		switch (Tipo)
		{
		case J1:
			color(Amarillo);
			gotoxy(CoordX - 1, CoordY - 1);
			printf("       ");
			gotoxy(CoordX - 1, CoordY);
			printf("  %c%c%c  ", 219, 219, 220);
			gotoxy(CoordX - 1, CoordY + 1);
			printf("  %c%c   ", 223, 223);
			gotoxy(CoordX - 1, CoordY + 2);
			printf("       ");
			break;
		case J2:
			color(Verde);
			gotoxy(CoordX - 1, CoordY - 1);
			printf("       ");
			gotoxy(CoordX - 1, CoordY);
			printf("  %c%c%c  ", 219, 219, 220);
			gotoxy(CoordX - 1, CoordY + 1);
			printf("  %c%c   ", 223, 223);
			gotoxy(CoordX - 1, CoordY + 2);
			printf("       ");
			break;
		case E1:
			color(Gris);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c%c", 219, 219, 219, 220);
			gotoxy(CoordX, CoordY + 1);
			printf("%c%c%c ", 223, 223, 223);
			break;
		case E2:
			color(Purpura);
			gotoxy(CoordX, CoordY);
			printf("%c%c%c%c", 219, 219, 219, 220);
			gotoxy(CoordX, CoordY + 1);
			printf("%c%c%c ", 223, 223, 223);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	
}