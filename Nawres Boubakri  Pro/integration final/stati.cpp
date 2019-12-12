#include "stati.h"
#include "ui_stati.h"

stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}


int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FOURNITURE where QUANT_FOURN BETWEEN '100' AND '200'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FOURNITURE where QUANT_FOURN BETWEEN '201' AND '500'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;

        float s2= b*100 ;
        float s3=c*100;

        float nb = b+c;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;

    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-100,this->width()-100);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);

    ui->label_2->setText("100-200") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("201-500") ;


}



void stati::on_pushButton_clicked()
{
     hide();
}
