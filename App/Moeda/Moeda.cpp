#include<iostream>
#include"Moeda.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>

/*----------------- File: Moeda.cpp ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por Laura Arakaki em 14/06/2022|
+-----------------------------------------------------+ */

using namespace std;

Moeda::Moeda(){
	this->imagem = NULL;
	this->pos_x = this->pos_y = -1;
}

Moeda::~Moeda(){
	al_destroy_bitmap(this->imagem);
}

void Moeda::setPos(int x, int y){
	al_init_image_addon();
	this->imagem = al_load_bitmap("coin.png");
	al_draw_bitmap(this->imagem, x, y, 0);
	this->pos_x = x;
	this->pos_y = y;
}

int Moeda::getPosX(){
	return this->pos_x;
}

int Moeda::getPosY(){
	return this->pos_y;
}

void Moeda::imprimeImagem(){
	al_draw_bitmap(this->imagem,this->pos_x,this->pos_y,0);

}

void Moeda::destroiImagem(){
	al_destroy_bitmap(this->imagem);
	this->imagem = NULL;
	this->pos_y = this->pos_x = -1;
}
