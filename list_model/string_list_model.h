#ifndef STRING_LIST_MODEL_H
#define STRING_LIST_MODEL_H

#include <QAbstractListModel>
#include<QStringList>

class string_list_model : public QAbstractListModel
{
    Q_OBJECT
public:
    string_list_model(const QStringList& strings,QObject * parent=nullptr);

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    bool insert_rows(int position,int rows,const QModelIndex&index=QModelIndex());
    bool remove_rows(int position,int rows,const QModelIndex&index=QModelIndex());
    Qt::ItemFlags flags(const QModelIndex &index) const override;
private:
    QStringList string_list;


};

#endif // STRING_LIST_MODEL_H
