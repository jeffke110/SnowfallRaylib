#pragma once
#ifndef SNOWFLAKES_H
#define SNOWFLAKES_H

#include "Snowflake.h"
#include <vector>

class Snowflakes {

public:
	Snowflakes();
	~Snowflakes();

	void draw_update();
	void removeSnowflake();

private:
	Texture2D snowflake_img;
	std::vector<Snowflake> snowflakes;

};

#endif // !SNOWFLAKES_H
