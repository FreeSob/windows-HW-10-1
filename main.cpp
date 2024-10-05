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





    QWidget *member3Tab = new QWidget;
    QLabel *member3Label = new QLabel("這是組員3頁面");
    QPushButton *fileButton = new QPushButton("File select");
    QVBoxLayout *member3Layout = new QVBoxLayout;
    member3Layout->addWidget(member3Label);
    member3Layout->addWidget(fileButton);
    member3Tab->setLayout(member3Layout);


    QObject::connect(fileButton, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "選擇檔案", "", "所有檔案 (*.*)");
        if (!filePath.isEmpty()) {
            leaderLabel->setText(filePath);
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
