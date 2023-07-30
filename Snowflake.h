#pragma once
#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include "raylib.h"
#include "raymath.h"
#include "Random.h"

#include <iostream>


class Snowflake {

public:
	Snowflake(Texture2D &snowflake_img);
	~Snowflake();

	void draw();
	void update();
	bool isOffScreen();

	void limitAcceleration();
	void sinusoidal_X_Coordinate();
	float generateRadius();

private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float radius;
	float gravity;
	float angle;
	float direction;
	float rotateAngle;

	Texture2D snowflake_img;

};

#endif // !SNOWFLAKE_H