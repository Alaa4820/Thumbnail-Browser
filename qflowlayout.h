#ifndef QFLOWLAYOUT_H
#define QFLOWLAYOUT_H

#include <QLayout>
#include <QRect>
#include <QStyle>
/**
 * @brief Classe che implementa una layout
 * che adatta i suoi widget in modo dimanico
 *
 * MOTA: la classe è un'implementazione fornita da QtCreator (sezione esempi)
 */
class QFlowLayout : public QLayout{
public:
    explicit QFlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    explicit QFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~QFlowLayout();

    void addItem(QLayoutItem *item) override;
    int horizontalSpacing() const;
    int verticalSpacing() const;
    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int) const override;
    int count() const override;
    QLayoutItem *itemAt(int index) const override;
    QSize minimumSize() const override;
    void setGeometry(const QRect &rect) override;
    QSize sizeHint() const override;
    QLayoutItem *takeAt(int index) override;

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem *> itemList;
    int m_hSpace;
    int m_vSpace;
};

#endif // QFLOWLAYOUT_H
