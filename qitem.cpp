#include <algorithm>
#include "qitem.h"

/**
 * Costruttore di default
 */
QItem::QItem(): _image(), _category(), _path(){}

/**
 * Costruttore secondario
 */
QItem::QItem(const QPixmap &image, const QString &category, const QString &path)
    : _image(image), _category(category), _path(path){}

/**
 * Copy constructor
 */
QItem::QItem(const QItem &other)
    : QWidget(nullptr), _image(other._image), _category(other._category), _path(other._path){}

/**
 * Operatore assegnamento
 */
const QItem &QItem::operator=(const QItem &other){
    if(this != &other){
        QItem tmp(*this);
        std::swap(_image, tmp._image);
        std::swap(_category, tmp._category);
    }
    return *this;
}

/**
 * Distruttore
 */
QItem::~QItem(){}

/**
 * Getter del dato membro _image
 */
const QPixmap &QItem::get_image() const{
    return _image;
}
/**
 * Getter del dato membro _category
 */
const QString &QItem::get_category() const{
    return _category;
}
/**
 * Getter del dato membro _path
 */
const QString &QItem::get_image_path() const{
    return _path;
}
/**
 * Override dell'operatore di stream
 */
QDebug operator<<(QDebug dbg, const QItem& item){
    dbg << item.get_image() << " " << item.get_category();
    return dbg;
}


