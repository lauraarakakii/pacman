#include<iostream>
#include"Pacman.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Pacman::Pacman(){
}

Pacman::~Pacman(){
}

void Pacman::waitEvent(ALLEGRO_EVENT_QUEUE* fila_eventos){
	al_wait_for_event(fila_eventos,&(this->evento));
}

ALLEGRO_EVENT Pacman::getEvent(){
	return (this->evento);
}

bool Pacman::eventKeyDown(){
	return ((this->evento).type == ALLEGRO_EVENT_KEY_DOWN);
}

bool Pacman::eventKeyUp(){
	return ((this->evento).type == ALLEGRO_EVENT_KEY_UP);
}

bool Pacman::eventCloseDisplay(){
	return ((this->evento).type == ALLEGRO_EVENT_DISPLAY_CLOSE);
}

bool Pacman::eventEscape(){
	return ((this->evento).keyboard.keycode == ALLEGRO_KEY_ESCAPE);
}

bool Pacman::eventTimer(){
	return ((this->evento).type == ALLEGRO_EVENT_TIMER);
}

void Pacman::move(int matriz[][21]){

	if(Personagem::getDirecao() == 1 && matriz[Personagem::getPosY()-1][Personagem::getPosX()] != 1){
		Personagem::setPosY(Personagem::getPosY() - 1);
		Personagem::setTeclaD(Personagem::getDirecao());
	}

	else if(Personagem::getDirecao() == 2 && matriz[Personagem::getPosY()+1][Personagem::getPosX()] != 1){
		Personagem::setPosY(Personagem::getPosY() + 1);
		Personagem::setTeclaD(Personagem::getDirecao());
	}

	else if(Personagem::getDirecao() == 3 && matriz[Personagem::getPosY()][Personagem::getPosX()-1] != 1){
		Personagem::setPosX(Personagem::getPosX() - 1);
		Personagem::setTeclaD(Personagem::getDirecao());
	}

	else if(Personagem::getDirecao() == 4 && matriz[Personagem::getPosY()][Personagem::getPosX()+1] != 1){
		Personagem::setPosX(Personagem::getPosX() + 1);
		Personagem::setTeclaD(Personagem::getDirecao());
	}

	else{
		if(Personagem::getTeclaD() == 1 && matriz[Personagem::getPosY()-1][Personagem::getPosX()] != 1){
			Personagem::setPosY(Personagem::getPosY() - 1);
		}

		else if(Personagem::getTeclaD() == 2 && matriz[Personagem::getPosY()+1][Personagem::getPosX()] != 1){
			Personagem::setPosY(Personagem::getPosY() + 1);
		}

		else if(Personagem::getTeclaD() == 3 && matriz[Personagem::getPosY()][Personagem::getPosX()-1] != 1){
			Personagem::setPosX(Personagem::getPosX() - 1);
		}

		else if(Personagem::getTeclaD() == 4 && matriz[Personagem::getPosY()][Personagem::getPosX()+1] != 1){
			Personagem::setPosX(Personagem::getPosX() + 1);
		}
	}
}
