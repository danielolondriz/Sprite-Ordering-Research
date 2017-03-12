#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Player.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->Load("map.tmx");
	
	SDL_Texture* ItemTex = App->tex->Load("Sprites/Entities.png");

	Zelda = App->ent->CreateEntity();
	Enemy = App->ent->CreateEntity();
	turret = App->ent->CreateEntity();
	Rupee = App->ent->CreateEntity();
	sign = App->ent->CreateEntity();
	chest = App->ent->CreateEntity();

	Zelda->SetTexture(ItemTex);
	Enemy->SetTexture(ItemTex);
	turret->SetTexture(ItemTex);
	Rupee->SetTexture(ItemTex);
	sign->SetTexture(ItemTex);
	chest->SetTexture(ItemTex);

	Zelda->SetTexRect(0, 0, 32, 60);
	Enemy->SetTexRect(32, 0, 32, 60);
	turret->SetTexRect(66, 0, 36, 65);
	Rupee->SetTexRect(100, 35, 30, 30);
	sign->SetTexRect(136, 0, 32, 32);
	chest->SetTexRect(168,0,32,32);
	Zelda->pos = { 100, 200 };
	Enemy->pos = { 100, 100 };
	turret->pos = { 350, 250 };
	Rupee->pos = { 200, 200 };
	sign->pos = { 150,450 };
	chest->pos = { 150,150 };
	App->player->pos.x = 0;
	App->player->pos.y = 0;

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	

	App->map->Draw();

	App->win->SetTitle("Handout - Sprite Ordering - Daniel Olondriz");


	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
