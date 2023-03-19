#include "qcustomhorn.h"

QCustomHorn::QCustomHorn(QWidget *parent) : QWidget(parent)
{
    m_background_color_ = QColor(55,107,154, 30);

    m_active_color_ = Qt::yellow;
    m_unactive_color_ = Qt::gray;
}


QCustomHorn::~QCustomHorn()
{

}


void QCustomHorn::resizeEvent(QResizeEvent *)
{
    this->repaint();
}


QSize QCustomHorn::sizeHint() const
{
    return QSize(150, 150);
}

QSize QCustomHorn::minimumSizeHint() const
{
    return QSize(30, 30);
}

void QCustomHorn::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width / 2, height / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBackground(&painter);

//    drawHorn(&painter);
    drawVehicleHorn(&painter);

//    drawTitle(&painter);

//    drawTimeCost(&painter);

//    drawSystemTime(&painter);
}

void QCustomHorn::drawBackground(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    painter->save();

    painter->setBrush(m_background_color_);
    painter->drawRect(-width, -height, width * 2, height * 2);

    painter->restore();
}

void QCustomHorn::drawHorn(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    painter->save();

    static const QPoint points[] = {
        QPoint(-10,  -5),
        QPoint( 48,  -5),
        QPoint( 58, -28),
        QPoint( 58,  28),
        QPoint( 48,   5),
        QPoint(-10,   5),
    };

    static const QLine lines[] = {
        {-10, -7, 58, -7},
        {-10,  7, 42,  7},
        { 113,-40, 113,  40},
    };
//    QRectF target(-40.0, -30.0, 80.0, 60.0);

//    if (m_horn_active_)
//    {
//        QImage image(":/resource/image/horn_on.png");
//        painter->setPen(QPen(m_active_color_, 4));
//        painter->drawImage(target, image);
//    } else {
//        QImage image(":/resource/image/horn_off.png");
//        painter->setPen(QPen(m_unactive_color_, 4));
//        painter->drawImage(target, image);
//    }
    if (m_horn_active_)
    {
        painter->setPen(QPen(Qt::green, 6));
    } else {
        painter->setPen(QPen(Qt::gray, 6));
    }


    painter->drawEllipse(-50, -20, 40, 40);

    QRectF rectangle2(2.0, -7.0, 60.0, 40.0);
    int startAngle2 = 90 * 16;
    int spanAngle2 = -280 * 16;
    painter->drawArc(rectangle2, startAngle2, spanAngle2);

    QRectF rectangle3(18.0, 3.0, 30.0, 20.0);
    int startAngle3 = 36 * 16;
    int spanAngle3 = -230 * 16;
    painter->drawArc(rectangle3, startAngle3, spanAngle3);

//    painter->drawPolygon(points, sizeof(points)/sizeof(points[0]));
    painter->drawLines(lines, sizeof(lines)/sizeof(lines[0]));

    QRectF rectangle(10.0, -87.0, 100.0, 80.0);
    int startAngle = 270 * 16;
    int spanAngle = 80 * 16;
    painter->drawArc(rectangle, startAngle, spanAngle);

    QRectF rectangle1(10.0, 7.0, 100.0, 80.0);
    int startAngle1 = 90 * 16;
    int spanAngle1 = -80 * 16;
    painter->drawArc(rectangle1, startAngle1, spanAngle1);

    painter->restore();
}

void QCustomHorn::drawVehicleHorn(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);
    QRectF target(-128.0, -83.0, 256.0, 165.0);

    painter->save();

    if (m_horn_active_)
    {
        QImage image(":/resource/image/horn_on.png");
        if (m_dir_ == HORNDIR_LEFT)
        {
            painter->drawImage(target, image.mirrored(true, false));
        } else {
            painter->drawImage(target, image);
        }

    } else {
        QImage image(":/resource/image/horn_off.png");
        if (m_dir_ == HORNDIR_LEFT)
        {
            painter->drawImage(target, image.mirrored(true, false));
        } else {
            painter->drawImage(target, image);
        }

    }


    painter->restore();
}

void QCustomHorn::setHornState(const bool value)
{
    if (this->m_horn_active_ != value)
    {
        this->m_horn_active_ = value;
        this->update();
    }
}

void QCustomHorn::setHornDir(const HornDir value)
{
    if (this->m_dir_ != value)
    {
        this->m_dir_ = value;
        this->update();
    }
}
