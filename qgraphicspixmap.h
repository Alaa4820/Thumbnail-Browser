#ifndef QGRAPHICSPIXMAP_H
#define QGRAPHICSPIXMAP_H

#include <QWidget>
#include <QEvent>
#include <QGraphicsPixmapItem>
#include <algorithm>

class QGraphicsPixmap : public QGraphicsPixmapItem, QObject {

public:
    QGraphicsPixmap();
    QGraphicsPixmap(const QPixmap &img, const QString &s);
    QGraphicsPixmap(const QGraphicsPixmap &other);
    const QGraphicsPixmap& operator=(const QGraphicsPixmap &other);
    ~QGraphicsPixmap();

    const QPixmap& get_image() const;
    const QString& get_category() const;


    void click(QGraphicsSceneMouseEvent *event);

private:
    QPixmap image;
    QString category;

};

QDebug operator<<(QDebug dbg, const QGraphicsPixmap& item);

#endif // QGRAPHICSPIXMAP_H
