#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#ifndef MAPA_h
#define MAPA_h

/*----------------- File: Mapa.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Laura Arakaki" em 05/06/2022|
+-----------------------------------------------------+ */

class Mapa {

private:

    int pos_x, pos_y;
public:
    ALLEGRO_BITMAP* imagem;
    Mapa();
    ~Mapa();
    void setPos(int, int);
    int getPosX();
    int getPosY();
    void imprimeImagem();
    void destroiImagem();
};

#endif // MAPA_H
