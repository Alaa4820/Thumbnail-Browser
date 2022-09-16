#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QHBoxLayout>
#include <QDebug>
#include <QWidget>
#include <QDirIterator>
#include <QCheckBox>
#include <QPushButton>
#include <QMap>
#include <QCloseEvent>
#include <QEvent>
#include <QLabel>
#include "qflowlayout.h"
#include "qitem.h"
#include "qpixmaplabel.h"
#include "qpixmapdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_categories();
    QCheckBox* getCheckBoxAll() const;
    unsigned int totalImages() const;
    void removeItemsFromFlowLayout();
    bool areAllCheckBoxChecked() const;
    void addItemsInFlowLayout(const QList<QItem> &list);
    void addItemsInFlowLayoutRandom(const QList<QItem> &list);

protected:
    void closeEvent(QCloseEvent*);


public slots:
    void showAllImages();
    void changeCheckStateAll();
    void loadAllImages();
    void showImagesByCategory();
    void showImageInDialog(const QString &path);

private:
    Ui::MainWindow *ui;
    QFlowLayout *flowLayout;///< layout dinamico che contiene le immagini
    QDir *directory;///< directory dataset
    QPixmapDialog *dialog;///< custom dialog
    QStringList categories;///< lista delle categorie
    QMap<QString, QList<QItem>> map;///< mappa delle categorie con associate le liste gli oggetti che contengono le immagini
    QList<QCheckBox*> categories_checkbox;///< lista delle checkbox
    QList<QItem> all_items;///< lista di tutti i QItem (riempita una sola volta appena si clicca su "All")
};
#endif // MAINWINDOW_H
