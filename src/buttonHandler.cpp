#include <buttonHandler.h>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

extern QDir dir;
extern QStringList imList;
extern QObject* window;

void ButtonHandler::handleClick() {
  //std::cout << "aboba" << '\n';

  //QMessageBox msgBox;     // диалоговое окно
  //msgBox.setText("Button Clicked!"); // устанавливаем текст
  //msgBox.exec();  // отображаем диалоговое окно

  bool ok{};
  QString path = QInputDialog::getText(nullptr,
    tr("Выбор папки"), tr("Адрес папки:"),
    QLineEdit::Normal, QDir::currentPath(), &ok);
  
  std::cout << ok << ' ' << path.toStdString() << '\n';
  //printf("%d %s\n", ok, text.toStdString());
  
  if (ok && !path.isEmpty())
    dir.setPath(path);
  //std::cout << dir.path().toStdString() << '\n';

  imList = dir.entryList();
  //for (const auto &file : imList) {
  //  std::cout << file.toStdString() << '\n';
  //}

  QObject* image = window->findChild<QObject*>("image");
  image->setProperty("source", QUrl::fromLocalFile(dir.path() + '/' + imList[0]));
}

