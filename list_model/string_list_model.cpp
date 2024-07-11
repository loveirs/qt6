#include "string_list_model.h"


string_list_model::string_list_model(const QStringList &strings, QObject *parent):
    QAbstractListModel(parent),string_list(strings)
{

}

QVariant string_list_model::data(const QModelIndex &index, int role) const //根据索引获取数据
{
    if(!index.isValid()){
        return QVariant();
    }

    if(index.row()>=string_list.size()){
        return QVariant();
    }

    if(role==Qt::DisplayRole||role==Qt::EditRole){
        return string_list.at(index.row());
    }else
        return QVariant();
}

bool string_list_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid()&&role==Qt::EditRole){
        string_list.replace(index.row(),value.toString());
        emit dataChanged(index,index);
        return true;
    }
    return false;
}

int string_list_model::rowCount(const QModelIndex &parent) const
{
    return string_list.count();
}

QVariant string_list_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    //判断横向还是纵向
    if(role!=Qt::DisplayRole){
        return QVariant();
    }
    if(orientation==Qt::Horizontal){ //横向则显示列号
        return QString("column %1").arg(section);

    }else{
        return QString("row %1").arg(section);
    }
}

bool string_list_model::insert_rows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(),position,position+rows-1);

    for(int row=0;row<rows;++row){
        string_list.insert(position+row,QString::number(row));
    }
    endInsertRows();
    return true;
}

bool string_list_model::remove_rows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(),position,position+rows-1);

    for(int row=0;row<rows;++row){
        string_list.removeAt(position);
    }
    endRemoveRows();
    return true;
}

Qt::ItemFlags string_list_model::flags(const QModelIndex &index) const
{
    if(!index.isValid()){
        return Qt::ItemIsEnabled;

    }

    return QAbstractItemModel::flags(index)|Qt::ItemIsEditable;
}
