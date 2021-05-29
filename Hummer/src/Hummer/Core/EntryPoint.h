#pragma once

#ifdef HM_PLATFORM_WINDOWS

extern Hummer::Application* Hummer::CreateApplication();

int main(int argc, char** argv)
{
	Hummer::Log::Init();

	HM_PROFILE_BEGIN_SESSION("Startup", "HummerProfile-Startup.json");
	auto app = Hummer::CreateApplication();
	HM_PROFILE_END_SESSION();

	HM_PROFILE_BEGIN_SESSION("Runtime", "HummerProfile-Runtime.json");
	app->Run();
	HM_PROFILE_END_SESSION();

	HM_PROFILE_BEGIN_SESSION("Startup", "HummerProfile-Shutdown.json");
	delete app;
	HM_PROFILE_END_SESSION();
}


#endif
