#include "mainwindow.hxx"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(run()));
    inputReader = ReaderType::New();
    outputWriter = WriterType::New();
    filter = FilterType::New();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    // Load the image
    inputReader->SetFileName(this->ui->inputPath->text().toStdString());
    inputReader->Update();

    // Create the filter
    filter->SetKernelSize(this->ui->horizontalSlider->sliderPosition());
    filter->SetInput(inputReader->GetOutput());
    filter->Update();

    // Write image
    outputWriter->SetFileName(this->ui->inputPath->text().toStdString());
    outputWriter->SetInput(filter->GetOutput());
    outputWriter->Update();
    close();
}
