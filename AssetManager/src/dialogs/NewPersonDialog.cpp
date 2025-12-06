#include <QMessageBox>
#include <QRegularExpression>
#include "NewPersonDialog.h"
#include "ui_NewPersonDialog.h"

NewPersonDialog::NewPersonDialog(PersonsDAO& personsDAO,
                                 QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewPersonDialog)
    , m_personsDAO(personsDAO)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &NewPersonDialog::onSave);
    connect(ui->cancelButton, &QPushButton::clicked, this, &NewPersonDialog::reject);

    setWindowTitle("Nueva Persona");
}

NewPersonDialog::~NewPersonDialog()
{
    delete ui;
}

void NewPersonDialog::loadPerson(int personId)
{
    m_personId = personId;

    Person person = m_personsDAO.getById(m_personId);
    if (person.firstName.isEmpty() || person.lastName.isEmpty())
        return;

    ui->firstNameLineEdit->setText(person.firstName);
    ui->lastNameLineEdit->setText(person.lastName);

    setWindowTitle("Editar persona");
}

void NewPersonDialog::onSave()
{
    QString errorMessage;
    if (!validateInput(errorMessage))
    {
        QMessageBox::warning(this, "Error de validación", errorMessage);
        return;
    }

    Person person;
    person.firstName = ui->firstNameLineEdit->text();
    person.lastName = ui->lastNameLineEdit->text();

    bool success = false;
    if (m_personId <= 0)
        success = m_personsDAO.insert(person.firstName, person.lastName);
    else
        success = m_personsDAO.update(m_personId, person.firstName, person.lastName);

    if (!success)
    {
        QMessageBox::critical(this, "Error", "No se puede guardar la persona.");
        return;
    }

    accept();
}

bool NewPersonDialog::validateInput(QString& errorMessage) const
{
    const QString firstName = ui->firstNameLineEdit->text().trimmed();
    const QString lastName = ui->lastNameLineEdit->text().trimmed();

    if (firstName.isEmpty())
    {
        errorMessage = "El nombre no puede estar vacío";
        return false;
    }

    if (firstName.length() > 50)
    {
        errorMessage = "El nombre no puede superar los 50 caracteres";
        return false;
    }

    if (!QRegularExpression("^[A-Za-zÁÉÍÓÚáéíóúÑñ ]+$").match(firstName).hasMatch())
    {
        errorMessage = "El nombre contiene caracteres no permitidos";
        return false;
    }

    if (lastName.isEmpty())
    {
        errorMessage = "El apellido no puede estar vacío";
        return false;
    }

    if (lastName.length() > 50)
    {
        errorMessage = "El apellido no puede superar los 50 caracteres";
        return false;
    }

    if (!QRegularExpression("^[A-Za-zÁÉÍÓÚáéíóúÑñ ]+$").match(lastName).hasMatch())
    {
        errorMessage = "El apellido contiene caracteres no permitidos";
        return false;
    }

    return true;
}
