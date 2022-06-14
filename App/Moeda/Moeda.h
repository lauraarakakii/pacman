#ifndef MOEDA_H
#define MOEDA_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

/*----------------- File: Moeda.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por Laura Arakaki em 14/06/2022|
+-----------------------------------------------------+ */

class Moeda {
	private:
		int pos_x, pos_y;
	public:
        ALLEGRO_BITMAP* imagem;

        Moeda();
		~Moeda();

        void setPos(int, int);
		void destroiImagem();
		void imprimeImagem();
		int getPosX();
		int getPosY();
};

#endif
