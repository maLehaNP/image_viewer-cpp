#include <buttonHandler.h>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

extern QDir dir;
extern QStringList imList;
extern QObject* window;

void ButtonHandler::handleClick(int sender) {
  std::cout << sender << '\n';

  switch (sender) {
    case FOLDER_BTN:
    {
      bool ok{};
      QString path = QInputDialog::getText(nullptr,
        tr("Выбор папки"), tr("Адрес папки:"),
        QLineEdit::Normal, QDir::currentPath(), &ok);
      std::cout << ok << ' ' << path.toStdString() << '\n';

      if (ok && !path.isEmpty())
        dir.setPath(path);
      imList = dir.entryList();

      QObject* image = window->findChild<QObject*>("image");
      image->setProperty("source", QUrl::fromLocalFile(dir.path() + '/' + imList[0]));
      break;
    }
    default:
      break;
  }

}

