#include "graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent)                                //类的构造
{
	graph_space = 0;                                                           //相关数据的初始化
	for (int i = 0; i < 450; ++i) {
		graph_data[i] = 0;
	}
}

void Graph::startTime(double timer_t)                                          //计时器的开始
{
	timerID = startTimer(timer_t);
}

void Graph::stopTime()                                                         //计时器的结束
{
	killTimer(timerID);
}

void Graph::paintEvent(QPaintEvent *)                                          //用于进行图像的重绘
{
	QPainter painter(this);                                                    //新建画笔
	painter.setPen(Qt::gray);                                                  //画笔颜色-表示边框颜色
	painter.setBrush(Qt::white);                                               //花刷颜色-表示内部颜色
	painter.drawRect(0, 0, 465, 405);

	for (int i = 1; i < 4; ++i) {                                              //绘制横向坐标线
		painter.drawLine(0, i * 101, 465, i * 101);
	}

	for (int i = 1; i < 5; ++i) {                                              //绘制纵向坐标线
		painter.drawLine(i * 93, 0, i * 93, 405);
	}

	painter.setPen(QColor(30, 160, 200));                                      //设置画笔颜色
	int old_y = 0, new_y;
	for (int i = 0; i < 450; ++i) {
		new_y = (405 / 2) * (1 - graph_data[(graph_space + i) % 450]);         //计算当前数值在位图中的像素位置
		painter.drawLine(i - 1, old_y, i, new_y);                              //线的绘制是从前点至后点
		old_y = new_y;
	}
}

void Graph::timerEvent(QTimerEvent *)                                          //用于触发计时器的操作
{
	graph_data[graph_space] = paragraph_voice / qPow(2, SIZE);                 //取出数据存放到位图中
	graph_space++;                                                             //位标后移
	update();                                                                  //更新位图
}
