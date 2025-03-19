#include <UV_Viewer.h>

bool running = true;

int main()
{
	std::string model_path;
	std::string texture_path;

	model_path = "engine/models/cube.obj";
	texture_path = "engine/textures/cube/albedo.png";
	//std::cin >> model_path;
	//std::cin >> texture_path;

	Init_Spegetti_Renderer();




	// World
	Window World_View = Window("World View", 800, 600);

	Camera World_Camera = Camera(Perspective, 90.0f, &World_View, 0.01f, 500.0f);

	Material material = Material();

	Texture texture = Texture(texture_path.c_str(), Repeat, Closest);

	Model world_model = Model(model_path.c_str());

	world_model.Set_Material(material);
	material.Set_Texture("albedo", &texture);

	World_Camera.Add_Model_To_Draw_Stack(&world_model);




	// UV
	Window UV_View = Window("UV View", 800, 600);

	Camera UV_Camera = Camera(Perspective, 90.0f, &UV_View, 0.01f, 500.0f);
	//UV_Camera.Change_Draw_Mode(Wireframe);

	Mesh uv_mesh = Load_Model_UV(model_path.c_str());
	Model uv_model = Model();
	uv_model.Add_Mesh(uv_mesh);

	uv_model.Set_Material(material);
	material.Set_Texture("albedo", &texture);

	UV_Camera.Add_Model_To_Draw_Stack(&uv_model);



	while (running)
	{
		Update_Delta();


		// World
		World_View.Push_Context();
		World_View.Update();

		//FreeCam(&World_Camera, &World_View);

		World_Camera.Draw();

		if (World_View.Should_Close()) running = false;




		// UV
		UV_View.Push_Context();
		UV_View.Update();

		FreeCam(&UV_Camera, &UV_View);

		UV_Camera.Draw();

		if (UV_View.Should_Close()) running = false;
	}

	Quit_Spegetti_Renderer();
	
	return 0;
}