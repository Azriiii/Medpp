#ifndef CLASS_PATIENT_H
#define CLASS_PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class class_patient
{
    int id_patient;
    QString nom_patient;
    QString prenom_patient;
     QString date_patient;
    int tel_patient;
    QString adresse;
public:
    class_patient();
    class_patient(int,QString,QString, QString,int,QString );
    int get_id();
    QString get_nom();
    QString get_prenom();
     QString get_date();
    int get_tel();
    QString get_adresse();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier();
      QSqlQueryModel * showidpatient();

    bool supprimer(int);
    bool update();
};

#endif // CLASS_PATIENT_H
