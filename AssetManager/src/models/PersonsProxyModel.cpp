#include "PersonsProxyModel.h"

PersonsProxyModel::PersonsProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setDynamicSortFilter(true);
}

void PersonsProxyModel::setFilterText(const QString& text)
{
    setFilterFixedString(text);
    invalidateFilter();
}

bool PersonsProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    if (filterRegularExpression().pattern().isEmpty())
        return true;

    for (int col = 0; col < 2; ++col)
    {
        QModelIndex index = sourceModel()->index(sourceRow, col, sourceParent);
        QString value = sourceModel()->data(index, Qt::DisplayRole).toString();

        if (value.contains(m_filterText, Qt::CaseInsensitive))
            return true;
    }
    return false;
}
