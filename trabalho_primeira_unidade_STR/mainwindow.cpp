#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "conjunto_processos.h"
#include <string>

#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Processo* currentProcess = new Processo();
    QTableView* processTable = ui->tableView;
    //QList<QStandardItem *> currentProcessList;
    QStandardItemModel* model = new QStandardItemModel(this);

    ui->setupUi(this);

    setWindowTitle("BetterHtop");

    model->setColumnCount(3);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    //processTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //currentProcessList.append(new QStandardItem("Column 1 Text"));
    //currentProcessList.append(new QStandardItem("Column 2 Text"));
   //currentProcessList.append(new QStandardItem("Column 3 Text"));

    //model->appendRow(currentProcessList);
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();
    //std::cout << conjuntoProcessos->programas.at(230).getPID();

    for(int i=0; i < conjuntoProcessos->programas.size(); i++){
        QList<QStandardItem *> currentProcessList;
        currentProcess->setPID(conjuntoProcessos->programas.at(i).getPID());
        currentProcess->setCPU_USAGE(conjuntoProcessos->programas.at(i).getCPU_USAGE());

        currentProcessList.append(new QStandardItem(currentProcess->getPID()));
        currentProcessList.append(new QStandardItem(currentProcess->getCPU_USAGE()));
        currentProcessList.append(new QStandardItem(to_string(42));



        model->appendRow(currentProcessList);
        ui->tableView->setModel(model);

    }





    ui->tableView->setModel(model);
    //std::cout << processTable->verticalHeader();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//======================================
//junk code
//TABLE CODE EXAMPLES
// QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
//QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
//model->setItem(0,0,firstRow);
