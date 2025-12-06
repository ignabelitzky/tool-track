#pragma once

#include <QDialog>
#include "src/dao/InstitutionsDAO.h"

namespace Ui {
class NewInstitutionDialog;
}

class NewInstitutionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewInstitutionDialog(InstitutionsDAO& institutionsDAO,
                                  QWidget *parent = nullptr);
    ~NewInstitutionDialog();

    void loadInstitution(int institutionId);

private slots:
    void onSave();

private:
    bool validateInput(QString& errorMessage) const;

private:
    Ui::NewInstitutionDialog *ui;
    InstitutionsDAO& m_institutionsDAO;
    int m_institutionId{-1};
};
