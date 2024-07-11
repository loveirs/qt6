#include "spinboxdele.h"
#include<QSpinBox>
spinboxdele::spinboxdele(QObject* parent):QItemDelegate(parent) {

}

QWidget *spinboxdele::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void spinboxdele::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int val=index.model()->data(index,Qt::EditRole).toInt();
    auto * spinbox= static_cast<QSpinBox*>(editor);
    spinbox->setValue(val);
}

void spinboxdele::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto *spinbox=static_cast<QSpinBox*>(editor);
    spinbox->interpretText();
    int val=spinbox->value();
    model->setData(index,val,Qt::EditRole);

}

void spinboxdele::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
