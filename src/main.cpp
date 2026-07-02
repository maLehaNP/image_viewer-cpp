#include <iostream>
#include <string>
#include <QApplication>
#include <QQmlApplicationEngine>

#include <backend.h>


QObject* window;


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  // регистрация типа backend
  qmlRegisterType<Backend>("backend", 1, 0, "Backend");

  const QUrl url("qrc:/path/src/main.qml");  // ссылка на файл qml
  engine.load(url);                          // загружаем файл qml

  // получаем корневой объект - окно приложения
  window = engine.rootObjects().first();

  return app.exec();
}

