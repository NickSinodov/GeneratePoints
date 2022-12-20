#include "Object.h"

Object::Object()
{
	m_running	= false;
	m_pause		= false;
	position.X	= 0;
	position.Y	= 0;
}

void Object::run()
{
	while (m_running)
	{
		if(m_pause)
		{
			thread.sleep(1);
		}
		else
		{
			position.X = QRandomGenerator::global()->bounded(0, 100);
			position.Y = QRandomGenerator::global()->bounded(0, 100);
			emit variableChange();
			thread.sleep(1);
		}
	}
}
