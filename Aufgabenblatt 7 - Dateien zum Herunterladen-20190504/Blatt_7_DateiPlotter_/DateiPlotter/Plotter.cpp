#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Plotter(const double xWerte[], const double yWerte[], int AnzWerte, bool bFuellen)
{
	const int xOffset = 12;					// linker Rand für Werte und Achse
	const int xBreite = 80;				    // normale Breite des Konsolenfensters
	const int xMaxBreite = xBreite-xOffset;	// Breite der Zeichenflaeche ohne Rahmen
	const int yMaxHoehe = 40;				// Hoehe der Anzeige
	int xAnzahl = 0;						// Anzahl der genutzten x-Werte
	int yAnzahl = yMaxHoehe;				// Anzahl der Unterteilungen der y-Achse
	double yAchse[yMaxHoehe]={0.0};			// Array zur Speicherung der y-Werte
	double ymin = 0.0;
	double ymax = 0.0;
	bool xVorzWechsel = false;
	bool yVorzWechsel = false;
	int xNullPos = -1;						// Lage der Null auf x-Achse
	int yNullPos = -1;						// Lage der Null auf y-Achse
	char Graphik[xBreite][yMaxHoehe];		// Array zur Speicherung der zu druckenden Zeichen
	const char symbol = '*';				// Zeichen, das gedruckt wird

	//Initialisierung der "Zeichenflaeche" mit Leerzeichen
	for(int x=0;x<xBreite;x++)
	{
		for(int y=0;y<yMaxHoehe;y++) Graphik[x][y]=' ';
	}

	// Anzahl der x-Werte bestimmen
	xAnzahl = (AnzWerte < xMaxBreite) ? AnzWerte : xMaxBreite;
	if(xAnzahl != AnzWerte) 
	{
		cout << "Hinweis:\nEs koennen nicht alle x-Werte dargestellt werden." 
			 << "\nIhre Anzahl wurde auf " << xAnzahl << " reduziert." << endl;
	}

	/**************************
	Koordinatensystem bestimmen 
	***************************/

	/* Position der x-Achse bestimmen:
	   Gibt es einen Vorzeichenwechsel bei den y-Werten? 
	   Dann Lage der Null bestimmen */
	ymin=yWerte[0];
	ymax=yWerte[0];
	for (int i=1;i<xAnzahl;i++)
		{
			ymin = (ymin < yWerte[i]) ? ymin : yWerte[i];
			ymax = (ymax > yWerte[i]) ? ymax : yWerte[i];
		}
	yVorzWechsel = (ymin * ymax) < 0.0;
	double yStep = abs(ymax-ymin) / (yAnzahl-1);

	/* Lage der x-Achse bestimmen
	   es wird der y-Wert genommen, welcher gleich Null oder der Null an nächsten ist 
	   dabei ist die Anzahl der y-Achsenwerte zu beachten */
	if(yVorzWechsel)
	{
		int i = 0;
		do
		{
			if(( ymin + i * yStep ) == 0)
			{	
				yNullPos = i;
			}
			else if( (ymin + i*yStep)*(ymin+(i+1)*yStep) < 0 ) 
			{
				yNullPos = i;
			}
			i++;
		}while( (yNullPos<0) && (i<xAnzahl) );
	}
	else if(ymin == 0.) 
	{
		yNullPos = 0;
	}
	else if (ymax == 0.)
	{
		yNullPos = yAnzahl-1;
	}

	/* Position der y-Achse bestimmen
		es wird der x-Wert genommen, welcher gleich Null oder der Null an nächsten ist */
	xVorzWechsel = (xWerte[xAnzahl-1] * xWerte[0]) < 0;	

	if(xVorzWechsel)
	{
		int i = 0;
		do
		{
			if(xWerte[i]*xWerte[i+1] <= 0) xNullPos = i + ( (abs(xWerte[i]) < abs(xWerte[i+1])) ? 0 : 1 );
			i++;
		}while( (xNullPos<0) && (i<xAnzahl-1) );
	}
	
	/* y-Achse definieren
	   ohne Vorzeichenwechsel muss die Nulllage oben oder unten richtig bestimmt werden */
	if(yVorzWechsel)
	{
		yAchse[yNullPos] = 0.0;
		for (int yPos = yNullPos + 1;(yPos < yAnzahl);yPos++)
		{
			yAchse[yPos] = yAchse[yPos-1] + yStep;
		}
		for (int yPos = yNullPos - 1;(yPos >= 0);yPos--)
		{
			yAchse[yPos] = yAchse[yPos+1] - yStep;
		}
	}
	else 
	{
		yAchse[0] = ymin;
		for (int yPos = 1;(yPos < yAnzahl);yPos++)
		{
			yAchse[yPos] = yAchse[yPos-1] + yStep;
		}
	}
	// Testausgabe
	//for (int y=0;y<yAnzahl;y++) cout << y << " " << yAchse[y] << endl;


	/* Ausgabe der Koordinatenachsen:
	   es werden immer die Achsen am Rand der Flaeche gezeichnet, weil dort die Einheiten stehen.
	   Wenn ein Vorzeichenwechsel vorliegt, wird die jeweilige Achse zusätzlich eingezeichnet. 
	*/

	// x-Achse am unteren Rand für Beschriftung immer ausgeben
	if(xVorzWechsel)
	{
		for(int x=xNullPos;x<xAnzahl;x++) 
			{
				Graphik[x][0] = (( ((x-xNullPos)%10)==0) && (x!=0)) ? '+' : '-';	
			}
		for(int x=xNullPos;x>=0;x--) 
			{
				Graphik[x][0] = (( ((x-xNullPos)%10)==0) && (x!=0)) ? '+' : '-';	
			}
		Graphik[xAnzahl-1][0] = '>';
	}
	else
	{
		for(int x=0;x<xAnzahl;x++) 
		{
			Graphik[x][0] = (( (x%10)==0) && (x!=0)) ? '+' : '-';	
		}
		Graphik[xAnzahl-1][0] = '>';
	}

	// optional: x-Achse auch an der "richtigen" y-Position ausgeben
	if( (yNullPos > 0) && (yNullPos != (yAnzahl-1)) )
	{
		if(xVorzWechsel)
		{
			for(int x=xNullPos;x<xAnzahl;x++) 
				{
					Graphik[x][yNullPos] = (( ((x-xNullPos)%10)==0) && (x!=0)) ? '+' : '-';	
				}
			for(int x=xNullPos;x>=0;x--) 
				{
					Graphik[x][yNullPos] = (( ((x-xNullPos)%10)==0) && (x!=0)) ? '+' : '-';	
				}
			//Graphik[xAnzahl-1][yNullPos] = '>';
		}
		else
		{
			for(int x=0;x<xAnzahl;x++) 
			{
				Graphik[x][yNullPos] = (( (x%10)==0) && (x!=0)) ? '+' : '-';	
			}
			//Graphik[xAnzahl-1][yNullPos] = '>';
		}

	}

	// y-Achse am linken Rand für Beschriftung immer ausgeben
	if(yVorzWechsel)
	{
		for(int y=yNullPos;y<yAnzahl;y++) 
			{
				Graphik[0][y] = (( ((y-yNullPos)%10)==0) && (y!=0)) ? '+' : '|';
			}
		for(int y=yNullPos;y>=0;y--) 
			{
				Graphik[0][y] = (( ((y-yNullPos)%10)==0) && (y!=0)) ? '+' : '|';
			}
		Graphik[0][yAnzahl-1] = '^';
	}
	else
	{
		for(int y=0;y<yAnzahl;y++) 
		{
			Graphik[0][y] = (( ((y)%10)==0) && (y!=0)) ? '+' : '|';
		}
		Graphik[0][yAnzahl-1] = '^';
	}

	// optional: y-Achse an der "richtigen" x-Position ausgeben
	if( (xNullPos > 0) && (xNullPos != xAnzahl-1) )
	{
		if(yVorzWechsel)
		{
			for(int y=yNullPos;y<yAnzahl;y++) 
				{
					Graphik[xNullPos][y] = (( ((y-yNullPos)%10)==0) && (y!=0)) ? '+' : '|';
				}
			for(int y=yNullPos;y>=0;y--) 
				{
					Graphik[xNullPos][y] = (( ((y-yNullPos)%10)==0) && (y!=0)) ? '+' : '|';
				}
			Graphik[xNullPos][yAnzahl-1] = '^';
		}
		else
		{
			for(int y=0;y<yAnzahl;y++) 
			{
				Graphik[xNullPos][y] = (( ((y)%10)==0) && (y!=0)) ? '+' : '|';
			}
			Graphik[xNullPos][yAnzahl-1] = '^';
		}

	}

	/* Befüllen der Zeichenfläche
	   bfuellen = false => nur die Kurve
	   bFuellen = true => Flaeche zur x-Achse  
	*/

	int y = 0;
	bool toPaint = true;

	if(yVorzWechsel)
	{
		for(int x=0;x<xAnzahl;x++)
		{
			// Werte oberhalb der x-Achse
			y = 0;
			toPaint = true;
			y = yNullPos;

			while(toPaint && (y < yAnzahl))
			{
				if ( (yWerte[x] >= 0) && abs(yWerte[x]-yAchse[y]) < abs(yWerte[x]-yAchse[y+1]) )
					{
						Graphik[x][y] = symbol;
						toPaint = false;
						if(bFuellen) for(int y2=yNullPos;(y2<y);y2++) Graphik[x][y2] = symbol;
					}
				y++;
			};

			// Werte unterhalb der x-Achse
			toPaint = true;
			y = 0;

			while(toPaint && (y <= yNullPos))
			{
				if ( (yWerte[x] <= 0) && (abs(abs(yWerte[x])-abs(yAchse[y])) < abs(abs(yWerte[x])-abs(yAchse[y+1]))))
					{
						Graphik[x][y] = symbol;
						toPaint = false;
						if(bFuellen) for(int y2=y+1;(y2<yNullPos);y2++) Graphik[x][y2] = symbol;
					}
				y++;
			};
		}
	}
	else
	{
		for(int x=0;x<xAnzahl;x++)
		{		
			toPaint = true;
			y = 0;
	
			while(toPaint && (y < yAnzahl))
			{
				if ( abs(abs(yWerte[x])-abs(yAchse[y])) < abs(abs(yWerte[x])-abs(yAchse[y+1])) )
				{
					Graphik[x][y] = symbol;
					toPaint = false;
					if(bFuellen) 
					{
						if(ymax < 0)
						{
							for(int y2=y+1;(y2<yAnzahl);y2++) Graphik[x][y2] = symbol;
						}
						else
						{
							for(int y2=y-1;(y2>=0);y2--) Graphik[x][y2] = symbol;
						}
					}
				}
			y++;
			}
		}
	}

	/**************************
	 Ausgabe der Zeichenflaeche
	 **************************/

	// maximale y-Werte zuerst
	cout << "\n" << endl;
	for(int y=yAnzahl-1;y>=0;y--)
	{
		// Bschriftung der y-Achse ausgeben
		if( (y == 0) || (y == yAnzahl-1) || (y == yNullPos) )
		{
			cout << setw(xOffset-2) << right << setprecision(2) << fixed << yAchse[y] << " ";
		}
		else
		{
			cout << setw(xOffset-1) << " ";
		}

		// Zeichenfläche ausgeben
		for(int x=0;x<xAnzahl;x++)
		{
			cout << Graphik[x][y];
		}
		cout << endl;
	}

	// Beschriftung der x-Achse ausgeben
	cout << setw(xOffset) << " " ;
	for (int x=0;x<xAnzahl;x++)
	{
		if ( (x == 0) || (x == (xNullPos)) || (x == xAnzahl-1) )
		{
			cout << "\b\b\b" << setw(5) << left << setprecision(2) << fixed << xWerte[x]; 
		}
		else
		{
			cout << setw(1) << " " ; 
		}
	}
	cout << "\n\n" << endl;


	// Ausgabe der Parameter
	cout << "Zeichenparameter:" 
		 << "\n-----------------" 
		 << "\nAnzahl x-Werte = " << setw(6) << right << xAnzahl 
		 << "\nxmin =           " << setw(6) << setprecision(2) << fixed << xWerte[0] 
		 << "\nxmax =           " << setw(6) << xWerte[xAnzahl-1] 
		 << "\nAnzahl y-Werte = " << setw(6) << right << yAnzahl 
		 << "\nymin =           " << setw(6) << setprecision(2) << fixed << ymin 
		 << "\nymax =           " << setw(6) << ymax 
		 << "\n\n" << endl;

	/*
	// Kontroll-Ausgaben ("dirty debugging")
	cout << "Kontrolle:" 
	     << "\nxVorzeichenwechel: " << boolalpha << xVorzWechsel 
		 << "\nNull in x = " << xNullPos-xOffset 
		 << "\nyVorzeichenwechel: " << boolalpha << yVorzWechsel 
		 << "\nNull in y = " << yNullPos 
		 << "\n" << endl;
	*/ 

	return;
 }