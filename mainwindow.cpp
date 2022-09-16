#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>
/**
 * Costruttore della classe MainWindow
 */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), categories(), map(), categories_checkbox(), all_items(){
    ui->setupUi(this);
    setWindowTitle(tr("Thumbnal Browser"));
    directory = new QDir(QDir::currentPath() + "/dataset");
    flowLayout = new QFlowLayout(ui->scrollAreaImagesWidgetContents);
    dialog = new QPixmapDialog();
    load_categories();
    loadAllImages();
    setMinimumSize(500, 180);
}
/**
 * Funzione che apre la dialog dopo un doppio click su un'immagine
 * Permette solo di aprire una dialog alla volta; se si apre un'altra dialog
 * allora la precedente viene chiusa
 */
void MainWindow::showImageInDialog(const QString &path){
    if(dialog->isVisible())
        dialog->close();
    QPixmap img(path);
    dialog->setPixmap(img); //immagine con le dimensioni reali
    dialog->show();
}
/**
 * Funzione che mostra tutte le immagini nel flowlayout
 * (In caso la dialog fosse aperta questa viene chiusa)
 */
void MainWindow::showAllImages(){
    removeItemsFromFlowLayout(); //rimuovo le categorie selezionate precedentemente
    const QCheckBox *checkboxAll = getCheckBoxAll();
    if(all_items.size() == 0){
        QStringList keys = map.keys();
        for(const QString &s : keys){
            for(const QItem &pm: map.value(s))
                all_items.append(pm);

        }
    }

    if(checkboxAll && checkboxAll->checkState() == Qt::Checked) //visualizzo tutte le immagini
        addItemsInFlowLayoutRandom(all_items);

    if(checkboxAll && checkboxAll->checkState() == Qt::Unchecked)
        removeItemsFromFlowLayout();
    dialog->close();
}
/**
 * Funzione che mostra le immagini nel flowlayout in base alle checkbox attive
 * (In caso la dialog fosse aperta questa viene chiusa)
 */
void MainWindow::showImagesByCategory(){
    QList<QItem> list_checked;
    QCheckBox *checkboxAll = getCheckBoxAll();
    QStringList keys = map.keys();
    for(const QCheckBox* const checkbox : categories_checkbox)
        if(checkbox && checkbox->checkState() == Qt::Checked)
            for(const QString &s : keys){
                if(s == checkbox->objectName()){
                    QList<QItem> img = map.value(s);
                    for(const QItem &p: img)
                        list_checked.append(QItem(p.get_image(), s, p.get_image_path()));
                }
            }
    removeItemsFromFlowLayout();
    addItemsInFlowLayout(list_checked);

    if(areAllCheckBoxChecked()) //se tutte le categorie sono attive allora attivo "All"
        checkboxAll->setCheckState(Qt::Checked);
    else
        checkboxAll->setCheckState(Qt::Unchecked);
    dialog->close();
}

/**
 * Funzione che ritona true se tutte le checkBox (esclusa la checkbox "All")
 * sono attive, false altrimenti
 */
bool MainWindow::areAllCheckBoxChecked() const{
    for(const QCheckBox* const checkbox : categories_checkbox)
        if(checkbox && checkbox->objectName() != QString("All")
                && checkbox->checkState() == Qt::Unchecked)
            return false;
    return true;
}

/**
 * Funzione che aggiunge al flowlayout le immagini contenute nella lista
 * La funzione viene chiamata solo quando si selezionano le checkbox delle categorie
 * esclusa la checkbox "All"
 */
void MainWindow::addItemsInFlowLayout(const QList<QItem> &list){
    for(unsigned int i = 0; i < list.size(); ++i){
        QPixmap picture = list.at(i).get_image();
        QPixmapLabel *label_img = new QPixmapLabel();
        label_img->setImage(picture);
        label_img->setScaledContents(true);
        label_img->setPath(list.at(i).get_image_path());
        QLabel *label_categoria = new QLabel(list.at(i).get_category());
        label_categoria->setAlignment(Qt::AlignHCenter);
        QFont font;
        font.setPointSize(10);
        label_categoria->setFont(font);
        QWidget *widget = new QWidget;
        QVBoxLayout *card_view = new QVBoxLayout();
        card_view->addWidget(label_img);
        card_view->addWidget(label_categoria);
        widget->setLayout(card_view);
        flowLayout->addWidget(widget);
        connect(label_img, SIGNAL(doubleClicked(QString)), this, SLOT(showImageInDialog(QString)));
    }
}

/**
 * Funzione che aggiunge al flowlayout in modo random le immagini contenute nella lista
 * La funzione viene chiamata solo quando la checkbox "All" viene attivata
 */
