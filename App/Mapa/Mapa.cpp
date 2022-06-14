#include<iostream>
#include "Mapa.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>

using namespace std;

/*----------------- File: Mapa.cpp ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Laura Arakaki" em 05/06/2022|
+-----------------------------------------------------+ */


Mapa::Mapa(){
    this->imagem = NULL;
    this->pos_x = this->pos_y = -1;
}

Mapa::~Mapa(){
    al_destroy_bitmap(this->imagem);
}

void Mapa::setPos(int x, int y){
    al_init_image_addon();
    this->imagem = al_load_bitmap("Imagens/bloco.png");
    al_draw_bitmap(this->imagem, x, y, 0);
    this->pos_x = x;
    this->pos_y = y;
}

int Mapa::getPosX(){
    return this->pos_x;
}

int Mapa::getPosY(){
    return this->pos_y;
}

void Mapa::imprimeImagem(){
    al_draw_bitmap_region(this->imagem, 0, 0, 25, 25, this->pos_x, pos_y, 0);
}

void Mapa::destroiImagem(){
    al_destroy_bitmap(this->imagem);
    this->imagem = NULL;
    this->pos_y = this->pos_x = -1;
}
