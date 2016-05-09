
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // LIST OF TABS
    // ---------------------------------------------------------------------------------------------------------------------------------->>
    // List views are only representations of data models. In the h file we created a pointer to the QStringListModel class
    // which we now instantiate
    listViewWestModel = new QStringListModel(this);
    // Make data list
    QStringList strList;
    strList << "Radio" << "Motors" << "Lights & IO" << "Functions" << "Driving" << "Battle" << "Sounds" << "Misc" << "Firmware";
    // Populate our model
    listViewWestModel->setStringList(strList);
    // Glue model and view together
    ui->listViewWest->setModel(listViewWestModel);
    // Select the first item.
    ui->listViewWest->setCurrentIndex(listViewWestModel->index(0,0));

    // Let's connect the listview and stacked widget.
    // QListView really doesn't have any signals that are worth a damn. Nor can we use a signal from QStringListModel object. Instead
    // we must use a signal from the more generic QItemSelectionModel which we point to our list view selection model
    // Now this signal works and passes both current and previous index numbers to our created function called changeStackedWidget.
    // We only need to use the new "current" index and set the stacked widget to that same index.
    QItemSelectionModel *selectionModel = ui->listViewWest->selectionModel();
    connect(selectionModel, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(changeStackedWidget(QModelIndex,QModelIndex)));

    // Uncomment the below if compiling with Qt 5.6
    // In Qt 5.6 whenever we click on the list view, it would select two items - the one you wanted to select, and the next one too.
    // This doesn't look right. If we use this second signal to re-assert the listView selected item, we can sort of work around it.
    // You get some flickering but it does work.
    //connect(ui->listViewWest, SIGNAL(clicked(QModelIndex)), this, SLOT(changeStackedWidget56Fix(QModelIndex)));


    // Go back to first tab of listview in case we got off it during setup
    // ---------------------------------------------------------------------------------------------------------------------------------->>
    // You actually have to set two things - the listview along the side (why I called it West), but programmatically that won't automatically
    // trigger the stacked widget change the way a click will. So we also set the stacked widget explicitly.
      ui->listViewWest->setCurrentIndex(listViewWestModel->index(0,0));
      ui->stackedWidgetMain->setCurrentIndex(0);
      qApp->processEvents();  // Equivalent of VB DoEvents()

}

MainWindow::~MainWindow()
{   // Destructor.
    delete ui;
}

void MainWindow::changeStackedWidget(const QModelIndex& current, const QModelIndex& )
{
    // This function changes the current tab when the user clicks on an item in the listview

    // Set the stacked widget to the page passed by current index
    ui->stackedWidgetMain->setCurrentIndex(current.row());
    // Set focus to any old thing so there isn't an ugly looking square around the text we just clicked
    ui->stackedWidgetMain->setFocus();
}

// Uncomment the below if compiling in Qt 5.6
/*void MainWindow::changeStackedWidget56Fix(const QModelIndex& current)
{
    // In Qt 5.6, there is a bug that will highlight both the current listView item and the one after it, whenever
    // you click on it. I was able to work around this by adding a second signal from listViewWest clicked that
    // calls this slot. It causes a flicker because the second item is still selected, but then this one de-selects it.
    ui->listViewWest->setCurrentIndex(current);
    qApp->processEvents();  // Equivalent of VB DoEvents()
}*/
