#include <MGL_Renderer/Mesh.h>

#include <Renderer/Mesh.h>
#include <Renderer/Camera.h>

#include <Math/Tranform.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <glad/gl.h>

void* PLUGIN_CreateMesh(void** pArgs)
{
	Vertex* pVertices;
	unsigned int pVertexSize;
	unsigned int* pIndices;
	unsigned int pIndicesSize;
	unsigned int pShader;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : VERTICES IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : VERTICES SIZE IS NULL!\n");

		if (!pArgs[2]) printf("ERROR [PLUGIN] : INDICES IS NULL!\n");
		if (!pArgs[3]) printf("ERROR [PLUGIN] : INDICES SIZE IS NULL!\n");

		if (!pArgs[4]) printf("ERROR [PLUGIN] : SHADER IS NULL!\n");

		if (!pArgs[0] || !pArgs[1] || !pArgs[2] || !pArgs[3] || !pArgs[4]) return NULL;


		pVertices	=	 (Vertex*)pArgs[0];
		pVertexSize	=	*(unsigned int*)pArgs[1];

		pIndices		=	 (unsigned int*)pArgs[2];
		pIndicesSize	=	*(unsigned int*)pArgs[3];

		pShader = *(unsigned int*)pArgs[4];
	}

	MGL_Mesh* result = (MGL_Mesh*)malloc(sizeof(MGL_Mesh));

	result->m_shader = pShader;

	glGenBuffers(1, &result->m_VBO);
	glGenBuffers(1, &result->m_EBO);
	glGenVertexArrays(1, &result->m_VAO);

	glBindVertexArray(result->m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, result->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, pVertexSize * sizeof(Vertex), &pVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result->m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, pIndicesSize * sizeof(unsigned int), &pIndices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	glBindVertexArray(0);

	return result;
}

void PLUGIN_DrawMesh(void** pArgs)
{
	MGL_Mesh* pMesh;
	Camera* pCamera;

	{
		if (!pArgs[0]) printf("ERROR [PLUGIN] : MESH IS NULL!\n");
		if (!pArgs[1]) printf("ERROR [PLUGIN] : CAMERA IS NULL!\n");
	
		if (!pArgs[0] || !pArgs[1]) return;

		pMesh = (MGL_Mesh*)pArgs[0];
		pCamera = (Camera*)pArgs[1];
	}

	glUseProgram(pMesh->m_shader);

	Matrix view = CreateTransform(pCamera->position, pCamera->rotation, Vector3(1, 1, 1));

	glUniformMatrix4fv(glGetUniformLocation(pMesh->m_shader, "uView"), 1, GL_FALSE, view.m_values);
	glUniformMatrix4fv(glGetUniformLocation(pMesh->m_shader, "uProjection"), 1, GL_FALSE, pCamera->m_projection.m_values);

	glBindVertexArray(pMesh->m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void PLUGIN_DestroyMesh(void** pArgs)
{
	MGL_Mesh* pMesh;

	{
		if (!pArgs[0]) printf("WARN [PLUGIN] : Mesh is NULL!\n");
	
		if (!pArgs[0]) return;

		pMesh = (MGL_Mesh*)pArgs[0];
	}

	glDeleteBuffers(1, &pMesh->m_VBO);
	glDeleteVertexArrays(1, &pMesh->m_VAO);
	
	free(pMesh);
}