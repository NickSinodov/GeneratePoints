#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QThread>
#include <QRandomGenerator>

class Object : public QObject
{
	Q_OBJECT
public:
	Object();
	struct Position
	{
		int X;
		int Y;
	}position;
	QThread thread;

	bool m_running;
	bool m_pause;
signals:
	void variableChange();
public slots:
	void run();
};

#endif // OBJECT_H
