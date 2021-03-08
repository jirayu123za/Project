#include "Player.h"

void Player::initVaribles() {
	this->movementSpeed = 3.f;
}

void Player::initShape() {
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x,float y) {

	this->shape.setPosition(100, 780);

	this->initVaribles();
	this->initShape();
}

Player::~Player() {

}

void Player::updateInput() {
	//Keyboard input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(-this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(this->movementSpeed, 0.f);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target) {
	//Left
	if(this->shape.getGlobalBounds().left <= 200.f )
		this->shape.setPosition(200.f, this->shape.getGlobalBounds().top);
	//Right
	if(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x){
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
}

void Player::update(const sf::RenderTarget*target) {

	this->updateInput();

	//Window bounds collision
	this->updateWindowBoundsCollision(target);

}
void Player::render(sf::RenderTarget*target) {
	target->draw(this->shape);
}

