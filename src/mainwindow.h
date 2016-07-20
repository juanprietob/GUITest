
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "MirabelFilter.h"

#include <QMainWindow>
#include <QSlider>


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    typedef itk::Image<unsigned char,2>  ImageType;
    typedef itk::MirabelFilter<ImageType>  FilterType;
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typedef itk::ImageFileWriter<ImageType> WriterType;

    explicit MainWindow(QWidget *parent=NULL);
    ~MainWindow();

private slots:
    void run();

private:
    
    ReaderType::Pointer inputReader;
    WriterType::Pointer outputWriter;
    FilterType::Pointer filter;
};



#endif // MAINWINDOW_HXX
