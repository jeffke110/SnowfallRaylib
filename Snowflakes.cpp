

#include "Snowflakes.h"



Snowflakes::Snowflakes() {
	snowflake_img = LoadTexture("resources/snowflake.png");
	snowflakes.push_back(Snowflake(snowflake_img));
}
Snowflakes::~Snowflakes() {

}

void Snowflakes::draw_update() {
	snowflakes.push_back(Snowflake(snowflake_img));
	for (auto& snowflake : snowflakes) {
		snowflake.draw();
		snowflake.update();
	}
}


void Snowflakes::removeSnowflake() {

	auto it = remove_if(snowflakes.begin(), snowflakes.end(), [](Snowflake& s) { return s.isOffScreen();  });
	snowflakes.erase(it, snowflakes.end());

}

