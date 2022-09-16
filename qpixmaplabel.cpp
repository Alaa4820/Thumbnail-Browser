#include "qpixmaplabel.h"

/**
 * Costruttore di default
 */
QPixmapLabel::QPixmapLabel(QWidget *parent) :QLabel(parent), _image("empty"), _path(""){}

/**
 * Costruttore secondario
 */
QPixmapLabel::QPixmapLabel(QPixmap image, QString path, QWidget *parent)
    :  QLabel(parent), _image(image), _path(path){}

/**
 * Copy constructor
 */
QPixmapLabel::QPixmapLabel(const QPixmapLabel &other): QLabel(), _image(other._image), _path(other._path) {}

/**
 * Operatore assegnamento
 */
QPixmapLabel& QPixmapLabel::operator=(const QPixmapLabel &other){
    if(this != &other){
        QPixmapLabel tmp(other);
        std::swap(_image, tmp._image);
        std::swap(_path, tmp._path);
    }
    return *this;
}

/**
 * Distruttore
 */
QPixmapLabel::~QPixmapLabel(){}

/**
 * Setter del dato membro _image
 */
void QPixmapLabel::setImage(const QPixmap &pixmap){
    _image = pixmap;
    setPixmap(pixmap);
}
/**
 * Setter del dato membro _path
 */
void QPixmapLabel::setPath(const QString &path){
    _path = path;
}

/**
 * Funzione che riceve l'evento "doppio click" e emette un SIGNAL
 * con la funzione doubleClicked(QString)
 */
void QPixmapLabel::mouseDoubleClickEvent(QMouseEvent *event){
    Q_UNUSED(event);
    emit doubleClicked(_path);
}




