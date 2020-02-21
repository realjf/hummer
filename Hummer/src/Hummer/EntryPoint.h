#pragma once

#ifdef HM_PLATFORM_WINDOWS

extern Hummer::Application* Hummer::CreateApplication();

int main(int argc, char** argv)
{
	Hummer::Log::Init();
	HM_CORE_WARN("Initialized Log!");
	HM_INFO("Hello!");

	auto app = Hummer::CreateApplication();
	app->Run();
	delete app;
}

#endif // HM_PLATFORM_WINDOWS



