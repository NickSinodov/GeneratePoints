#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include "Object.h"
namespace Ui {
class GraphicScene;
}

class GraphicScene : public QWidget
{
	Q_OBJECT

public:
	explicit GraphicScene(QWidget *parent = nullptr);
	~GraphicScene();

private slots:
	void getCoordinate();
	void on_Start_clicked();

	void on_Pause_clicked();

	void on_Stop_clicked();

private:
	Ui::GraphicScene	*ui;
	QGraphicsScene		m_scene;
	Object				m_obj;
	QPen				m_pen;
};

#endif // GRAPHICSCENE_H
