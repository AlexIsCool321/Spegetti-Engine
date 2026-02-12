#include <GL_Renderer/GL_Mesh.h>

#include <stdio.h>
#include <stdlib.h>

Mesh* PLUGIN_CreateMesh(void** args)
{
	Vertex* vertices;
	unsigned long vertices_size;
	unsigned long* indices;
	unsigned long indices_size;
	unsigned short shader;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : VERTICES IS NULL!\n");
		if (!args[1]) printf("ERROR [PLUGIN] : VERTICES SIZE IS NULL!\n");
		if (!args[2]) printf("ERROR [PLUGIN] : INDICES IS NULL!\n");
		if (!args[3]) printf("ERROR [PLUGIN] : INDICES SIZE IS NULL!\n");
		if (!args[4]) printf("ERROR [PLUGIN] : SHADER IS NULL!\n");
		
		if (!args[0] || !args[1] || !args[2] || !args[3] || !args[4]) return NULL;

		vertices		=	 (Vertex*)			args[0];
		vertices_size	=	*(unsigned long*)	args[1];
		indices			=	 (unsigned long*)	args[2];
		indices_size	=	*(unsigned long*)	args[3];
		shader			=	*(unsigned short*)	args[4];
	}

	GL_Mesh* result = (GL_Mesh*)malloc(sizeof(GL_Mesh));

	return (Mesh*)result;
}

void PLUGIN_DrawMesh(void** args)
{
	GL_Mesh* mesh;

	{
		if (!args[0]) printf("ERROR [PLUGIN] : MESH IS NULL!\n");

		if (!args[0]) return;

		mesh	=	 (GL_Mesh*)	args[0];
	}

	
}

void PLUGIN_DestroyMesh(void** args)
{
	GL_Mesh* mesh;

	{
		if (!args[0]) printf("WARN [PLUGIN] : Mesh is already NULL.\n");

		if (!args[0]) return;

		mesh	=	 (GL_Mesh*)	args[0];
	}

	free(mesh);
	mesh = NULL;
}