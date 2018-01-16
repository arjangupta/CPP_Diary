/* Author: Arjan Gupta
 * Purpose: Test to see class state alterations
 */

#include <iostream>

class Sample
{
public:

	Sample ()
	{
		m_value = 0;
	}

	Sample ( const Sample &other )
	{
		m_value = other.getValue();
	}

	int getValue () const
	{
		return m_value;
	}

	void setValue ( int val )
	{
		m_value = val;
	}

protected:
	int m_value;
};


Sample alter_state ( Sample src_sample )
{
	src_sample.setValue( 45 );
	return src_sample;
}

int main ()
{
	Sample my_sample;
	std::cout << "my_sample.getValue() is " << my_sample.getValue() << std::endl;
	my_sample = alter_state( my_sample );
	std::cout << "After calling alter_state(), my_sample.getValue() is " << my_sample.getValue() << std::endl;

	return 0;
}