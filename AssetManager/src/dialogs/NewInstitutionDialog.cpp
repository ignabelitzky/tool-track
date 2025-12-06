#include <QRegularExpression>
#include <QMessageBox>
#include "NewInstitutionDialog.h"
#include "ui_NewInstitutionDialog.h"


NewInstitutionDialog::NewInstitutionDialog(InstitutionsDAO& institutionsDAO,
                                           QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewInstitutionDialog)
    , m_institutionsDAO(institutionsDAO)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &NewInstitutionDialog::onSave);
    connect(ui->cancelButton, &QPushButton::clicked, this, &NewInstitutionDialog::reject);

    setWindowTitle("Nueva Institución");
}

NewInstitutionDialog::~NewInstitutionDialog()
{
        delete ui;
}

void NewInstitutionDialog::loadInstitution(int institutionId)
{
    m_institutionId = institutionId;

    Institution institution = m_institutionsDAO.getById(m_institutionId);
    if (institution.name.isEmpty())
        return;

    ui->institutionNameLineEdit->setText(institution.name);

    setWindowTitle("Editar Institución");
}

void NewInstitutionDialog::onSave()
{
    QString errorMessage;
    if (!validateInput(errorMessage))
    {
        QMessageBox::warning(this, "Error de validación", errorMessage);
        return;
    }

    Institution institution;
    institution.name = ui->institutionNameLineEdit->text();

    bool success = false;
    if (m_institutionId <= 0)
        success = m_institutionsDAO.insert(institution.name);
    else
        success = m_institutionsDAO.update(m_institutionId, institution.name);

    if (!success)
    {
        QMessageBox::critical(this, "Error", "No se puede guardar la institución.");
        return;
    }

    accept();
}

bool NewInstitutionDialog::validateInput(QString& errorMessage) const
{
    const QString name = ui->institutionNameLineEdit->text().trimmed();

    if (name.isEmpty())
    {
        errorMessage = "El nombre no puede estar vacío";
        return false;
    }

    if (name.length() > 120)
    {
        errorMessage = "El nombre no puede superar los 120 caracteres";
        return false;
    }

    if (!QRegularExpression("^[A-Za-zÁÉÍÓÚáéíóúÑñ ]+$").match(name).hasMatch())
    {
        errorMessage = "El nombre contiene caracteres no permitidos";
        return false;
    }

    return true;
}
