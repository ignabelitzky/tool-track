#include "PersonsTableModel.h"

PersonsTableModel::PersonsTableModel(PersonsDAO& personsDAO,
                                     QObject *parent)
    : QAbstractTableModel{parent}
    , m_personsDAO{personsDAO}
{
    refresh();
}

int PersonsTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_persons.size();
}

int PersonsTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return COLUMN_COUNT;
}

QVariant PersonsTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    if (!index.isValid() || index.row() >= m_persons.size())
        return QVariant();

    const Person& person = m_persons[index.row()];

    if (role == Qt::UserRole)
        return person.id;

    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case FirstName:
            return person.firstName;
        case LastName:
            return person.lastName;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant PersonsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case FirstName:
            return "Nombre";
        case LastName:
            return "Apellido";
        default:
            return QVariant();
        }
    }
    return section + 1;
}

void PersonsTableModel::refresh()
{
    beginResetModel();
    m_persons = m_personsDAO.getAll();
    endResetModel();
}

const Person& PersonsTableModel::getPerson(int row) const
{
    if (row < 0 || row >= m_persons.size())
    {
        static Person emptyPerson;
        return emptyPerson;
    }
    return m_persons[row];
}
