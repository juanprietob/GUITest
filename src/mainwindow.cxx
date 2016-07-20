#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    this->setupUi( this );
    connect(this->pushButton,SIGNAL(clicked()),this,SLOT(run()));
    inputReader = ReaderType::New();
    outputWriter = WriterType::New();
    filter = FilterType::New();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::run()
{
    // Load the image
    inputReader->SetFileName(this->inputPath->text().toStdString());
    inputReader->Update();

    // Create the filter
    filter->SetKernelSize(this->horizontalSlider->sliderPosition());
    filter->SetInput(inputReader->GetOutput());
    filter->Update();

    // Write image
    outputWriter->SetFileName(this->inputPath->text().toStdString());
    outputWriter->SetInput(filter->GetOutput());
    outputWriter->Update();
    close();
}
