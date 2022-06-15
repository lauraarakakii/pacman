#include<iostream>
#include"Personagem.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

Personagem::Personagem(){
	this->imagem[0] = NULL;
	this->imagem[1] = NULL;
	this->pos_x = this->pos_y = this->teclaD = this->direcao = -1;
}

Personagem::~Personagem(){
	al_destroy_bitmap(this->imagem[0]);
	al_destroy_bitmap(this->imagem[1]);
}

void Personagem::setPos(int x, int y){
	this->pos_x = x;
	this->pos_y = y;
}

void Personagem::setPosX(int x){
	this->pos_x = x;
}

void Personagem::setPosY(int y){
	this->pos_y = y;
}

void Personagem::setImagens(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* img2){
	this->imagem[0] = img; //check if it is returning NULL
	this->imagem[1] = img2; //check if it is returning NULL
}

int Personagem::getPosX(){ return this->pos_x; }

int Personagem::getPosY(){
	return this->pos_y;
}


void Personagem::imprimeImagem(int direcao){
	if(direcao == 1 || direcao == 4)
		al_draw_bitmap_region(this->imagem[1], 0, 0, 25, 25, this->pos_x*25,this->pos_y*25,0);
	if(direcao == 2 || direcao == 3)
		al_draw_bitmap_region(this->imagem[0], 0, 0, 25, 25, this->pos_x*25,this->pos_y*25,0);
}

void Personagem::destroiImagem(){
	al_destroy_bitmap(this->imagem[0]);
	al_destroy_bitmap(this->imagem[1]);
	this->imagem[0] = NULL;
	this->imagem[1] = NULL;
	this->pos_y = this->pos_x = -1;
}


void Personagem::setTeclaD(int d){
	this->teclaD = d;
}

int Personagem::getTeclaD(){
	return this->teclaD;
}

void Personagem::setDirecao(int d){
	this->direcao = d;
}

int Personagem::getDirecao(){
	return this->direcao;
}
