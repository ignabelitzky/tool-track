#include "InstitutionsProxyModel.h"
#include <QAbstractItemModel>

InstitutionsProxyModel::InstitutionsProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setDynamicSortFilter(true);
}

void InstitutionsProxyModel::setFilterText(const QString& text)
{
    setFilterFixedString(text);
    invalidateFilter();
}

bool InstitutionsProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    if (filterRegularExpression().pattern().isEmpty())
        return true;

    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    QString name = sourceModel()->data(index).toString();

    return name.contains(filterRegularExpression());
}
