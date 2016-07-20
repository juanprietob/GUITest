#pragma once
#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "MirabelFilter.hxx"
#include "ui_mainwindow.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include <QMainWindow>
#include <QSlider>


namespace Ui{
class MainWindow;
}
class MirabelFilter;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    typedef itk::Image<unsigned char,2>  ImageType;
    typedef itk::MirabelFilter<ImageType>  FilterType;
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typedef itk::ImageFileWriter<ImageType> WriterType;

    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();

private slots:
    void run();

private:
    Ui::MainWindow *ui;
    ReaderType::Pointer inputReader;
    WriterType::Pointer outputWriter;
    FilterType::Pointer filter;
};

#endif // MAINWINDOW_HXX
