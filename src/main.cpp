#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDir>

#include <buttonHandler.h>


QObject* window;
QDir dir;
QStringList imList;
int listIdx;
int listLen;


int main(int argc, char *argv[]) {
  //QGuiApplication app(argc, argv);
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  // регистрация типа buttonHandler
  qmlRegisterType<ButtonHandler>("buttonHandler", 1, 0, "ButtonHandler");

  const QUrl url("qrc:/path/src/main.qml");  // ссылка на файл qml
  engine.load(url);                          // загружаем файл qml

  QStringList filters;
  filters << "*.jpg";
  dir.setNameFilters(filters);

  // получаем корневой объект - окно приложения
  window = engine.rootObjects().first();
  // получаем в окне элементы кнопок
  //QObject *folderBtn = window->findChild<QObject *>("folderBtn");
  //QObject *prevBtn = window->findChild<QObject *>("prevBtn");
  //QObject *nextBtn = window->findChild<QObject *>("nextBtn");
  //QObject *firstBtn = window->findChild<QObject *>("firstBtn");
  //QObject *lastBtn = window->findChild<QObject *>("lastBtn");
  //QObject *slideShowBtn = window->findChild<QObject *>("slideShowBtn");
  //QObject *turnBtn = window->findChild<QObject *>("turnBtn");
  //QObject *delBtn = window->findChild<QObject *>("delBtn");

  return app.exec();
}