void MainWindow::addItemsInFlowLayoutRandom(const QList<QItem> &list){
    QSet<int> randomNumbers;
    randomNumbers.contains(0);
    for(unsigned int i = 0; i < list.size(); ++i){
        int pos = QRandomGenerator::global()->bounded(0, list.size());
        if(randomNumbers.size() > 0)
            while(randomNumbers.contains(pos))
                pos = QRandomGenerator::global()->bounded(0, list.size()); //intervallo [ 0, list.size() )
        randomNumbers.insert(pos);
        QPixmap picture = list.at(pos).get_image();
        QPixmapLabel *label_img = new QPixmapLabel();
        label_img->setImage(picture);
        label_img->setScaledContents(true);
        label_img->setPath(list.at(pos).get_image_path());
        QLabel *label_categoria = new QLabel(list.at(pos).get_category());
        label_categoria->setAlignment(Qt::AlignHCenter);
        QFont font;
        font.setPointSize(10);
        label_categoria->setFont(font);
        QWidget *widget = new QWidget;    
        QVBoxLayout *card_view = new QVBoxLayout();
        card_view->addWidget(label_img, Qt::AlignVCenter);
        card_view->addWidget(label_categoria);
        widget->setLayout(card_view);
        flowLayout->addWidget(widget);
        connect(label_img, SIGNAL(doubleClicked(QString)), this, SLOT(showImageInDialog(QString)));

    }
}
/**
 * Funzione che rimuove dal flowlayout tutte le immagini
 */
void MainWindow::removeItemsFromFlowLayout(){
    if (flowLayout && flowLayout->layout() != nullptr ){
        QLayoutItem* item;
        while (( item = flowLayout->layout()->takeAt(0)) != nullptr ){
            delete item->widget();
            delete item;
        }
    }
}

/**
 * Funzione che attiva/disattiva le checkbox relative alle categorie
 * se la checkbox "All" si attiva/disattiva
 * (In caso la dialog fosse aperta, viene chiusa)
 */
void MainWindow::changeCheckStateAll(){
    const QCheckBox *checkboxAll = getCheckBoxAll();
    if(checkboxAll && checkboxAll->checkState() == Qt::Unchecked){
        for(QCheckBox* const box: categories_checkbox)
            box->setCheckState(Qt::Unchecked);
        return;
    }

    if(checkboxAll && checkboxAll->checkState() == Qt::Checked){
        for(QCheckBox* const box: categories_checkbox)
            box->setCheckState(Qt::Checked);
        return;
    }
    dialog->close(); //se cambiano le categorie chiudo la dialog
}

/**
 * Funzione che carica in una mappa tutte le immagini appena viene create la MainWindow
 * Le entries della mappa sono coppie <categoria, lista di item>
 */
void MainWindow::loadAllImages(){
    QDirIterator it(directory->path(), QDir::AllEntries | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QString path = it.path();
    QMap<QString, QList<QItem>> data;
    QList<QItem> list;
    while(it.hasNext()){
        path = it.next();// contiene ../dataset lo salto
        QFile file(path);
        QFileInfo info(path);
        QString category(info.baseName());
        if(info.isDir()){
            QDir dir(directory->path()+"/"+category);
            QStringList images = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
            for(const QString &name : images){
                QString fullPathImg = dir.path()+"/"+name;
                QByteArray ext = QFileInfo(fullPathImg).completeSuffix().toUtf8();
                QPixmap img(fullPathImg, ext);
                img = img.scaled(120, 120, Qt::IgnoreAspectRatio, Qt::FastTransformation); //l'immagine con dimensioni reali
                QItem gpm(img, category, fullPathImg);
                list.append(gpm);
            }
            data.insert(info.baseName(), list);
        }
        list.clear();
    }
    map = data;
}

/**
 * Funzione che le legge i nomi delle sottocartelle in "../dataset"
 * e aggiunge al layout delle categorie tutte le checkbox
 */
void MainWindow::load_categories(){
    categories << "All" << directory->entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
    for(const QString &category: categories){
        QCheckBox *checkBox = new QCheckBox(category);
        checkBox->setObjectName(category);
        checkBox->setMinimumSize(QSize(100, 50));
        QFont font;
        font.setPointSize(20);
        checkBox->setFont(font);
        checkBox->setCheckState(Qt::Unchecked);
        checkBox->setStyleSheet("QCheckBox::indicator {width:50px;height: 50px;}"
                                "QCheckBox::indicator:unchecked { image: url(check-box-empty.png);}"
                                "QCheckBox::indicator:checked { image: url(check-box-with-check-sign.png);}");
        categories_checkbox.append(checkBox);
        ui->verticalLayout->addWidget(checkBox);
        if(category == "All"){
            connect(checkBox, &QCheckBox::clicked, this, &MainWindow::changeCheckStateAll);
            connect(checkBox, &QCheckBox::clicked, this, &MainWindow::showAllImages);
        }else
            connect(checkBox, &QCheckBox::clicked, this, &MainWindow::showImagesByCategory);

    }
}

/**
 * Funzione di supporto che ritorna il puntatore alla checkbox "All"
 */
QCheckBox *MainWindow::getCheckBoxAll() const{
    for(QCheckBox *checkbox: categories_checkbox)
        if(checkbox->objectName() == QString("All"))
            return checkbox;

    return nullptr;
}

/**
 * Funzione che calcola che il numeo totale di immagini
 */
unsigned int MainWindow::totalImages() const{
    unsigned int count = 0;
    QStringList keys = map.keys();
    for(const QString &s : keys){
        QList<QItem> img = map.value(s);
        count += img.size();
    }
    return count;
}
/**
 * Distruttore
 */
MainWindow::~MainWindow(){
    removeItemsFromFlowLayout();
    for(QCheckBox *cb: categories_checkbox)
        delete cb;
    delete ui;
    delete flowLayout;
    delete directory;
    delete dialog;
}
/**
 * Funzione che chiude la MainWindow e la dialog se questa è aperta
 */
void MainWindow::closeEvent(QCloseEvent *event){
    dialog->close();
    event->accept();
}






