#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "conjunto_processos.h"
#include <string>
#include <thread>
#include <QThread>
#include <QTimer>

#include <QStandardItem>

using namespace std;

string filter="";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Processo* currentProcess = new Processo();
    QTableView* processTable = ui->tableView;
    QLineEdit* pidLineEdit = ui->pidLineEdit;
    //Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(print_table()));
    timer->start(1000);

    ui->setupUi(this);

    setWindowTitle("BetterHtop");

    print_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//executes every second, iterates trough all procesess and prints them on the table if the
//filter field is contained in the command field of each process
void MainWindow::print_table(){
    Processo* currentProcess = new Processo();
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();
    QStandardItemModel* model = new QStandardItemModel(this);
    QTableView* processTable = ui->tableView;
    QLineEdit* filterLineEdit = ui->lineEdit_2;

    setWindowTitle("BetterHtop");

    model->clear();

    model->setColumnCount(4);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Uso de CPU")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Status")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Comando")));


    for(int i=0; i < conjuntoProcessos->programas.size(); i++){
        if(conjuntoProcessos->programas.at(i).getComando().find(filter) != std::string::npos){
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
        }
    }
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_clicked()
{
    QLineEdit* pidLineEdit = ui->pidLineEdit;
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();

    conjuntoProcessos->kill_process(pidLineEdit->text().toInt());
}

void MainWindow::on_pushButton_2_clicked()
{
    QLineEdit* pidLineEdit = ui->pidLineEdit;
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();

    conjuntoProcessos->pause_process(pidLineEdit->text().toInt());

}

void MainWindow::on_pushButton_3_clicked()
{
    QLineEdit* pidLineEdit = ui->pidLineEdit;
    Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();

    conjuntoProcessos->continue_process(pidLineEdit->text().toInt());
}

void MainWindow::on_pushButton_5_clicked()
{
    QLineEdit* filterLineEdit = ui->lineEdit_2;
    filter = filterLineEdit->text().toStdString();
}

//======================================
//junk code
//TABLE CODE EXAMPLES
// QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
//QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
//model->setItem(0,0,firstRow);
//processTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//model->appendRow(currentProcessList);
//QList<QStandardItem *> currentProcessList;
//QStandardItemModel* model = new QStandardItemModel(this);
//ui->tableView->setModel(model);
//std::cout << processTable->verticalHeader();
