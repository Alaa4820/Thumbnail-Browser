#ifndef QITEM_H
#define QITEM_H

#include <QWidget>
#include <QDebug>
#include <QObject>
#include <QEvent>

/**
 * @brief Classe container che contiene l'immagine e la categoria
 * a cui afferisce
 */
class QItem : public QWidget{
    Q_OBJECT

public:
    QItem();
    QItem(const QPixmap &image, const QString &category, const QString &path);
    QItem(const QItem &other);
    const QItem& operator=(const QItem &other);
    ~QItem();

    const QPixmap& get_image() const;
    const QString& get_category() const;
    const QString& get_image_path() const;

private:
    QPixmap _image;
    QString _category;
    QString _path;

};

QDebug operator<<(QDebug dbg, const QItem& item);

#endif // QITEM_H
