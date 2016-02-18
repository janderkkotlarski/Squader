#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <chrono>
#include <thread>
#include <utility>

#include <SFML/Graphics.hpp>



sf::Vector2f square_vector2f(const float length)
{
	
	return sf::Vector2f(length, length);
	
}

sf::Color type_to_color(const int type)
{
	
	const sf::Color white{sf::Color(255, 255, 255)};    
    const sf::Color black{sf::Color(0, 0, 0)};    
    const sf::Color orange{sf::Color(255, 127, 0)};    
    const sf::Color purple{sf::Color(127, 0, 255)};    
    const sf::Color cyan{sf::Color(127, 255, 255)};
    const sf::Color red{sf::Color(255, 0, 0)};
    const sf::Color yellow{sf::Color(255, 255, 0)};
    const sf::Color green{sf::Color(0, 255, 0)};
    const sf::Color blue{sf::Color(127, 127, 255)};
    const sf::Color grey{sf::Color(127, 127, 127)};
    
    switch (type)
    {
		
		case -1:
			return orange;
		case 0:
			return black;
		case 1:
			return grey;
			
	}
	
	return black;
	
}

class squade
{
	
	const float m_length{64.0f};
	
	const int m_type{0};
		
	sf::RectangleShape m_square{square_vector2f(m_length)};
	
	public:
	
	void set_position(const sf::Vector2f& position)
	{
		
		m_square.setPosition(position);
		
	}
	
	void set_color()
	{
		
		m_square.setFillColor(type_to_color(m_type));
		
	}
	
	void show_squade(sf::RenderWindow& window)
	{
		
		window.draw(m_square);
		
	}
	
	squade(const float length, const sf::Vector2f& position, const int type);
	
	~squade();	
	
};

squade::squade(const float length, const sf::Vector2f& position, const int type)
	: m_length(length), m_type(type), m_square(square_vector2f(m_length))
{
	
	assert(m_length > 0);
	
	m_square.setOrigin(square_vector2f(0.5f*m_length));
	set_position(position);
	set_color();
		
}

squade::~squade()
{
	
}



int main()
{
	
	const std::string program_name{"Squader V0.1"};
	

	
	const float refresh_rate{25.0f};
	assert(refresh_rate > 0.0f);
	
	const int delaz{static_cast<int>(1000.0f/refresh_rate)};
	assert(delaz > 10);
	
	const std::chrono::milliseconds delay{delaz};
	
	const float length{64.0f};	
	assert(length > 7.999f);
	
	const float sides{11.0f};
	assert(sides > 4.999f);
	
	const float window_x{length*sides};
       
    const sf::Vector2f window_sizes{window_x, window_x};
    
    const sf::Color white{sf::Color(255, 255, 255)};    
    const sf::Color black{sf::Color(0, 0, 0)};    
    const sf::Color orange{sf::Color(255, 127, 0)};    
    const sf::Color purple{sf::Color(127, 0, 255)};    
    const sf::Color cyan{sf::Color(127, 255, 255)};
    const sf::Color red{sf::Color(255, 0, 0)};
    const sf::Color yellow{sf::Color(255, 255, 0)};
    const sf::Color green{sf::Color(0, 255, 0)};
    const sf::Color blue{sf::Color(127, 127, 255)};
    
    sf::RenderWindow window{sf::VideoMode(window_x, window_x), program_name, sf::Style::Default};
    
    const sf::Vector2f player_start_position{0.5f*window_sizes};
    
    squade player{length, player_start_position, 1};
	
	while (window.isOpen())
    {

        sf::Event event;
        
        window.clear(black); 
        
        player.show_squade(window);    

        window.display();
        
        std::this_thread::sleep_for(delay);       

                    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            
            window.close();
                    
            return 1;
                    
        }    
        
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                
                window.close();
                
                return 2;
                
            }
        
        }
            

    }
	
	
	
	return 0;
	
}
