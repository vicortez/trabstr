#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "conjunto_processos.h"
#include <string>
#include <thread>
#include <QThread>

#include <QStandardItem>

using namespace std;


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

    model->setColumnCount(4);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Uso de CPU")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Status")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Comando")));


    //processTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //model->appendRow(currentProcessList);


    //thread t1(&MainWindow::print_table);
    //t1.join();

    //QThread* t1(&MainWindow::print_table, pointer);
    //t1->start();
    print_table();



    //ui->tableView->setModel(model);
    //std::cout << processTable->verticalHeader();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_table(){
    Processo* currentProcess = new Processo();
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();
    QStandardItemModel* model = new QStandardItemModel(this);
    QTableView* processTable = ui->tableView;

    setWindowTitle("BetterHtop");

    model->setColumnCount(4);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Uso de CPU")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Status")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Comando")));


    for(int i=0; i < conjuntoProcessos->programas.size(); i++){
        QList<QStandardItem *> currentProcessList;
        currentProcess->setPID(conjuntoProcessos->programas.at(i).getPID());
        currentProcess->setCPU_USAGE(conjuntoProcessos->programas.at(i).getCPU_USAGE());
        currentProcess->setEstado(conjuntoProcessos->programas.at(i).getEstado());
        currentProcess->setComando(conjuntoProcessos->programas.at(i).getComando());

        currentProcessList.append(new QStandardItem(QString::fromStdString(to_string(currentProcess->getPID()))));
        currentProcessList.append(new QStandardItem(QString::fromStdString(to_string(currentProcess->getCPU_USAGE()))));
        currentProcessList.append(new QStandardItem(QString::fromStdString(currentProcess->getEstado())));
        currentProcessList.append(new QStandardItem(QString::fromStdString(currentProcess->getComando())));



        model->appendRow(currentProcessList);
        ui->tableView->setModel(model);

    }
}

//======================================
//junk code
//TABLE CODE EXAMPLES
// QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
//QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
//model->setItem(0,0,firstRow);
