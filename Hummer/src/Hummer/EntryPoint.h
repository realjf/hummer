#pragma once

#ifdef HM_PLATFORM_WINDOWS

extern Hummer::Application* Hummer::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hummer Engine!\n");
	auto app = Hummer::CreateApplication();
	app->Run();
	delete app;
}

#endif // HM_PLATFORM_WINDOWS



