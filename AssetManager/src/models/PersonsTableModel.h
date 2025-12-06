#pragma once

#include <QAbstractTableModel>
#include <QObject>
#include "src/dao/PersonsDAO.h"

class PersonsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit PersonsTableModel(PersonsDAO& personsDAO,
                               QObject *parent = nullptr);
    ~PersonsTableModel() = default;

    enum {
        FirstName,
        LastName,
        COLUMN_COUNT
    };

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    // Custom actions
    void refresh();
    const Person& getPerson(int row) const;

private:
    PersonsDAO& m_personsDAO;
    QVector<Person> m_persons;
};
