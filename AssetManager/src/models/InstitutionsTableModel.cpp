#include "InstitutionsTableModel.h"

InstitutionsTableModel::InstitutionsTableModel(InstitutionsDAO& institutionsDAO,
                                               QObject *parent)
    : QAbstractTableModel{parent}
    , m_institutionsDAO{institutionsDAO}
{
    refresh();
}

int InstitutionsTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_institutions.size();
}

int InstitutionsTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return COLUMN_COUNT;
}

QVariant InstitutionsTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    if (!index.isValid() || index.row() >= m_institutions.size())
        return QVariant();

    const Institution& institution = m_institutions[index.row()];

    if (role == Qt::UserRole)
        return institution.id;

    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case Name:
            return institution.name;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant InstitutionsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case Name:
            return "Nombre";
        default:
            return QVariant();
        }
    }
    return section + 1;
}

void InstitutionsTableModel::refresh()
{
    beginResetModel();
    m_institutions = m_institutionsDAO.getAll();
    endResetModel();
}

const Institution& InstitutionsTableModel::getInstitution(int row) const
{
    if (row < 0 || row >= m_institutions.size())
    {
        static Institution emptyInstitution;
        return emptyInstitution;
    }
    return m_institutions[row];
}
