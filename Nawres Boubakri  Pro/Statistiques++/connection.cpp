#include "connection.h"
#include <QSqlError>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("nawres");//inserer nom de l'utilisateur
db.setPassword("nawres");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
bool Connection::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("test-bd");
                           db.setUserName("nawres");//inserer nom de l'utilisateur
                           db.setPassword("nawres");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connection::fermerConnexion()
{db.close();}
