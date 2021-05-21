#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Parameters;
class DataModel;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_pensionContribEmployee_valueChanged(double arg1);

        void on_contribLimit_valueChanged(int arg1);

    private:
        Ui::MainWindow *ui;
        Parameters* m_params;
        DataModel* m_model;
};
#endif // MAINWINDOW_HPP
