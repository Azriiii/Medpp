#include "equipement.h"

equipement::equipement()
{
    Ref_equip=0;
    type_equip="";
    quant_equip=0;
    prix=0;
   }
   equipement::equipement(int Ref_equip,QString type_equip,int quant_equip,int prix)
   {
     this->Ref_equip=Ref_equip;
     this->type_equip=type_equip;
     this->quant_equip=quant_equip;
     this->prix=prix;


   }
   int equipement::get_Ref_equip(){return  Ref_equip;}
   QString equipement::get_type_equip(){return type_equip;}
   int equipement::get_quant_equip(){return  quant_equip;}
   int equipement::get_prix(){return prix;}


   bool equipement::ajouter()
   {
       QSqlQuery query;

       QString res1= QString::number(Ref_equip);
       QString res2= QString::number(quant_equip);
       QString res3= QString::number(prix);


       query.prepare("INSERT INTO EQUIPEMENT ( REF_EQUIP, TYPE_EQUIP, QUANT_EQUIP, PRIX ) "
                           "VALUES (:Ref_equip, :type_equip, :quant_equip, :prix)");

       query.bindValue(":Ref_equip", Ref_equip);
       query.bindValue(":type_equip",type_equip);
       query.bindValue(":quant_equip", quant_equip);
       query.bindValue(":prix", prix);

       return    query.exec();
   }

   QSqlQueryModel *equipement::afficher()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from EQUIPEMENT ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EQUIP"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANT_EQUIP"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

       return model;
   }

   bool equipement::supprimer(int Reff)
   {
   QSqlQuery query;
   QString res= QString::number(Reff);
   query.prepare("Delete from EQUIPEMENT where REF_EQUIP = :Ref_equip ");
   query.bindValue(":Ref_equip", res);
   return    query.exec();

}
