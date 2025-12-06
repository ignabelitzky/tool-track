QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/core/AppController.cpp \
    src/core/DBMigrationService.cpp \
    src/core/Dashboard.cpp \
    src/core/DatabaseManager.cpp \
    src/dao/CheckoutDAO.cpp \
    src/dao/InstitutionsDAO.cpp \
    src/dao/ItemStatesDAO.cpp \
    src/dao/ItemTypesDAO.cpp \
    src/dao/ItemsDAO.cpp \
    src/dao/LocationsDAO.cpp \
    src/dao/OwnerTypesDAO.cpp \
    src/dao/PersonsDAO.cpp \
    src/dao/UsersDAO.cpp \
    src/dialogs/NewInstitutionDialog.cpp \
    src/dialogs/NewItemDialog.cpp \
    src/dialogs/NewPersonDialog.cpp \
    src/dialogs/NewUserDialog.cpp \
    src/models/CartTableModel.cpp \
    src/models/InstitutionsProxyModel.cpp \
    src/models/InstitutionsTableModel.cpp \
    src/models/Item.cpp \
    src/models/ItemsProxyModel.cpp \
    src/models/ItemsTableModel.cpp \
    src/models/PersonsProxyModel.cpp \
    src/models/PersonsTableModel.cpp \
    src/models/User.cpp \
    src/models/UsersProxyModel.cpp \
    src/models/UsersTableModel.cpp \
    src/pages/CheckoutPage.cpp \
    src/pages/ItemsPage.cpp \
    src/pages/OwnersPage.cpp \
    src/pages/UsersPage.cpp

HEADERS += \
    src/core/AppController.h \
    src/core/DBMigrationService.h \
    src/core/Dashboard.h \
    src/core/DatabaseManager.h \
    src/dao/CheckoutDAO.h \
    src/dao/InstitutionsDAO.h \
    src/dao/ItemStatesDAO.h \
    src/dao/ItemTypesDAO.h \
    src/dao/ItemsDAO.h \
    src/dao/LocationsDAO.h \
    src/dao/OwnerTypesDAO.h \
    src/dao/PersonsDAO.h \
    src/dao/UsersDAO.h \
    src/dialogs/NewInstitutionDialog.h \
    src/dialogs/NewItemDialog.h \
    src/dialogs/NewPersonDialog.h \
    src/dialogs/NewUserDialog.h \
    src/models/CartTableModel.h \
    src/models/InstitutionsProxyModel.h \
    src/models/InstitutionsTableModel.h \
    src/models/Item.h \
    src/models/ItemsProxyModel.h \
    src/models/ItemsTableModel.h \
    src/models/PersonsProxyModel.h \
    src/models/PersonsTableModel.h \
    src/models/User.h \
    src/models/UsersProxyModel.h \
    src/models/UsersTableModel.h \
    src/pages/CheckoutPage.h \
    src/pages/ItemsPage.h \
    src/pages/OwnersPage.h \
    src/pages/UsersPage.h

FORMS += \
    src/dialogs/NewInstitutionDialog.ui \
    src/dialogs/NewItemDialog.ui \
    src/dialogs/NewPersonDialog.ui \
    src/dialogs/NewUserDialog.ui \
    src/pages/CheckoutPage.ui \
    src/pages/ItemsPage.ui \
    src/pages/OwnersPage.ui \
    src/pages/UsersPage.ui \
    src/ui/Dashboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
