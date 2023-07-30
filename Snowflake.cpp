#include "Snowflake.h"



Snowflake::Snowflake(Texture2D &snowflake_img) {

	this->snowflake_img = snowflake_img;
	position = { (float)GetRandomValue(0, GetScreenWidth()), -50.0f };
	velocity = { 0.0f, 1.0f };
	gravity = .005f;
	acceleration = { 0.0f, gravity};
	radius = generateRadius();
	angle = 0.0f;
	direction = Random::Float() < .5 ? -1.0f : 1.0f;
	rotateAngle = 0.0f;
}

Snowflake::~Snowflake() {

}

float Snowflake::generateRadius() {
	float random = Random::Float();
	if (random < .7) {
		return Random::Float() * 5; 		// 0 - 5
	}
	return 5.0f + (Random::Float() * 8); 	// 5 - 10
}

void Snowflake::draw() {
	//rotate based off radius
	DrawTextureEx(snowflake_img, position, rotateAngle, radius / 10, WHITE);
	rotateAngle += direction * radius * .1;
}

void Snowflake::sinusoidal_X_Coordinate() {
	float offset = sin(angle) * radius * .25;
	position.x += offset;
}

void Snowflake::limitAcceleration() {
	//create terminal velocity based off radius of snow flake
	if (velocity.y >= radius * .5) {
		velocity.y = radius * .5;
	}
	else {
		velocity.y += acceleration.y;
	}
}

void Snowflake::update() {
	limitAcceleration();
	sinusoidal_X_Coordinate();
	position.y += velocity.y;
	angle += .001f * direction;
}

bool Snowflake::isOffScreen() {
	if (position.x + (50.0f) < 0.0f) {
		return true;
	}
	else if (position.x - (50.0f) > GetScreenWidth()) {
		return true;
	}
	else if (position.y - (50.0f) > GetScreenHeight()) {
		return true;
	}
	else {
		return false;
	}

}