#ifndef PACMAN_H
#define PACMAN_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "../Personagem/Personagem.h"

/*----------------- File: Pacman.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por Laura Arakaki em 14/06/2022|
+-----------------------------------------------------+ */

class Pacman : public Personagem {

	private:
		ALLEGRO_EVENT evento;
	public:

		void waitEvent(ALLEGRO_EVENT_QUEUE*);
		bool eventKeyDown();
		bool eventKeyUp();
		bool eventCloseDisplay();
		bool eventEscape();
		bool eventTimer();
		ALLEGRO_EVENT getEvent();

		virtual void move(int[][21]);

		Pacman();
		~Pacman();
};
#endif
