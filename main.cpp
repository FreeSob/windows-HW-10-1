#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *leaderTab = new QWidget;
    QLabel *leaderLabel = new QLabel("隊長\n組員1\n組員2\n組員3");
    leaderLabel->setStyleSheet("color: blue;");
    QVBoxLayout *leaderLayout = new QVBoxLayout;
    leaderLayout->addWidget(leaderLabel);
    leaderTab->setLayout(leaderLayout);

    QWidget *member1Tab = new QWidget;
    QLabel *member1Label = new QLabel("這是組員1頁面");
    QPushButton *colorButton = new QPushButton("color select");
    QVBoxLayout *member1Layout = new QVBoxLayout;
    member1Layout->addWidget(member1Label);
    member1Layout->addWidget(colorButton);
    member1Tab->setLayout(member1Layout);


    QObject::connect(colorButton, &QPushButton::clicked, [=]() {
        QColor color = QColorDialog::getColor(Qt::white, nullptr, "選擇文字顏色");
        if (color.isValid()) {
            QString colorName = color.name();
            leaderLabel->setStyleSheet(QString("color: %1;").arg(colorName));
        }
    });




    tabWidget->addTab(leaderTab, "隊長");
    tabWidget->addTab(member1Tab, "組員1");
    tabWidget->addTab(member2Tab, "組員2");
    tabWidget->addTab(member3Tab, "組員3");

    tabWidget->setWindowTitle("example");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
