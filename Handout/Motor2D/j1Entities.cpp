#include "j1Entities.h"
#include "j1Render.h"
#include "j1Player.h"
#include "p2Log.h"

bool j1EntityManager::PostUpdate()
{
	// TODO 6  Lets set a priority for every entity.
	//Iterate the list
	//Set the priority the same way we did with the player
	

	return true;
}

bool j1EntityManager::Update(float dt)
{
	for (std::list<Entity*>::iterator tmp = entities.begin(); tmp != entities.end(); tmp++) {
		tmp._Ptr->_Myval->Update();
	}

	return true;
}

bool j1EntityManager::CleanUp()
{
	DeleteEntities();

	return true;
}

Entity* j1EntityManager::CreateEntity()
{
	Entity* ent = nullptr;

	ent = new Entity();

	entities.push_back(ent);

	return ent;
}

void j1EntityManager::DeleteEntities()
{
	if(entities.size() != 0)
		for (std::list<Entity*>::iterator tmp = entities.begin();tmp == entities.end();tmp++) {
			if (tmp._Ptr != nullptr) {
				delete tmp._Ptr->_Myval;
			}
		}
}

void Entity::Update()
{
		
}

void Entity::SetTexture(SDL_Texture * tex)
{
	texture = tex;
}

void Entity::SetTexRect(int x, int y, int w, int h)
{
	rect = { x, y, w, h };
}

// TODO 4 -- Create the same method but with entities!

