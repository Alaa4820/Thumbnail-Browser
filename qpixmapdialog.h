#ifndef QPIXMAPDIALOG_H
#define QPIXMAPDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QLabel>
#include <algorithm>
/**
 * @brief Classe che implementa una QDialog
 */
class QPixmapDialog : public QDialog{
    Q_OBJECT

public:
    QPixmapDialog(QWidget *parent = nullptr);
    QPixmapDialog(const QPixmapDialog &other);
    QPixmapDialog& operator=(const QPixmapDialog &other);
    ~QPixmapDialog();
    void setPixmap(const QPixmap &img);

private:
    QPixmap _image;
    QHBoxLayout *_layout;
    QLabel *_label;
};

#endif // QPIXMAPDIALOG_H
