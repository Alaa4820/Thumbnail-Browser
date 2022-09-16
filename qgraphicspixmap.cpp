#include "qgraphicspixmap.h"

QGraphicsPixmap::QGraphicsPixmap(): image(""), category(""){}

QGraphicsPixmap::QGraphicsPixmap(const QPixmap &img, const QString &s) : QGraphicsPixmapItem(img), image(img), category(s){}

QGraphicsPixmap::QGraphicsPixmap(const QGraphicsPixmap &other):  QGraphicsPixmapItem(other.image), image(other.image), category(other.category){}

const QGraphicsPixmap &QGraphicsPixmap::operator=(const QGraphicsPixmap &other){
    if(this != &other){
        QGraphicsPixmap tmp(*this);
        std::swap(image, tmp.image);
        std::swap(category, tmp.category);
    }
    return *this;
}

QGraphicsPixmap::~QGraphicsPixmap(){}

const QPixmap &QGraphicsPixmap::get_image() const{
    return image;
}

const QString &QGraphicsPixmap::get_category() const{
    return category;
}

void QGraphicsPixmap::click(QGraphicsSceneMouseEvent *event){
    qDebug() << "click";
}

QDebug operator<<(QDebug dbg, const QGraphicsPixmap& item){
    dbg << item.get_image() << " " << item.get_category();
    return dbg;
}
