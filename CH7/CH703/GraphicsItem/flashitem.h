#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QCamera>
#include <QTimer>
#include <QImage>
#include <QDebug>

class FlashItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void timerEvent(QTimerEvent *);
private:
    bool flash;
    QTimer *timer;
    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QCameraViewfinder *view_finder;
    QPixmap pix;

signals:
    
private slots:
    //void startCaptureImage();
    void displayImage(int id, QImage image);
    void videoFrameCapture();
};

#endif // FLASHITEM_H
