#include <Engine.h>
#include <thread>


// Remove Console
#ifdef _WIN32
#include <Windows.h>

int main();

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}

#endif // _WIN32

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Spegetti Engine", 800, 600);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.Get_Window(), true);

	ImGui_ImplOpenGL3_Init("#version 130");

	io.IniFilename = NULL;


	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 1000.0f);

	



	Material Arches_material				= Material();
	Material Bars_material					= Material();
	Material Big_Pot_material				= Material();
	Material Blue_Curtans_material			= Material();
	Material Blue_Gold_Curtains_material	= Material();
	Material Ceiling_material				= Material();
	Material Chains_material				= Material();
	Material Doors_material					= Material();
	Material Floor_material					= Material();
	Material Green_Curtains_material		= Material();
	Material Green_Gold_Curtains_material	= Material();
	Material Hook_material					= Material();
	Material Lion_Face_material				= Material();
	Material Lion_material					= Material();
	Material Pillers_material				= Material();
	Material Plants_material				= Material();
	Material Pot_Plants_material			= Material();
	Material Pots_material					= Material();
	Material Red_Curtains_material			= Material();
	Material Red_Gold_Curtains_material		= Material();
	Material Roof_material					= Material();
	Material Room_material					= Material();
	Material Top_Pillers_material			= Material();
	Material Upper_Pillers_material			= Material();

	Texture plant_albedo	= Texture("demo/models/Sponza/glTF/5061699253647017043.png", Texture::Repeat, Texture::Linear);
	Texture plant_normal	= Texture("demo/models/Sponza/glTF/8773302468495022225.jpg", Texture::Repeat, Texture::Linear);
	Texture plant_arm		= Texture("demo/models/Sponza/glTF/11872827283454512094.jpg", Texture::Repeat, Texture::Linear);
	
	Texture Bars_albedo	= Texture("demo/models/Sponza/glTF/4975155472559461469.jpg", Texture::Repeat, Texture::Linear);
	Texture Bars_normal	= Texture("demo/models/Sponza/glTF/2299742237651021498.jpg", Texture::Repeat, Texture::Linear);
	Texture Bars_arm	= Texture("demo/models/Sponza/glTF/3371964815757888145.jpg", Texture::Repeat, Texture::Linear);

	Texture pot_plant_albedo	= Texture("demo/models/Sponza/glTF/8006627369776289000.png", Texture::Repeat, Texture::Linear);
	Texture pot_plant_normal	= Texture("demo/models/Sponza/glTF/12501374198249454378.jpg", Texture::Repeat, Texture::Linear);
	Texture pot_plant_arm		= Texture("demo/models/Sponza/glTF/715093869573992647.jpg", Texture::Repeat, Texture::Linear);
	
	Texture pots_albedo	= Texture("demo/models/Sponza/glTF/7268504077753552595.jpg", Texture::Repeat, Texture::Linear);
	Texture pots_normal	= Texture("demo/models/Sponza/glTF/8503262930880235456.jpg", Texture::Repeat, Texture::Linear);
	Texture pots_arm	= Texture("demo/models/Sponza/glTF/4477655471536070370.jpg", Texture::Repeat, Texture::Linear);
	
	Texture lion_albedo	= Texture("demo/models/Sponza/glTF/8750083169368950601.jpg", Texture::Repeat, Texture::Linear);
	Texture lion_normal	= Texture("demo/models/Sponza/glTF/13982482287905699490.jpg", Texture::Repeat, Texture::Linear);
	Texture lion_arm	= Texture("demo/models/Sponza/glTF/16885566240357350108.jpg", Texture::Repeat, Texture::Linear);
	
	Texture lion_face_albedo	= Texture("demo/models/Sponza/glTF/6772804448157695701.jpg", Texture::Repeat, Texture::Linear);
	Texture lion_face_normal	= Texture("demo/models/Sponza/glTF/759203620573749278.jpg", Texture::Repeat, Texture::Linear);
	Texture lion_face_arm		= Texture("demo/models/Sponza/glTF/13196865903111448057.jpg", Texture::Repeat, Texture::Linear);
	
	Texture room_albedo	= Texture("demo/models/Sponza/glTF/5792855332885324923.jpg", Texture::Repeat, Texture::Linear);
	Texture room_normal	= Texture("demo/models/Sponza/glTF/16299174074766089871.jpg", Texture::Repeat, Texture::Linear);
	Texture room_arm	= Texture("demo/models/Sponza/glTF/11968150294050148237.jpg", Texture::Repeat, Texture::Linear);
	
	Texture arches_albedo	= Texture("demo/models/Sponza/glTF/14650633544276105767.jpg", Texture::Repeat, Texture::Linear);
	Texture arches_normal	= Texture("demo/models/Sponza/glTF/2051777328469649772.jpg", Texture::Repeat, Texture::Linear);
	Texture arches_arm		= Texture("demo/models/Sponza/glTF/4871783166746854860.jpg", Texture::Repeat, Texture::Linear);
	
	Texture ceiling_albedo	= Texture("demo/models/Sponza/glTF/15295713303328085182.jpg", Texture::Repeat, Texture::Linear);
	Texture ceiling_normal	= Texture("demo/models/Sponza/glTF/10388182081421875623.jpg", Texture::Repeat, Texture::Linear);
	Texture ceiling_arm		= Texture("demo/models/Sponza/glTF/9916269861720640319.jpg", Texture::Repeat, Texture::Linear);
	
	Texture roof_albedo	= Texture("demo/models/Sponza/glTF/2969916736137545357.jpg", Texture::Repeat, Texture::Linear);
	Texture roof_normal	= Texture("demo/models/Sponza/glTF/14118779221266351425.jpg", Texture::Repeat, Texture::Linear);
	Texture roof_arm	= Texture("demo/models/Sponza/glTF/8747919177698443163.jpg", Texture::Repeat, Texture::Linear);
	
	Texture pillers_albedo	= Texture("demo/models/Sponza/glTF/6047387724914829168.jpg", Texture::Repeat, Texture::Linear);
	Texture pillers_normal	= Texture("demo/models/Sponza/glTF/15722799267630235092.jpg", Texture::Repeat, Texture::Linear);
	Texture pillers_arm		= Texture("demo/models/Sponza/glTF/8051790464816141987.jpg", Texture::Repeat, Texture::Linear);
	
	Texture floor_albedo	= Texture("demo/models/Sponza/glTF/5823059166183034438.jpg", Texture::Repeat, Texture::Linear);
	Texture floor_normal	= Texture("demo/models/Sponza/glTF/14267839433702832875.jpg", Texture::Repeat, Texture::Linear);
	Texture floor_arm		= Texture("demo/models/Sponza/glTF/13824894030729245199.jpg", Texture::Repeat, Texture::Linear);
	
	Texture top_pillers_albedo	= Texture("demo/models/Sponza/glTF/7441062115984513793.jpg", Texture::Repeat, Texture::Linear);
	Texture top_pillers_normal	= Texture("demo/models/Sponza/glTF/6667038893015345571.jpg", Texture::Repeat, Texture::Linear);
	Texture top_pillers_arm		= Texture("demo/models/Sponza/glTF/8114461559286000061.jpg", Texture::Repeat, Texture::Linear);
	
	Texture door_albedo	= Texture("demo/models/Sponza/glTF/11490520546946913238.jpg", Texture::Repeat, Texture::Linear);
	Texture door_normal	= Texture("demo/models/Sponza/glTF/3628158980083700836.jpg", Texture::Repeat, Texture::Linear);
	Texture door_arm	= Texture("demo/models/Sponza/glTF/3455394979645218238.jpg", Texture::Repeat, Texture::Linear);
	
	Texture upper_piller_albedo	= Texture("demo/models/Sponza/glTF/6151467286084645207.jpg", Texture::Repeat, Texture::Linear);
	Texture upper_piller_normal	= Texture("demo/models/Sponza/glTF/7645212358685992005.jpg", Texture::Repeat, Texture::Linear);
	Texture upper_piller_arm	= Texture("demo/models/Sponza/glTF/8783994986360286082.jpg", Texture::Repeat, Texture::Linear);
	
	Texture green_curtain_albedo	= Texture("demo/models/Sponza/glTF/4675343432951571524.jpg", Texture::Repeat, Texture::Linear);
	Texture green_curtain_normal	= Texture("demo/models/Sponza/glTF/7056944414013900257.jpg", Texture::Repeat, Texture::Linear);
	Texture green_curtain_arm		= Texture("demo/models/Sponza/glTF/7815564343179553343.jpg", Texture::Repeat, Texture::Linear);
	
	Texture blue_curtain_albedo	= Texture("demo/models/Sponza/glTF/2775690330959970771.jpg", Texture::Repeat, Texture::Linear);
	Texture blue_curtain_normal	= Texture("demo/models/Sponza/glTF/2374361008830720677.jpg", Texture::Repeat, Texture::Linear);
	Texture blue_curtain_arm	= Texture("demo/models/Sponza/glTF/7815564343179553343.jpg", Texture::Repeat, Texture::Linear);
	
	Texture red_curtain_albedo	= Texture("demo/models/Sponza/glTF/2185409758123873465.jpg", Texture::Repeat, Texture::Linear);
	Texture red_curtain_normal	= Texture("demo/models/Sponza/glTF/332936164838540657.jpg", Texture::Repeat, Texture::Linear);
	Texture red_curtain_arm		= Texture("demo/models/Sponza/glTF/7815564343179553343.jpg", Texture::Repeat, Texture::Linear);
	
	Texture blue_gold_curtain_albedo	= Texture("demo/models/Sponza/glTF/17876391417123941155.jpg", Texture::Repeat, Texture::Linear);
	Texture blue_gold_curtain_normal	= Texture("demo/models/Sponza/glTF/6593109234861095314.jpg", Texture::Repeat, Texture::Linear);
	Texture blue_gold_curtain_arm		= Texture("demo/models/Sponza/glTF/466164707995436622.jpg", Texture::Repeat, Texture::Linear);

	Texture red_gold_curtain_albedo	= Texture("demo/models/Sponza/glTF/11474523244911310074.jpg", Texture::Repeat, Texture::Linear);
	Texture red_gold_curtain_normal	= Texture("demo/models/Sponza/glTF/4601176305987539675.jpg", Texture::Repeat, Texture::Linear);
	Texture red_gold_curtain_arm	= Texture("demo/models/Sponza/glTF/466164707995436622.jpg", Texture::Repeat, Texture::Linear);
	
	Texture green_gold_curtain_albedo	= Texture("demo/models/Sponza/glTF/9288698199695299068.jpg", Texture::Repeat, Texture::Linear);
	Texture green_gold_curtain_normal	= Texture("demo/models/Sponza/glTF/4910669866631290573.jpg", Texture::Repeat, Texture::Linear);
	Texture green_gold_curtain_arm		= Texture("demo/models/Sponza/glTF/466164707995436622.jpg", Texture::Repeat, Texture::Linear);
	
	Texture chain_albedo	= Texture("demo/models/Sponza/glTF/16275776544635328252.png", Texture::Repeat, Texture::Linear);
	Texture chain_normal	= Texture("demo/models/Sponza/glTF/14170708867020035030.jpg", Texture::Repeat, Texture::Linear);
	Texture chain_arm		= Texture("demo/models/Sponza/glTF/1219024358953944284.jpg", Texture::Repeat, Texture::Linear);
	
	Texture hook_albedo	= Texture("demo/models/Sponza/glTF/755318871556304029.jpg", Texture::Repeat, Texture::Linear);
	Texture hook_normal	= Texture("demo/models/Sponza/glTF/3827035219084910048.jpg", Texture::Repeat, Texture::Linear);
	Texture hook_arm	= Texture("demo/models/Sponza/glTF/2411100444841994089.jpg", Texture::Repeat, Texture::Linear);
	
	Texture big_pot_albedo	= Texture("demo/models/Sponza/glTF/8481240838833932244.jpg", Texture::Repeat, Texture::Linear);
	Texture big_pot_normal	= Texture("demo/models/Sponza/glTF/10381718147657362067.jpg", Texture::Repeat, Texture::Linear);
	Texture big_pot_arm		= Texture("demo/models/Sponza/glTF/17556969131407844942.jpg", Texture::Repeat, Texture::Linear);


	Model Arches				= Model("demo/models/Sponza/Arches.obj");
	Model Bars					= Model("demo/models/Sponza/Bars.obj");
	Model Big_Pot				= Model("demo/models/Sponza/Big Pot.obj");
	Model Blue_Curtans			= Model("demo/models/Sponza/Blue Curtans.obj");
	Model Blue_Gold_Curtains	= Model("demo/models/Sponza/Blue Gold Curtans.obj");
	Model Ceiling				= Model("demo/models/Sponza/Ceiling.obj");
	Model Chains				= Model("demo/models/Sponza/Chains.obj");
	Model Doors					= Model("demo/models/Sponza/Doors.obj");
	Model Floor					= Model("demo/models/Sponza/Floor.obj");
	Model Green_Curtains		= Model("demo/models/Sponza/Green Curtans.obj");
	Model Green_Gold_Curtains	= Model("demo/models/Sponza/Green Gold Curtans.obj");
	Model Hook					= Model("demo/models/Sponza/Hook.obj");
	Model Lion_Face				= Model("demo/models/Sponza/Lion Face.obj");
	Model Lion					= Model("demo/models/Sponza/Lion.obj");
	Model Pillers				= Model("demo/models/Sponza/Pillers.obj");
	Model Plants				= Model("demo/models/Sponza/Plants.obj");
	Model Pot_Plants			= Model("demo/models/Sponza/Pot Plants.obj");
	Model Pots					= Model("demo/models/Sponza/Pots.obj");
	Model Red_Curtains			= Model("demo/models/Sponza/Red Curtans.obj");
	Model Red_Gold_Curtains		= Model("demo/models/Sponza/Red Gold Curtans.obj");
	Model Roof					= Model("demo/models/Sponza/Roof.obj");
	Model Room					= Model("demo/models/Sponza/Room.obj");
	Model Top_Pillers			= Model("demo/models/Sponza/Top Pillers.obj");
	Model Upper_Pillers			= Model("demo/models/Sponza/Uper Pillers.obj");

	Arches.Set_Material(&Arches_material);
	Bars.Set_Material(&Bars_material);
	Big_Pot.Set_Material(&Big_Pot_material);
	Blue_Curtans.Set_Material(&Blue_Curtans_material);
	Blue_Gold_Curtains.Set_Material(&Blue_Gold_Curtains_material);
	Ceiling.Set_Material(&Ceiling_material);
	Chains.Set_Material(&Chains_material);
	Doors.Set_Material(&Doors_material);
	Floor.Set_Material(&Floor_material);
	Green_Curtains.Set_Material(&Green_Curtains_material);
	Green_Gold_Curtains.Set_Material(&Green_Gold_Curtains_material);
	Hook.Set_Material(&Hook_material);
	Lion_Face.Set_Material(&Lion_Face_material);
	Lion.Set_Material(&Lion_material);
	Pillers.Set_Material(&Pillers_material);
	Plants.Set_Material(&Plants_material);
	Pot_Plants.Set_Material(&Pot_Plants_material);
	Pots.Set_Material(&Pots_material);
	Red_Curtains.Set_Material(&Red_Curtains_material);
	Red_Gold_Curtains.Set_Material(&Red_Gold_Curtains_material);
	Roof.Set_Material(&Roof_material);
	Room.Set_Material(&Room_material);
	Top_Pillers.Set_Material(&Top_Pillers_material);
	Upper_Pillers.Set_Material(&Upper_Pillers_material);


	Arches_material.Set_Texture("albedo",	&arches_albedo);
	Arches_material.Set_Texture("normal",	&arches_normal);
	Arches_material.Set_Texture("arm",		&arches_arm);

	Bars_material.Set_Texture("albedo",		&Bars_albedo);
	Bars_material.Set_Texture("normal",		&Bars_normal);
	Bars_material.Set_Texture("arm",		&Bars_arm);

	Big_Pot_material.Set_Texture("albedo",	&big_pot_albedo);
	Big_Pot_material.Set_Texture("normal",	&big_pot_normal);
	Big_Pot_material.Set_Texture("arm",		&big_pot_arm);

	Blue_Curtans_material.Set_Texture("albedo",	&blue_curtain_albedo);
	Blue_Curtans_material.Set_Texture("normal",	&blue_curtain_normal);
	Blue_Curtans_material.Set_Texture("arm",	&blue_curtain_arm);

	Blue_Gold_Curtains_material.Set_Texture("albedo",	&blue_gold_curtain_albedo);
	Blue_Gold_Curtains_material.Set_Texture("normal",	&blue_gold_curtain_normal);
	Blue_Gold_Curtains_material.Set_Texture("arm",		&blue_gold_curtain_arm);

	Ceiling_material.Set_Texture("albedo",	&ceiling_albedo);
	Ceiling_material.Set_Texture("normal",	&ceiling_normal);
	Ceiling_material.Set_Texture("arm",		&ceiling_arm);

	Chains_material.Set_Texture("albedo",	&chain_albedo);
	Chains_material.Set_Texture("normal",	&chain_normal);
	Chains_material.Set_Texture("arm",		&chain_arm);

	Doors_material.Set_Texture("albedo",	&door_albedo);
	Doors_material.Set_Texture("normal",	&door_normal);
	Doors_material.Set_Texture("arm",		&door_arm);

	Floor_material.Set_Texture("albedo",	&floor_albedo);
	Floor_material.Set_Texture("normal",	&floor_normal);
	Floor_material.Set_Texture("arm",		&floor_arm);

	Green_Curtains_material.Set_Texture("albedo",	&green_curtain_albedo);
	Green_Curtains_material.Set_Texture("normal",	&green_curtain_normal);
	Green_Curtains_material.Set_Texture("arm",		&green_curtain_arm);

	Green_Gold_Curtains_material.Set_Texture("albedo",	&green_gold_curtain_albedo);
	Green_Gold_Curtains_material.Set_Texture("normal",	&green_gold_curtain_normal);
	Green_Gold_Curtains_material.Set_Texture("arm",		&green_gold_curtain_arm);

	Hook_material.Set_Texture("albedo",	&hook_albedo);
	Hook_material.Set_Texture("normal",	&hook_normal);
	Hook_material.Set_Texture("arm",	&hook_arm);

	Lion_Face_material.Set_Texture("albedo",	&lion_face_albedo);
	Lion_Face_material.Set_Texture("normal",	&lion_face_normal);
	Lion_Face_material.Set_Texture("arm",		&lion_face_arm);

	Lion_material.Set_Texture("albedo",	&lion_albedo);
	Lion_material.Set_Texture("normal",	&lion_normal);
	Lion_material.Set_Texture("arm",	&lion_arm);

	Pillers_material.Set_Texture("albedo",	&pillers_albedo);
	Pillers_material.Set_Texture("normal",	&pillers_normal);
	Pillers_material.Set_Texture("arm",		&pillers_arm);

	Plants_material.Set_Texture("albedo",	&plant_albedo);
	Plants_material.Set_Texture("normal",	&plant_normal);
	Plants_material.Set_Texture("arm",		&plant_arm);

	Pot_Plants_material.Set_Texture("albedo",	&pot_plant_albedo);
	Pot_Plants_material.Set_Texture("normal",	&pot_plant_normal);
	Pot_Plants_material.Set_Texture("arm",		&pot_plant_arm);

	Pots_material.Set_Texture("albedo",	&pots_albedo);
	Pots_material.Set_Texture("normal",	&pots_normal);
	Pots_material.Set_Texture("arm",	&pots_arm);

	Red_Curtains_material.Set_Texture("albedo",	&red_curtain_albedo);
	Red_Curtains_material.Set_Texture("normal",	&red_curtain_normal);
	Red_Curtains_material.Set_Texture("arm",	&red_curtain_arm);

	Red_Gold_Curtains_material.Set_Texture("albedo",	&red_gold_curtain_albedo);
	Red_Gold_Curtains_material.Set_Texture("normal",	&red_gold_curtain_normal);
	Red_Gold_Curtains_material.Set_Texture("arm",		&red_gold_curtain_arm);

	Roof_material.Set_Texture("albedo",	&roof_albedo);
	Roof_material.Set_Texture("normal",	&roof_normal); 
	Roof_material.Set_Texture("arm",	&roof_arm);

	Room_material.Set_Texture("albedo",	&room_albedo);
	Room_material.Set_Texture("normal",	&room_normal);
	Room_material.Set_Texture("arm",	&room_arm);

	Top_Pillers_material.Set_Texture("albedo",	&top_pillers_albedo);
	Top_Pillers_material.Set_Texture("normal",	&top_pillers_normal);
	Top_Pillers_material.Set_Texture("arm",		&top_pillers_arm);

	Upper_Pillers_material.Set_Texture("albedo",	&upper_piller_albedo);
	Upper_Pillers_material.Set_Texture("normal",	&upper_piller_normal);
	Upper_Pillers_material.Set_Texture("arm",		&upper_piller_arm);

	
	camera.Add_To_Draw_Stack(&Arches);
	camera.Add_To_Draw_Stack(&Bars);
	camera.Add_To_Draw_Stack(&Big_Pot);
	camera.Add_To_Draw_Stack(&Blue_Curtans);
	camera.Add_To_Draw_Stack(&Blue_Gold_Curtains);
	camera.Add_To_Draw_Stack(&Ceiling);
	camera.Add_To_Draw_Stack(&Chains);
	camera.Add_To_Draw_Stack(&Doors);
	camera.Add_To_Draw_Stack(&Floor);
	camera.Add_To_Draw_Stack(&Green_Curtains);
	camera.Add_To_Draw_Stack(&Green_Gold_Curtains);
	camera.Add_To_Draw_Stack(&Hook);
	camera.Add_To_Draw_Stack(&Lion_Face);
	camera.Add_To_Draw_Stack(&Lion);
	camera.Add_To_Draw_Stack(&Pillers);
	camera.Add_To_Draw_Stack(&Plants);
	camera.Add_To_Draw_Stack(&Pot_Plants);
	camera.Add_To_Draw_Stack(&Pots);
	camera.Add_To_Draw_Stack(&Red_Curtains);
	camera.Add_To_Draw_Stack(&Red_Gold_Curtains);
	camera.Add_To_Draw_Stack(&Roof);
	camera.Add_To_Draw_Stack(&Room);
	camera.Add_To_Draw_Stack(&Top_Pillers);
	camera.Add_To_Draw_Stack(&Upper_Pillers);
	


	std::vector<Light*> light_pos;

	bool Released = true;

	while (!window.Should_Close())
	{
		window.Update();
		/*
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Text("FPS : %f", (float)Get_FPS(), 0.1f, 0.0f, 100.0f);
		ImGui::Text("Camera Position : %f %f %f", camera.Position.x, camera.Position.y, camera.Position.z);

		ImGui::Separator();
		*/
		for (int i = 0; i < light_pos.size(); i++)
		{
			//ImGui::Text("Light %i Position : %f %f %f", i, light_pos[i]->Position.x, light_pos[i]->Position.y, light_pos[i]->Position.z, 0.1f, -100.0f, 100.0f);
		}

		FreeCam(&camera, &window);

		if (glfwGetKey(window.Get_Window(), GLFW_KEY_E) == GLFW_PRESS)
		{
			if (Released == true)
			{
				Light* light = new Light(camera.Position, glm::vec3(1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032f);
				camera.Add_Light(light);
				light_pos.push_back(light);
				
				Released = false;
			}
		}
		else
		{
			Released = true;
		}

		if (glfwGetKey(window.Get_Window(), GLFW_KEY_Q) == GLFW_PRESS)
		{
			light_pos.clear();
		}
		
		camera.Draw(&window);

		//ImGui::End();
		//ImGui::Render();

		//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	return 0;
}