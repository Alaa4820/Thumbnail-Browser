#ifndef QPIXMAPLABEL_H
#define QPIXMAPLABEL_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <algorithm>

/**
 * @brief Classe che implementa una QLabel cliccabile
 */
class QPixmapLabel : public QLabel{

    Q_OBJECT

signals:
    void doubleClicked(const QString &path);


public:
    explicit QPixmapLabel(QWidget* parent = NULL);
    QPixmapLabel(QPixmap image, QString path, QWidget* parent = NULL);
    QPixmapLabel& operator=(const QPixmapLabel &other);
    QPixmapLabel(const QPixmapLabel &other);
    ~QPixmapLabel();
    void setImage(const QPixmap &pixmap);
    void setPath(const QString &path);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);



private:
    QPixmap _image;
    QString _path;
};

#endif // QPIXMAPLABEL_H
