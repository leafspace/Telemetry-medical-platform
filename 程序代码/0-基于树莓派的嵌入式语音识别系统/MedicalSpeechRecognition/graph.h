#ifndef GRAPH_H
#define GRAPH_H

#include "voice.h"
#include <QWidget>
#include <qpainter.h>                                                          //涉及到图像的更新操作
#include <QtCore/qmath.h>                                                      //用于支持qpow

class Graph : public QWidget                                                   //本类用于描述波形的变化-显示类
{
	Q_OBJECT
public:
	explicit Graph(QWidget *parent = 0);

	void startTime(double timer_t);                                            //计时器的开始
	void stopTime();                                                           //计时器的结束
signals:

	public slots :
private:
	float graph_data[450];                                                     //描述显示图中的数据的内容（采用队列的方式减少内存消耗）
	int graph_space;                                                           //描述当前输出的位于graph_data中的位置
	int timerID;                                                               //计时器的ID，用于结束时使用

	void paintEvent(QPaintEvent*);                                             //用于进行图像的重绘
	void timerEvent(QTimerEvent*);                                             //用于触发计时器的操作
};

#endif // GRAPH_H
