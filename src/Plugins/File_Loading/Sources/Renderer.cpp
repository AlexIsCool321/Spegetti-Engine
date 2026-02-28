#include <stdio.h>
#include <stdlib.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

extern "C"
{
	#include <File_Loading/Renderer.hpp>

	Shader* PLUGIN_LoadShader(void** pArgs)
	{
		const char* pType;

		{
			if (!pArgs[0]) printf("ERROR [PLUGIN] : TYPE IS NULL!\n");

			if (!pArgs[0]) return NULL;

			pType = *(const char**)pArgs[0];
		}


		const char* vertex;
		const char* fragment;

		char path[512];

		sprintf(path, "shaders/%s.vs", pType);
		vertex = ReadFile(path);
		if (!vertex)
		{
			printf("ERROR [PLUGIN] : FAILED TO READ VERTEX FILE!\n");
			return 0;
		}

		sprintf(path, "shaders/%s.fs", pType);
		fragment = ReadFile(path);
		if (!fragment)
		{
			printf("ERROR [PLUGIN] : FAILED TO READ FRAGMENT FILE!\n");
			return 0;
		}

		return CreateShader(vertex, fragment);
	}

	void processNode(Mesh** pMeshes, uint8_t* meshIndex, aiNode* pNode, const aiScene* pScene);
	Mesh* processMesh(aiMesh *mesh, const aiScene *scene);

	Model* PLUGIN_LoadModel(void** pArgs)
	{
		const char* pName;
		const char* pFormat;

		{
			if (!pArgs[0]) printf("ERROR [PLUGIN] : NAME IS NULL!\n");
			if (!pArgs[1]) printf("ERROR [PLUGIN] : FORMAT IS NULL!\n");

			if (!pArgs[0] || !pArgs[1]) return NULL;

			pName	= *(const char**)pArgs[0];
			pFormat	= *(const char**)pArgs[1];
		}


		char path[512];

		sprintf(path, "models/%s.%s", pName, pFormat);
		size_t size;
		
		void* modelSource = ReadBinary(path, &size);

		if (!modelSource)
		{
			printf("ERROR [PLUGIN] : FAILED TO OPEN MODEL FILE! : [ %s ]\n", pName);
			return NULL;
		}
		
		
		Assimp::Importer importer;
		
		const aiScene* scene = importer.ReadFileFromMemory(modelSource, size, aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace, pFormat);
		if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			printf("ERROR [PLUGIN] : FAILED TO PARSE MODEL [ %s ]! [ %s ]\n", pName, importer.GetErrorString());
			return NULL;
		}

		Mesh* meshes[scene->mNumMeshes];
		uint8_t meshIndex = 0;

		processNode(meshes, &meshIndex, scene->mRootNode, scene);

		return CreateModel(meshes, scene->mNumMeshes);
	}
}

void processNode(Mesh** pMeshes, uint8_t* meshIndex, aiNode* pNode, const aiScene* pScene)
{
	for(unsigned int i = 0; i < pNode->mNumMeshes; i++)
	{
		aiMesh* mesh = pScene->mMeshes[pNode->mMeshes[i]];
		pMeshes[*meshIndex] = processMesh(mesh, pScene);

		*meshIndex = *meshIndex + 1;
	}

	for(unsigned int i = 0; i < pNode->mNumChildren; i++)
	{
		processNode(pMeshes, meshIndex, pNode->mChildren[i], pScene);
	}
}

Mesh* processMesh(aiMesh* mesh, const aiScene *scene)
{
	unsigned int indiciesSize = 0;
	for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		indiciesSize += mesh->mFaces[i].mNumIndices;
	}

	unsigned int indices[indiciesSize];
	Vertex vertices[mesh->mNumVertices];


	for(unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex* vertex = &vertices[i];

		// Position
		vertex->position.x = mesh->mVertices[i].x;
		vertex->position.y = mesh->mVertices[i].y;
		vertex->position.z = mesh->mVertices[i].z;
		
		// UV
		if(mesh->mTextureCoords[0])
		{
			vertex->uv.x = mesh->mTextureCoords[0][i].x; 
			vertex->uv.y = mesh->mTextureCoords[0][i].y;
		}
		else
		{
			vertex->uv = Vector2(0, 0);
		}
	}

	unsigned int index = 0;
	for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];

		for(unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices[index] = face.mIndices[j];
			index++;
		}
	}

	Mesh* result = CreateMesh(vertices, mesh->mNumVertices, indices, indiciesSize, LoadShader("pbr"));
	return result;
}