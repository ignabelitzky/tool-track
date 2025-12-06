#pragma once

#include <QWidget>
#include "src/dao/PersonsDAO.h"
#include "src/dao/InstitutionsDAO.h"
#include "src/models/PersonsTableModel.h"
#include "src/models/PersonsProxyModel.h"
#include "src/models/InstitutionsTableModel.h"
#include "src/models/InstitutionsProxyModel.h"

namespace Ui {
class OwnersPage;
}

class OwnersPage : public QWidget
{
    Q_OBJECT

public:
    explicit OwnersPage(PersonsDAO& personsDAO,
                        InstitutionsDAO& institutionsDAO,
                        QWidget *parent = nullptr);
    ~OwnersPage();

private slots:
    void onPersonsSelectionChanged(const QItemSelection& selected,
                                   const QItemSelection& deselected);
    void onNewPersonClicked();
    void onEditPersonClicked();
    void onDeletePersonClicked();
    void onRefreshPersonsClicked();

    void onInstitutionsSelectionChanged(const QItemSelection& selected,
                                        const QItemSelection& deselected);
    void onNewInstitutionClicked();
    void onEditInstitutionClicked();
    void onDeleteInstitutionClicked();
    void onRefreshInstitutionsClicked();

private:
    void setupPersonsTable();
    void setupInstitutionsTable();
    void setupConnections();
    void reconnectPersonsSelectionModel();
    void reconnectInstitutionsSelectionModel();
    int getSelectedPersonId() const;
    int getSelectedInstitutionId() const;

private:
    Ui::OwnersPage *ui;
    PersonsDAO& m_personsDAO;
    InstitutionsDAO& m_institutionsDAO;
    PersonsTableModel* m_personsModel;
    PersonsProxyModel* m_personsProxy;
    InstitutionsTableModel* m_institutionsModel;
    InstitutionsProxyModel* m_institutionsProxy;
};
