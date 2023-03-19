#ifndef QCUSTOMHORN_H
#define QCUSTOMHORN_H

#include <QWidget>
#include <QPainter>

/**
 * @brief Feature:
 * Support
 * Support
 * Support
 * Support
 */

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT QCustomMobileSignal : public QWidget
#else
class QCustomHorn : public QWidget
#endif
{
    Q_OBJECT
public:
    explicit QCustomHorn(QWidget *parent = nullptr);
    ~QCustomHorn();

protected:
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

    void drawBackground(QPainter *painter);
    void drawHorn(QPainter *painter);
private:
    QColor m_active_color_;
    QColor m_unactive_color_;
    // false:unactive true:active
    bool m_horn_active_{false};

    QColor m_background_color_;

signals:

public slots:
    void setHornState(const bool value);
};

#endif // QCUSTOMHORN_H
