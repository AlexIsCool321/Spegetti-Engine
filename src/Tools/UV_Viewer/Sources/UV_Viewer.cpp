#include <UV_Viewer.h>

// Remove Console
#ifdef _WIN32
#include <Windows.h>

int main();

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}

#endif // _WIN32

bool running = true;

int main()
{
	std::string model_path;
	std::string texture_path;

	model_path = "engine/models/crowbar.obj";
	texture_path = "engine/textures/crowbar/albedo.png";

	Init_Spegetti_Renderer();




	// World
	Window World_View = Window("World View", 800, 600);
	World_View.Set_Icon("bin/UV_Viewer.png");

	Camera World_Camera = Camera(Camera::Perspective, 90.0f, &World_View, 0.01f, 500.0f);

	Material world_material = Material();
	Texture world_albedo = Texture(texture_path.c_str(), Texture::Repeat, Texture::Linear);

	Model world_model = Model(model_path.c_str());

	world_model.Set_Material(&world_material);
	world_material.Set_Texture("albedo", &world_albedo);

	World_Camera.Add_To_Draw_Stack(&world_model);




	// UV
	Window UV_View = Window("UV View", 800, 600);
	UV_View.Set_Icon("bin/UV_Viewer.png");

	Camera UV_Camera = Camera(Camera::Perspective, 90.0f, &UV_View, 0.01f, 500.0f);
	//UV_Camera.Change_Draw_Mode(Wireframe);

	Material uv_material = Material();
	Texture uv_albedo = Texture(texture_path.c_str(), Texture::Repeat, Texture::Linear);

	Mesh uv_mesh = Load_Model_UV(model_path.c_str());
	Model uv_model = Model();
	uv_model.Add_Mesh(uv_mesh);

	uv_model.Set_Material(&uv_material);
	uv_material.Set_Texture("albedo", &uv_albedo);

	UV_Camera.Add_To_Draw_Stack(&uv_model);



	while (running)
	{
		Update_Delta();


		// World
		World_View.Push_Context();
		World_View.Update();

		FreeCam(&World_Camera, &World_View);

		World_Camera.Draw(&World_View);

		if (World_View.Should_Close()) running = false;




		// UV
		UV_View.Push_Context();
		UV_View.Update();

		//FreeCam(&UV_Camera, &UV_View);

		UV_Camera.Draw(&UV_View);

		if (UV_View.Should_Close()) running = false;
	}

	Quit_Spegetti_Renderer();
	
	return 0;
}