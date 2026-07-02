#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QPushButton>
#include <string>

//void doButton(QObject* sender);
void doButton();

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url("qrc:/path/main.qml"); // ссылка на файл qml
  engine.load(url);                     // загружаем файл qml

  // получаем корневой объект - окно приложения
  QObject *window = engine.rootObjects().first();

  // получаем в окне элементы кнопок
  QPushButton *folderBtn = window->findChild<QPushButton *>("folderBtn");
  QPushButton *prevBtn = window->findChild<QPushButton *>("prevBtn");
  QPushButton *nextBtn = window->findChild<QPushButton *>("nextBtn");
  QPushButton *firstBtn = window->findChild<QPushButton *>("firstBtn");
  QPushButton *lastBtn = window->findChild<QPushButton *>("lastBtn");
  QPushButton *slideShowBtn = window->findChild<QPushButton *>("slideShowBtn");
  QPushButton *turnBtn = window->findChild<QPushButton *>("turnBtn");
  QPushButton *delBtn = window->findChild<QPushButton *>("delBtn");

  //folderBtn->setProperty("text", QVariant("aboba"));
  QObject::connect(&folderBtn, "clicked", doButton);

  return app.exec();
}


void doButton() {
  //std::cout << sender->objectName().toStdString() << '\n';
  std::cout << "folderBtn" << '\n';
  //switch (sender->objectName()) {
  //  case "folderBtn"
  //  default:  
  //    break;
  //}
}
