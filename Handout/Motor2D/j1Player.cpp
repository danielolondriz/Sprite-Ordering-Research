#include "j1Player.h"
#include "j1Input.h"

#include "p2Log.h"

bool j1Player::Start()
{

	texture = App->tex->Load("Sprites/Link_Sprites.png");

	//Walk
	{
		
		image.x = 0;
		image.y = 0;
		image.w = 30;
		image.h = 60;

	}
	return true;
}

bool j1Player::Update(float dt)
{

	idle = true;

	if (App->input->GetKey(SDL_SCANCODE_W)) {
		pos.y -=  0.4;
		curr_dir = up;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_A)) {
		pos.x -= 0.4;
		curr_dir = left;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_S)) {
		pos.y += 0.4;
		curr_dir = down;
		idle = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_D)) {
		pos.x +=0.4;
		curr_dir = right;
		idle = false;
	}

	// TODO 3 part 2 -- Call the method previously created.
	//globals PLAYER_STARTPOS_Y and PLAYER_HEIGHT may be of help for the priority.
	

	return true;
}

bool j1Player::PostUpdate()
{
	return true;
}

SDL_Rect j1Player::GetRect()
{
	return image;
}

// TODO 3 part 1 
// Create a method that adds the player sprites to the double ended queue.
//It must recieve the priority!!!


bool j1Player::CleanUp()
{
	if(texture != nullptr)
		App->tex->UnLoad(texture);

	return true;
}
