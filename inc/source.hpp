#pragma once
#include <SFML/Graphics.hpp>

namespace saa {
	class Circle
	{
	private:
		float m_r;
		float m_x, m_y;
		sf::CircleShape m_shape;

	public:
		Circle() = default;

		Circle(float x, float y, float r) {
			Setup(x, y, r);
		}

		void Setup(float x, float y, float r) {
			m_x = x;
			m_y = y;
			m_r = r;
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Blue);
		}
		sf::CircleShape Get() 
		{
			return m_shape;
		}
	};

	class Rectangle
	{
	private:
		float m_a, m_b;
		float m_x, m_y;
		sf::RectangleShape m_shape;

	public:
		Rectangle() = default;

		Rectangle(float x, float y, float a, float b) {
			Setup(x, y, a, b);
		}

		void Setup(float x, float y, float a, float b) {
			m_x = x;
			m_y = y;
			m_a = a;
			m_b = b;
			m_shape.setSize(sf::Vector2f(m_a, m_b));
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Red);
		}
		sf::RectangleShape Get()
		{
			return m_shape;
		}
	};

	class Triangle
	{
	private:
		float m_x, m_y, m_s1, m_s2, m_s3, m_s4, m_s5, m_s6;
		sf::ConvexShape m_shape;

	public:
		Triangle() = default;

		Triangle(float x, float y, float s1, float s2, float s3, float s4, float s5, float s6) {
			Setup(x, y, s1, s2, s3, s4, s5, s6);
		}

		void Setup(float x, float y, float s1, float s2, float s3, float s4, float s5, float s6) {
			m_x = x;
			m_y = y;
			m_s1 = s1;
			m_s2 = s2;
			m_s3 = s3;
			m_s4 = s4;
			m_s5 = s5;
			m_s6 = s6;

			m_shape.setPointCount(3);
			m_shape.setPoint(0, sf::Vector2f(m_s1, m_s2));
			m_shape.setPoint(1, sf::Vector2f(m_s3, m_s4));
			m_shape.setPoint(2, sf::Vector2f(m_s5, m_s6));

			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Magenta);
		}
		sf::ConvexShape Get()
		{
			return m_shape;
		}
	};

	class Line
	{
	private:
		float m_l1, m_l2, m_l3, m_l4;
		sf::RectangleShape m_shape;

	public:
		Line() = default;

		Line(float l1, float l2, float l3, float l4) {
			Setup(l1, l2, l3, l4);
		}

		void Setup(float l1, float l2, float l3, float l4) {
			m_l1 = l1;
			m_l2 = l2;
			m_l3 = l3;
			m_l4 = l4;

			m_shape.setSize(sf::Vector2f(1, l1));
			m_shape.rotate(m_l4);
			m_shape.setPosition(m_l2, m_l3);
			m_shape.setFillColor(sf::Color::Cyan);
		}
		sf::RectangleShape Get()
		{
			return m_shape;
		}
	};
}

