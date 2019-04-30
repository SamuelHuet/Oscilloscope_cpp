#include "slider.h"

Slider::Slider(QWidget *parent)
{
    QLabel *label_zoomX = new QLabel;
    QLCDNumber *lcd_zoomX = new QLCDNumber;
    QSlider *slider_zoomX = new QSlider(Qt::Horizontal);
    slider_zoomX->setRange(1, 100);
    slider_zoomX->setValue(10);
    label_zoomX->setText("Zoom X");
    lcd_zoomX->display(10);

    QLabel *label_zoomY = new QLabel;
    QLCDNumber *lcd_zoomY = new QLCDNumber;
    QSlider *slider_zoomY = new QSlider(Qt::Horizontal);
    slider_zoomY->setRange(1, 100);
    slider_zoomY->setValue(10);
    label_zoomY->setText("Zoom Y");
    lcd_zoomY->display(10);

    QLabel *label_scrollY = new QLabel;
    QLCDNumber *lcd_scrollY = new QLCDNumber;
    QSlider *slider_scrollY = new QSlider(Qt::Horizontal);
    slider_scrollY->setRange(-3500, 0);
    slider_scrollY->setValue(0);
    label_scrollY->setText("Scrolling");
    lcd_scrollY->display(0);

    QLabel *label_trigger_enable = new QLabel;
    QCheckBox *check_trigger = new QCheckBox;
    label_trigger_enable->setText("Enable Trigger");

    QSlider *slider_trigger = new QSlider(Qt::Vertical);
    QLabel *label_trigger = new QLabel;
    QLCDNumber *lcd_trigger = new QLCDNumber;
    slider_trigger->setRange(-500, 500);
    slider_trigger->setValue(0);
    slider_trigger->setDisabled(true);
    label_trigger->setText("Trigger");
    lcd_trigger->display(0);


    QPushButton *Button_quit = new QPushButton("Quit");

    QGridLayout *qgl_instance = new QGridLayout;
    qgl_instance->addWidget(label_zoomX, 0, 0, 1, 1);
    qgl_instance->addWidget(lcd_zoomX, 0, 1, 1, 1);
    qgl_instance->addWidget(slider_zoomX, 1, 0, 1, 2);

    qgl_instance->addWidget(label_zoomY, 3, 0, 1, 1);
    qgl_instance->addWidget(lcd_zoomY, 3, 1, 1, 1);
    qgl_instance->addWidget(slider_zoomY, 4, 0, 1, 2);

    qgl_instance->addWidget(label_scrollY, 5, 0, 1, 1);
    qgl_instance->addWidget(lcd_scrollY, 5, 1, 1, 1);
    qgl_instance->addWidget(slider_scrollY, 6, 0, 1, 2);

    qgl_instance->addWidget(label_trigger_enable, 7, 0, 1, 2);
    qgl_instance->addWidget(check_trigger, 7, 2, 1, 1);

    qgl_instance->addWidget(slider_trigger, 8, 2, 5, 1);
    qgl_instance->addWidget(label_trigger, 10, 0, 1, 1);
    qgl_instance->addWidget(lcd_trigger, 10, 1, 1, 1);

    qgl_instance->addWidget(Button_quit, 20, 0, 1, 2);

    setLayout(qgl_instance);

    connect(slider_zoomX, SIGNAL(valueChanged(int)),lcd_zoomX, SLOT(display(int)));
    connect(slider_zoomX, SIGNAL(valueChanged(int)), this, SIGNAL(ZoomXChanged(int)));

    connect(slider_zoomY, SIGNAL(valueChanged(int)),lcd_zoomY, SLOT(display(int)));
    connect(slider_zoomY, SIGNAL(valueChanged(int)), this, SIGNAL(ZoomYChanged(int)));

    connect(slider_scrollY, SIGNAL(valueChanged(int)),lcd_scrollY, SLOT(display(int)));
    connect(slider_scrollY, SIGNAL(valueChanged(int)), this, SIGNAL(ScrollXChanged(int)));

    connect(check_trigger, SIGNAL(clicked(bool)), slider_scrollY, SLOT(setDisabled(bool)));
    connect(check_trigger, SIGNAL(clicked(bool)), slider_trigger, SLOT(setEnabled(bool)));
    connect(check_trigger, SIGNAL(clicked(bool)), this, SIGNAL(CheckBox_trigger(bool)));
    connect(slider_trigger, SIGNAL(valueChanged(int)), lcd_trigger, SLOT(display(int)));
    connect(slider_trigger, SIGNAL(valueChanged(int)), this, SIGNAL(TriggerChanged(int)));

    connect(Button_quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

}

Slider::~Slider()
{

}


