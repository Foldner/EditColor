#include "editcolor.h"
#include "ui_editcolor.h"
#include "QGridLayout"
#include "QClipboard"

QString colorCode = "#000000";

EditColor::EditColor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditColor)
{
    ui->setupUi(this);

    sliderRed = new QSlider(Qt::Horizontal, nullptr);
    sliderRed->setMaximum(255);
    sliderRed->setMinimum(0);
    sliderRed->setStyleSheet("QSlider::handle:horizontal {background-color: #ed1b52}");
    QObject::connect(sliderRed,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    sliderGreen = new QSlider(Qt::Horizontal, nullptr);
    sliderGreen->setMaximum(255);
    sliderGreen->setMinimum(0);
    sliderGreen->setStyleSheet("QSlider::handle:horizontal {background-color: #00c100}");
    QObject::connect(sliderGreen,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    sliderBlue = new QSlider(Qt::Horizontal, nullptr);
    sliderBlue->setMaximum(255);
    sliderBlue->setMinimum(0);
    sliderBlue->setStyleSheet("QSlider::handle:horizontal {background-color: #0169ff}");
    QObject::connect(sliderBlue,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    textLabel = new QLabel("Hello World!");
    QString propertyStr = QString("font-size: 20pt; font-weight: bold");
    textLabel->setStyleSheet(propertyStr);
    textLabel->setAlignment(Qt::AlignHCenter);

    colorCodeLabel = new QLabel("Код цвета: #000000");
    propertyStr = QString("font-size: 12pt");
    colorCodeLabel->setStyleSheet(propertyStr);
    colorCodeLabel->setAlignment(Qt::AlignLeft);

    copyButton = new QPushButton();
    copyButton->setFixedSize(25,25);
    copyButton->setStyleSheet("qproperty-icon: url(:/icons/copy.png);");
    QObject::connect(copyButton,SIGNAL(released()),this, SLOT(ButtonClicked()));

    QGridLayout* sliderLayout = new QGridLayout;
    sliderLayout->setHorizontalSpacing(1);
    sliderLayout->addWidget(sliderRed, 1, 0, 1, 2);
    sliderLayout->addWidget(sliderGreen, 2, 0, 1, 2);
    sliderLayout->addWidget(sliderBlue, 3, 0, 1, 2);
    sliderLayout->addWidget(textLabel, 0, 0, 1, 2);
    sliderLayout->addWidget(colorCodeLabel, 4, 0);
    sliderLayout->addWidget(copyButton, 4, 1);

    QWidget* window = new QWidget();
    window->setLayout(sliderLayout);

    this->setCentralWidget(window);
}

void EditColor::SliderMoved()
{
    QString propertyStr = QString("color: rgb(%1,%2,%3); font-size: 20pt; font-weight: bold").arg(sliderRed->value()).arg(sliderGreen->value()).arg(sliderBlue->value());
    textLabel->setStyleSheet(propertyStr);

    QString colorCodeRed, colorCodeGreen, colorCodeBlue;
    colorCodeRed.setNum(sliderRed->value(), 16);
    if(colorCodeRed.length() == 1)
        colorCodeRed = "0" + colorCodeRed;
    colorCodeGreen.setNum(sliderGreen->value(), 16);
    if(colorCodeGreen.length() == 1)
        colorCodeGreen = "0" + colorCodeGreen;
    colorCodeBlue.setNum(sliderBlue->value(), 16);
    if(colorCodeBlue.length() == 1)
        colorCodeBlue = "0" + colorCodeBlue;
    colorCode = "#" + colorCodeRed + colorCodeGreen + colorCodeBlue;
    colorCodeLabel->setText("Код цвета: " + colorCode);
}

void EditColor::ButtonClicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(colorCode);
}

EditColor::~EditColor()
{
    delete ui;
}

