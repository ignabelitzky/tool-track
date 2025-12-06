#pragma once

#include <QObject>
#include <QSortFilterProxyModel>

class InstitutionsProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit InstitutionsProxyModel(QObject *parent = nullptr);

    void setFilterText(const QString& text);

protected:
    bool filterAcceptsRow(int sourceRow,
                          const QModelIndex& sourceParent) const;
};
