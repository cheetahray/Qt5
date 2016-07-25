#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) :
    QObject(parent)
{
    camera = new QCamera(QCamera::availableDevices()[1]);
    imageCapture = new QCameraImageCapture(camera);
    view_finder = new QCameraViewfinder();

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage))
                , this, SLOT(displayImage(int,QImage)));

    camera->setCaptureMode(QCamera::CaptureViewfinder);
    camera->setViewfinder(view_finder);

    flash=true;
    setFlag(ItemIsMovable);
    camera->start();
    startTimer(100);
}

void FlashItem::displayImage(int id, QImage image)
{
    pix = QPixmap::fromImage(image);
    //ui->lblShowImage->setPixmap();
    //將影像畫在lblShowImage上
}

void FlashItem::videoFrameCapture()
{
    imageCapture->capture();
    //擷取當下視訊畫面
}

QRectF FlashItem::boundingRect() const
{
    //qreal adjust = 2;
    return QRectF(-pix.width()>>1,-pix.height()>>1,pix.width(),pix.height());
    //return QRectF(-600,-300, 1200,600);
}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7,-7,40,40);

    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(flash?(Qt::red):(Qt::yellow));
    painter->drawEllipse(-10,-10,40,40);
    */
    painter->drawPixmap(boundingRect().topLeft(),pix);
}

void FlashItem::timerEvent(QTimerEvent *)
{
    videoFrameCapture();
    flash=!flash;
    update();
}
