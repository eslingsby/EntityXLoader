#include "Engine.hpp"
#include "Timer.hpp"

int main(int argc, char** argv) {
	Engine engine(argc, argv);

	TimePoint timer;
	entityx::TimeDelta dt = 0.0;

	//while (engine.running()) {
		startTime(&timer);

		engine.update(dt);

		dt = deltaTime(timer);
	//}

	return 0;
}