#pragma once

#include <QDialog>
#include "src/dao/PersonsDAO.h"

namespace Ui {
class NewPersonDialog;
}

class NewPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPersonDialog(PersonsDAO& personsDAO,
                             QWidget *parent = nullptr);
    ~NewPersonDialog();

    void loadPerson(int personId);

private slots:
    void onSave();

private:
    bool validateInput(QString& errorMessage) const;

private:
    Ui::NewPersonDialog *ui;
    PersonsDAO& m_personsDAO;
    int m_personId{-1};
};
