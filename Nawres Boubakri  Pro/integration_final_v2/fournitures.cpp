#include "fournitures.h"

fournitures::fournitures()
{
     Ref_fourn=0;
     type_fourn="";
     quant_fourn=0;
     prix=0;
     nom_fourn="";
    }
    fournitures::fournitures(int Ref_fourn,QString nom_fourn,QString type_fourn,int quant_fourn,int prix)
    {
      this->Ref_fourn=Ref_fourn;
      this->nom_fourn=nom_fourn;
      this->type_fourn=type_fourn;
      this->quant_fourn=quant_fourn;
      this->prix=prix;


    }
    int fournitures::get_Ref_fourn(){return  Ref_fourn;}
    QString fournitures::get_nom_fourn(){return nom_fourn;}
    QString fournitures::get_type_fourn(){return type_fourn;}
    int fournitures::get_quant_fourn(){return  quant_fourn;}
    int fournitures::get_prix(){return prix;}


    bool fournitures::ajouter()
    {
        QSqlQuery query;
        QSqlQuery query_;

        QString res1= QString::number(Ref_fourn);
        QString res2= QString::number(quant_fourn);
        QString res3= QString::number(prix);
        fournitures F;

        if(F.recherche_id(Ref_fourn)==0)


       { query.prepare("INSERT INTO FOURNITURE ( REF_FOURN, NOM_FOURN, TYPE_FOURN, QUANT_FOURN, PRIX ) "
                            "VALUES (:Ref_fourn, :nom_fourn, :type_fourn, :quant_fourn, :prix)");

        query.bindValue(":Ref_fourn", Ref_fourn);
        query.bindValue(":nom_fourn", nom_fourn);
        query.bindValue(":type_fourn",type_fourn);
        query.bindValue(":quant_fourn", quant_fourn);
        query.bindValue(":prix", prix);
        }

        return    query.exec();
    }

    QSqlQueryModel *fournitures::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNITURE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_FOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANT_FOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

        return model;
    }

    bool fournitures::supprimer(int Reff)
    {
    QSqlQuery query;
    QString res= QString::number(Reff);
    query.prepare("Delete from FOURNITURE where REF_FOURN = :Ref_fourn ");
    query.bindValue(":Ref_fourn", res);
    return    query.exec();
}

    int fournitures::recherche_id(int idd)
    {
        QSqlQuery query;
        int count=0;
        bool test=0;
       QString idb=QString :: number(idd);
       if(query.exec("select REF_FOURN from FOURNITURE where REF_FOURN="+idb+""))
        {
            while(query.next())
                count++;
            if(count>=1)
                test=1;

        }
        return test;




    }


