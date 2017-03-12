#ifndef __J1PLAYER_H__
#define __J1PLAYER_H__

#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "Animation.h"








#define PLAYER_STARTPOS_Y 0
#define PLAYER_HEIGHT 60

enum directions {
	up = 0,
	down,
	left,
	right,
	__LAST
};

class j1Player : public j1Module {

public:
	fPoint pos;
	directions curr_dir;
	SDL_Rect image;
private:
	bool idle = true;

	SDL_Texture* texture;
	

public:
	j1Player() {};
	virtual ~j1Player() {
		if (texture != nullptr)
			App->tex->UnLoad(texture);
	};

public:
	bool Start();
	bool Update(float dt);
	bool PostUpdate();

	SDL_Rect GetRect();

	// TODO 3 part 1
	// Create a method that adds the player sprites to the double ended queue
	//It must recieve the priority!!!


	bool CleanUp();

};

#endif