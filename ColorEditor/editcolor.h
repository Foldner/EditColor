#ifndef EDITCOLOR_H
#define EDITCOLOR_H

#include <QMainWindow>
#include "QLabel"
#include "QSlider"
#include "QPushButton"


QT_BEGIN_NAMESPACE
namespace Ui { class EditColor; }
QT_END_NAMESPACE

class EditColor : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditColor(QWidget *parent = nullptr);
    ~EditColor();

public slots:
//void ChangeText();
void SliderMoved();
void ButtonClicked();

private:
    Ui::EditColor *ui;
    QPushButton* copyButton;
    QLabel* colorCodeLabel;
    QLabel* textLabel;
    QSlider* sliderRed;
    QSlider* sliderGreen;
    QSlider* sliderBlue;
};
#endif // EDITCOLOR_H
