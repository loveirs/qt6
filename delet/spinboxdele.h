#ifndef SPINBOXDELE_H
#define SPINBOXDELE_H

#include <QItemDelegate>
// #include <QQmlEngine>

class spinboxdele : public QItemDelegate
{
    // QML_ELEMENT
    Q_OBJECT
public:
    spinboxdele(QObject* parent = 0);
    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // SPINBOXDELE_H
