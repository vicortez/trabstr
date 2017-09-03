#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "conjunto_processos.h"

#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTableView *processTable = ui->tableView;
    QList<QStandardItem *> programsList;
    QStandardItemModel* model = new QStandardItemModel(this);

    ui->setupUi(this);

    setWindowTitle("BetterHtop");

    model->setColumnCount(3);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    //processTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    programsList.append(new QStandardItem("Column 1 Text"));
    programsList.append(new QStandardItem("Column 2 Text"));
    programsList.append(new QStandardItem("Column 3 Text"));

    model->appendRow(programsList);
    //Conjunto_Processos* conjuntoProcessos = new Conjunto_Processos();
    //std::cout << conjuntoProcessos;




    ui->tableView->setModel(model);
    std::cout << processTable->verticalHeader();


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
