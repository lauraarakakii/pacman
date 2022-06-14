#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

/*----------------- File: Personagem.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por Laura Arakaki em 14/06/2022|
+-----------------------------------------------------+ */

class Personagem {

	private:

		int pos_x, pos_y;
		int teclaD, direcao;


	public:
	    ALLEGRO_BITMAP* imagem[2];
		void destroiImagem();
		void setPos(int, int);
		int getPosX();
		int getPosY();
		void setPosX(int);
		void setPosY(int);
		void imprimeImagem(int);
		void setImagens(ALLEGRO_BITMAP* , ALLEGRO_BITMAP*);

		void setTeclaD(int);
		int getTeclaD();

		void setDirecao(int);
		int getDirecao();

		virtual void move(int[][21]) = 0;

		Personagem();
		virtual ~Personagem();
};

#endif
