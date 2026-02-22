#include <System/Renderer.h>

#include <Renderer/Shader.h>

#include <System/SearchPath.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processNode(Mesh** pMeshes, uint8_t* pMeshCount, C_STRUCT aiNode *node, const C_STRUCT aiScene *scene);
Mesh* processMesh(C_STRUCT aiMesh* pMesh, const C_STRUCT aiScene* pScene);

unsigned int LoadShader(const char* pType)
{
	const char* vertex;
	const char* fragment;

	char path[512];

	sprintf(path, "shaders/%s.vs", pType);
	vertex = ReadFile(path);
	if (!vertex)
	{
		printf("ERROR : FAILED TO READ VERTEX FILE!\n");
		return 0;
	}

	sprintf(path, "shaders/%s.fs", pType);
	fragment = ReadFile(path);
	if (!fragment)
	{
		printf("ERROR : FAILED TO READ FRAGMENT FILE!\n");
		return 0;
	}

	return CreateShader(vertex, fragment);
}


Model* LoadModel(const char* pName, const char* pFormat)
{
	char path[512];

	sprintf(path, "models/%s.%s", pName, pFormat);
	size_t size;
	void* modelSource = ReadBinary(path, &size);

	if (!modelSource)
	{
		printf("ERROR : FAILED TO OPEN MODEL FILE! : [ %s ]\n", pName);
		return NULL;
	}

	Mesh* meshes[MAX_MESH_COUNT];
	uint8_t meshCount = 0;
	
	const C_STRUCT aiScene* scene = aiImportFileFromMemory(modelSource, size, aiProcess_Triangulate | aiProcess_FlipUVs, pFormat);
	if (!scene)
	{
		printf("ERROR : FAILED TO PARSE MODEL [ %s ]! [ %s ]\n", pName, aiGetErrorString());

		return NULL;
	}

	C_STRUCT aiNode* rootNode = scene->mRootNode;

	processNode(meshes, &meshCount, rootNode, scene);

	aiReleaseImport(scene);

	Mesh* modelMeshes[meshCount];
	for (uint8_t i = 0; i < meshCount; i++)
	{
		modelMeshes[i] = meshes[i];
	}

	return CreateModel(modelMeshes, meshCount);
}

void processNode(Mesh** pMeshes, uint8_t* pMeshCount, C_STRUCT aiNode* pNode, const C_STRUCT aiScene* pScene)
{
	for (unsigned int i = 0; i < pNode->mNumMeshes; i++)
	{
		unsigned int nodeMesh =  pNode->mMeshes[i];
		C_STRUCT aiMesh** meshes = pScene->mMeshes;

		C_STRUCT aiMesh* mesh = meshes[nodeMesh];

		Mesh* Rmesh = processMesh(mesh, pScene);
		pMeshes[*pMeshCount] = Rmesh;
		(*pMeshCount)++;
	}

	for(unsigned int i = 0; i < pNode->mNumChildren; i++)
	{
		processNode(pMeshes, pMeshCount, pNode->mChildren[i], pScene);
	}
}

Mesh* processMesh(C_STRUCT aiMesh* pMesh, const C_STRUCT aiScene* pScene)
{
	Vertex vertices[pMesh->mNumVertices];
	unsigned int indices[pMesh->mNumFaces * 3];
	unsigned int indicesIndex = 0;

	for(unsigned int i = 0; i < pMesh->mNumVertices; i++)
	{
		Vertex* vertex = &vertices[i];
		
		vertex->position.x = pMesh->mVertices[i].x;
		vertex->position.y = pMesh->mVertices[i].y;
		vertex->position.z = pMesh->mVertices[i].z;

		if(pMesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
		{
			vertex->uv.x = pMesh->mTextureCoords[0][i].x; 
			vertex->uv.y = pMesh->mTextureCoords[0][i].y;
		}
	}
	
	for (unsigned int i = 0; i < pMesh->mNumFaces; i++)
	{
		C_STRUCT aiFace face = pMesh->mFaces[i];

		for(unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indicesIndex++;
			indices[indicesIndex - 1] = face.mIndices[j];
		}
	}

	Texture texture = CreateTexture(0, 0, NULL, 0, 0, 0);
	BindTexture(&texture);

	unsigned int shader = LoadShader("pbr");
	SetTextureUniform(shader, "color", &texture);

	return CreateMesh(vertices, pMesh->mNumVertices, indices, pMesh->mNumFaces * 3, shader);
}