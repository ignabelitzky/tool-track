#pragma once

#include <QAbstractTableModel>
#include <QObject>
#include "src/dao/InstitutionsDAO.h"

class InstitutionsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit InstitutionsTableModel(InstitutionsDAO& institutionsDAO,
                                    QObject *parent = nullptr);
    ~InstitutionsTableModel() = default;

    enum {
        Name,
        COLUMN_COUNT
    };

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    // Custom actions
    void refresh();
    const Institution& getInstitution(int row) const;

private:
    InstitutionsDAO& m_institutionsDAO;
    QVector<Institution> m_institutions;
};
