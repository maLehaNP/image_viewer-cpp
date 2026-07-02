#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QPushButton>
#include <string>

#include <buttonHandler.h>

//void doButton(QObject* sender);
//void doButton();

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  const QUrl url("qrc:/path/src/main.qml"); // ссылка на файл qml
  engine.load(url);                     // загружаем файл qml

  // получаем корневой объект - окно приложения
  QObject *window = engine.rootObjects().first();
  
  // регистрация типа buttonHandler
  //qmlRegisterType<ButtonHandler>("buttonHandler", 1, 0, "ButtonHandler");
  
  // получаем в окне элементы кнопок
  QObject *folderBtn = window->findChild<QObject *>("folderBtn");
  QObject *prevBtn = window->findChild<QObject *>("prevBtn");
  QObject *nextBtn = window->findChild<QObject *>("nextBtn");
  QObject *firstBtn = window->findChild<QObject *>("firstBtn");
  QObject *lastBtn = window->findChild<QObject *>("lastBtn");
  QObject *slideShowBtn = window->findChild<QObject *>("slideShowBtn");
  QObject *turnBtn = window->findChild<QObject *>("turnBtn");
  QObject *delBtn = window->findChild<QObject *>("delBtn");

  //folderBtn->setProperty("text", QVariant("aboba"));
  //QObject::connect(&folderBtn, "clicked", doButton);

  return app.exec();
}


//void doButton() {
  //std::cout << sender->objectName().toStdString() << '\n';
  //std::cout << "folderBtn" << '\n';
  //switch (sender->objectName()) {
  //  case "folderBtn"
  //  default:  
  //    break;
  //}
//}
