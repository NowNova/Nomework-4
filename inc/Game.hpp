#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace saa {
	class Game {
	private:
		int m_width;
		int m_height;
		std::string m_capture; //Название
		saa::Circle* m_c;
		saa::Rectangle* m_r;
		saa::Triangle* m_t;
		saa::Line* m_l;
		int m_n;
		sf::RenderWindow m_window;

	public:
		Game(int width, int height, const std::string& capture) {
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n) {

			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			m_c = new saa::Circle[m_n];
			m_r = new saa::Rectangle[m_n];
			m_t = new saa::Triangle[m_n];
			m_l = new saa::Line[m_n];

			srand(time(0));
			for (int i = 0; i < m_n; i++) {
				int x = rand() % 1000;
				int y = rand() % 600;
				int x1 = rand() % 1000;
				int y1 = rand() % 600;
				int x2 = rand() % 1000;
				int y2 = rand() % 600;
				int s1 = rand() % 100;
				int s2 = rand() % 100;
				int s3 = rand() % 100;
				int s4 = rand() % 100;
				int s5 = rand() % 100;
				int s6 = rand() % 100;
				int r = rand() % 100 + 1;
				int a = rand() % 100 + 1;
				int b = rand() % 100 + 1;
				int l1 = rand() % 1000;
				int l2 = rand() % 1000;
				int l3 = rand() % 1000;
				int l4 = rand() % 360 + 1;
				m_c[i].Setup(x, y, r);
				m_r[i].Setup(x1, y1, a, b);
				m_t[i].Setup(x2, y2, s1, s2, s3, s4, s5, s6);
				m_l[i].Setup(l1, l2, l3, l4);
			}
		}
		void Life() 
		{
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].Get());
					m_window.draw(m_r[i].Get());
					m_window.draw(m_t[i].Get());
					m_window.draw(m_l[i].Get());
				}
				m_window.display();
			}
		}
	};
}