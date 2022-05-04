#pragma once
namespace Eclipse
{
	namespace Engine
	{
		class EclipseTime
		{
		public:
			static long long CurrentTime;
			static long long LastTime;
			static int FPS;
			static int Frames;
			static float Timer;
			static float DeltaTime;

			static void Init();
			static void Tick();
		};
	}
}

