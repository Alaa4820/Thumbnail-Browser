#include "qpixmapdialog.h"

/**
 * Costruttore di default
 */
QPixmapDialog::QPixmapDialog(QWidget *parent):QDialog(parent), _image(){
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle(QString("Dialog"));
    _layout = new QHBoxLayout;
    _label = new QLabel;
}
/**
 * Copy constructor
 */
QPixmapDialog::QPixmapDialog(const QPixmapDialog &other)
    : QDialog(), _image(other._image), _layout(other._layout), _label(other._label) {}

/**
 * Operatore assegnamento
 */
QPixmapDialog& QPixmapDialog::operator=(const QPixmapDialog &other) {
    if(this != &other){
        QPixmapDialog tmp(other);
        std::swap(_image, tmp._image);
        std::swap(_label, tmp._label);
        std::swap(_layout, tmp._layout);
    }
    return *this;
}

/**
 * Distruttore
 */
QPixmapDialog::~QPixmapDialog(){
    delete _layout;
    delete _label;
}

/**
 * Funzione che aggiunge l'immagine al layout
 * settando la dimensione della dialog con quella dell'immagine
 */
void QPixmapDialog::setPixmap(const QPixmap &img){
    _label->setPixmap(img);
    _layout->addWidget(_label, Qt::AlignCenter);
    setLayout(_layout);
    setMinimumSize(img.width(),img.height());
}

