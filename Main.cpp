#include<iostream>
#include<string.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include"App/Mapa/Mapa.h"
#include"App/Moeda/Moeda.h"
#include"App/Pacman/Pacman.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

/*----------------- File: Main.cpp ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Laura Arakaki" em 14/06/2022|
+-----------------------------------------------------+ */


void rewrite(Mapa mapa[]){
    for(int i = 0; i < 368; i++){
        mapa[i].imprimeImagem();
    }

    al_flip_display();
    al_draw_bitmap(al_load_bitmap("../Imagens/background.jpg"),0,0,0);
}

int main(){

    ALLEGRO_DISPLAY *display = NULL; //Tela
    ALLEGRO_BITMAP  *image   = NULL; //Imagem

   if(!al_init()) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   //Cria uma tela com essas dimensoes
   display = al_create_display(800,600);

   if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   //Funções teclado
   al_install_keyboard();

   //Carrega a Imagem de background
   /*image = al_load_bitmap("Imagens/background.jpg");

   if(!image) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao carregar a imagem!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }*/

    int m = 0, c = 0, pac = 0;
    int matriz[19][21] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
        1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,1,
        1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
        1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
        1,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,0,1,
        1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,
        1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };

    Mapa *mapa = new Mapa[368];
    Moeda *moeda = new Moeda[362];
    Pacman *pacman = new Pacman;

    //char image1[] = "../../Others/Imagens/mario-right.png";
    //char image2[] = "../../Others/Imagens/mario-left.png";

    ALLEGRO_BITMAP *imagem1 = NULL;
    ALLEGRO_BITMAP *imagem2 = NULL;


    imagem1 = al_load_bitmap("Imagens/mario-left.png");
    imagem2 = al_load_bitmap("Imagens/mario-right.png");

    printf("passei aqui");
    if(imagem1 == NULL || imagem2 == NULL){
        printf("NULL");
    }

    for(int i=0; i<19; i++){
        for(int j=0; j<21; j++){
            if(matriz[i][j] == 1){
                mapa[m++].setPos(j*25, i*25);
            }else if (matriz[i][j] == 0){
                moeda[c++].setPos(j*25, i*25);
            }else if(matriz[i][j] == 2){
                pacman[pac].setImagens(imagem1, imagem2);
                pacman[pac++].setPos(j*25, i*25);
            }
        }
    }


    for(int i = 0; i < 368; i++){
        mapa[i].imprimeImagem();
    }

    for(int i = 0; i < 362; i++){
        moeda[i].imprimeImagem();
    }

      //DESENHA PACMAN
    for(int i = 0; i < 1; i++){
        pacman[i].imprimeImagem(0);
    }

    al_flip_display();
    al_rest(5);

    for(int i=0; i<19; i++){
        for(int j=0; j<21; j++){
                mapa[m++].destroiImagem();
        }
    }


    return 0;
}
