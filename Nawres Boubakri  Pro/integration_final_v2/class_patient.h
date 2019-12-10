#ifndef CLASS_PATIENT_H
#define CLASS_PATIENT_H
#include<QString>
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
    QString sexe;
public:
    class_patient();
    class_patient(int,QString,QString, QString,int,QString,QString );
    int get_id();
    QString get_nom();
    QString get_prenom();
     QString get_date();
    int get_tel();
    QString get_adresse();
      QString get_sexe();
    bool ajouter();
     bool modifier(int,QString,QString, QString,int,QString,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trier();
      QSqlQueryModel * rechercher(int);

    bool supprimer(int);
};

#endif // CLASS_PATIENT_H
