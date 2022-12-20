#include "GraphicScene.h"
#include "ui_GraphicScene.h"

GraphicScene::GraphicScene(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphicScene)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&m_scene);
	connect(&m_obj.thread, &QThread::started, &m_obj, &Object::run);
	connect(&m_obj, &Object::variableChange, this, &GraphicScene::getCoordinate);
	m_obj.moveToThread(&m_obj.thread);
	m_pen.setColor(Qt::black);
}

GraphicScene::~GraphicScene()
{
	delete ui;
}

void GraphicScene::getCoordinate()
{
	m_scene.addEllipse(m_obj.position.X, m_obj.position.Y, 4, 4, m_pen, QBrush(Qt::black));
}

void GraphicScene::on_Start_clicked()
{
	m_obj.m_running = true;

	if(!m_obj.m_pause)
	{
		m_obj.thread.start();
	}
	else
	{
		m_obj.m_pause = false;
	}
}


void GraphicScene::on_Pause_clicked()
{
	if(m_obj.m_running)
	{
		m_obj.m_pause = true;
	}
}


void GraphicScene::on_Stop_clicked()
{
	m_obj.thread.terminate();
	m_obj.m_running = false;
	m_obj.m_pause	= false;
	m_scene.clear();
}

