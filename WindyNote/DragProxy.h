#ifndef DRAGPROXY_H
#define DRAGPROXY_H

#include <QObject>
#include <QWidget>  
#include <QEvent>  
#include <QRect>  
#include <QPoint>

class DragProxy : public QObject
{
	Q_OBJECT

public:
	DragProxy(QWidget *parent);
	~DragProxy();

protected:  
	enum WidgetRegion  
	{  
		Top = 0,  
		TopRight,  
		Right,  
		RightBottom,  
		Bottom,  
		LeftBottom,  
		Left,  
		LeftTop,  
		Inner,  
		Unknown  
	};  

public:  
	// �������ܱ߿���  
	void SetBorderWidth(int top, int right, int bottom, int left);  

protected:  
	virtual bool eventFilter(QObject* obj, QEvent* event);  

	void MakeRegions();  
	WidgetRegion HitTest(const QPoint& pos);  
	void UpdateGeometry(int x, int y, int w, int h);  

	// ���ӱ߿�����Ƶ��������ӿؼ��ϣ����ܻ���������ʽδ�ı䣬����ʹ�ü�ʱ�����  
	void StartCursorTimer();  
	void StopCursorTimer();  

protected:
	QWidget* m_proxyWidget;     // ����Ĵ���  
	int m_top, m_right, m_bottom, m_left;   // ���ܿ��  
	QRect m_regions[9];     // �Ź��񣬶�Ӧ9������  

	QPoint m_originPosGlobal;   // ��קǰ���λ��  
	QRect m_originGeo;          // ��קǰ����λ�úʹ�С  

	bool m_mousePressed;        // ����Ƿ���  
	WidgetRegion m_regionPressed;   // ��¼��갴��ʱ�����������  

	int m_cursorTimerId;  
};

#endif // DRAGPROXY_H
