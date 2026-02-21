#ifndef NOODLE_ENTITY_H
#define NOODLE_ENTITY_H

#include <Math/Vec3.h>

typedef struct
{
	Vec3 position;
	Vec3 rotation;
	Vec3 scale;

	const char* name;
	const char* type;
} Entity;

Entity* CreateEntity(const char* pName, const char* pType);

void UpdateEntity(Entity* pEntity);

void DestroyEntity(Entity* pEntity);

#endif